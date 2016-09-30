#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <stdexcept>

#include "database/dbcon.hpp"
#include "utils/uuid.hpp"

dbcon::dbcon() {
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_UUID),
					boost::bind(&dbcon::getUUID, this, _1)));
	dbfunctions.insert(
				std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_ECHO_STRING),
						boost::bind(&dbcon::echo, this, _1)));
	dbfunctions.insert(
				std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_DB_VERSION),
						boost::bind(&dbcon::dbVersion, this, _1)));

	boost::asio::io_service::work work(DBioService);

	return;
}

dbcon::~dbcon() {
	asyncthreadpool.join_all();
	return;
}

int dbcon::spawnThreads(unsigned int poolsize) {
	if (poolsize < 1) {
		poolsize = 1;
	}

	if (!poolinitialized) {
		int i;
		std::string hostname = "192.168.1.11";
		std::string user = "root";
		std::string password = "root";
		std::string database = "desolationredux";
		db_handler *syncdbhandler;

		if (!syncdbhandlerpool.is_lock_free()) {
			throw std::runtime_error("syncdbhandlerpool is not lock free");
		}

		syncdbhandlerpool.reserve(poolsize + 1);
		for (i = 0; i < poolsize; i++) {
			syncdbhandler = new (db_handler);
			syncdbhandler->connect(hostname, user, password, database);
			syncdbhandlerpool.bounded_push((intptr_t) syncdbhandler);
		}

		tempsyncdbhandler.connect(hostname, user, password, database);

		DBioService.set_dbinfos(hostname, user, password, database);
		for (i = 0; i < poolsize; i++) {
			asyncthreadpool.create_thread(
					boost::bind(&dbcon_io_service::run, &DBioService)
			);
		}
		poolinitialized = true;
	} else {
		throw std::runtime_error("Threads already spawned");
	}

	return asyncthreadpool.size();
}

std::string dbcon::processDBCall(boost::property_tree::ptree &dbcall) {
	std::string returnString;

	std::string dbfunction = dbcall.get<std::string>("dbfunction");
	boost::property_tree::ptree &dbarguments = dbcall.get_child("dbarguments");

	DB_FUNCTIONS::iterator it = dbfunctions.find(dbfunction);
	if (it != dbfunctions.end()) {
		const DB_FUNCTION &func(it->second);
		returnString = func(dbarguments);
	} else {
		throw std::runtime_error("Don't know dbfunction: " + dbfunction);
	}

	return returnString;
}

std::string dbcon::getUUID(boost::property_tree::ptree &dbarguments) {
	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + orderedUUID() + "\"]";
}

std::string dbcon::echo(boost::property_tree::ptree &dbarguments) {
	std::string echostring = dbarguments.get<std::string>("echostring");
	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + echostring + "\"]";
}


std::string dbcon::dbVersion(boost::property_tree::ptree &dbarguments) {
	intptr_t syncdbhandlerpointer;
	db_handler *syncdbhandler;

	//int fieldcount = 0;
	std::string version;

	if (poolinitialized) {

	// try to get an db handler
	while (!syncdbhandlerpool.pop(syncdbhandlerpointer)) {
		printf("i am in a loop! :( \n");
	}

	//	syncdbhandler = &tempsyncdbhandler;
	syncdbhandler = (db_handler*) syncdbhandlerpointer;

	version = syncdbhandler->querydbversion();

	// return handler to the pool
	syncdbhandlerpool.bounded_push(syncdbhandlerpointer);
	} else {
		throw std::runtime_error("db handler pool not initialized");
	}

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + version + "\"]";
}

/*
std::string dbcon::dbVersion(boost::property_tree::ptree &dbarguments) {
	intptr_t syncdbhandlerpointer;
	db_handler *syncdbhandler;
	MYSQL_RES *result;
	MYSQL_ROW row = 0;
	//int fieldcount = 0;
	std::string version;

	// try to get an db handler
	while (!syncdbhandlerpool.pop(syncdbhandlerpointer)) {
		printf("i am in a loop! :( \n");
	}

	//	syncdbhandler = &tempsyncdbhandler;
	syncdbhandler = (db_handler*) syncdbhandlerpointer;

	syncdbhandler->rawquery("SELECT VERSION()", &result);

	// return handler to the pool
	syncdbhandlerpool.bounded_push(syncdbhandlerpointer);

	row = mysql_fetch_row(result);
	//fieldcount = mysql_num_fields(*result);
	version = row[0];

	mysql_free_result(result);

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + version + "\"]";
}
*/
