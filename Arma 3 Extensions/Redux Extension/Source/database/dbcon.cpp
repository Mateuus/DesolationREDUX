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
					std::make_tuple(boost::bind(&dbcon::getUUID, this, _1, _2), HANDLELESS_MAGIC)));
	dbfunctions.insert(
				std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_ECHO_STRING),
						std::make_tuple(boost::bind(&dbcon::echo, this, _1, _2), HANDLELESS_MAGIC)));
	dbfunctions.insert(
				std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_DB_VERSION),
						std::make_tuple(boost::bind(&dbcon::dbVersion, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
				std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_DEBUG_CALL),
						std::make_tuple(boost::bind(&dbcon::debugCall, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
					std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_DUMP_OBJECTS),
							std::make_tuple(boost::bind(&dbcon::dumpObjects, this, _1, _2), SYNC_MAGIC)));
	dbfunctions.insert(
					std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_LOAD_PLAYER),
							std::make_tuple(boost::bind(&dbcon::loadPlayer, this, _1, _2), SYNC_MAGIC)));

	boost::asio::io_service::work work(DBioService);

	return;
}

dbcon::~dbcon() {
	asyncthreadpool.join_all();
	return;
}

int dbcon::spawnHandler(unsigned int poolsize, std::string worlduuid) {
	if (poolsize < 1) {
		poolsize = 1;
	}

	if (!poolinitialized) {
		int i;
		std::string hostname = "192.168.1.11";
		std::string user = "root";
		std::string password = "rootuserpwd";
		std::string database = "desolationredux";
		unsigned int port = 0;
		db_handler *syncdbhandler;

		if (!syncdbhandlerpool.is_lock_free()) {
			throw std::runtime_error("syncdbhandlerpool is not lock free");
		}

		syncdbhandlerpool.reserve(poolsize + 1);
		for (i = 0; i < poolsize; i++) {
			syncdbhandler = new (db_handler);
			syncdbhandler->connect(hostname, user, password, database, port, worlduuid);
			syncdbhandlerpool.bounded_push((intptr_t) syncdbhandler);
		}

		// tempsyncdbhandler.connect(hostname, user, password, database, port, worlduuid);

		/* commented until async is needed
		DBioService.set_dbinfos(hostname, user, password, database, port, worlduuid);
		for (i = 0; i < poolsize; i++) {
			asyncthreadpool.create_thread(
					boost::bind(&dbcon_io_service::run, &DBioService)
			);
		}
		*/
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
		DB_FUNCTION_INFO funcinfo = it->second;

		switch (std::get<1>(funcinfo))
		{
		case SYNC_MAGIC:
			returnString = syncCall(funcinfo, dbarguments);
			break;

		case ASYNC_MAGIC:
			returnString = asyncCall(funcinfo, dbarguments);
			break;

		case HANDLELESS_MAGIC:
			returnString = handlelessCall(funcinfo, dbarguments);
			break;

		default:
			throw std::runtime_error("unknown function class");
		}
	} else {
		throw std::runtime_error("Don't know dbfunction: " + dbfunction);
	}

	return returnString;
}

std::string dbcon::syncCall(DB_FUNCTION_INFO funcinfo, boost::property_tree::ptree &dbarguments) {
	const DB_FUNCTION &func(std::get<0>(funcinfo));
	std::string returnString;

	intptr_t syncdbhandlerpointer;
	db_handler *syncdbhandler;

	std::string version;

	if (poolinitialized) {

		// try to get an db handler
		while (!syncdbhandlerpool.pop(syncdbhandlerpointer)) {
			printf("i am in a loop! :( \n");
		}
		try {
			//	syncdbhandler = &tempsyncdbhandler;
			syncdbhandler = (db_handler*) syncdbhandlerpointer;

			returnString = func(dbarguments, syncdbhandler);

			// return handler to the pool
			syncdbhandlerpool.bounded_push(syncdbhandlerpointer);
		} catch (std::exception const& e) {
			// allways return the handler
			syncdbhandlerpool.bounded_push(syncdbhandlerpointer);
			throw std::runtime_error(e.what());
		}
	} else {
		throw std::runtime_error("db handler pool not initialized");
	}

	return returnString;
}

std::string dbcon::asyncCall(DB_FUNCTION_INFO funcinfo, boost::property_tree::ptree &dbarguments) {
	return this->syncCall(funcinfo, dbarguments);
}

std::string dbcon::handlelessCall(DB_FUNCTION_INFO funcinfo, boost::property_tree::ptree &dbarguments) {
	const DB_FUNCTION &func(std::get<0>(funcinfo));
	return func(dbarguments, NULL);
}

std::string dbcon::getUUID(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + orderedUUID() + "\"]";
}

std::string dbcon::echo(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string echostring = dbarguments.get<std::string>("echostring");
	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + echostring + "\"]";
}

std::string dbcon::debugCall(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string matrix;
	bool placecommaone = false;
	bool placecommatwo = false;

	//std::vector< std::vector<std::string> > resultmatrix = dbhandler->verbosetest("SELECT hex(uuid), classname, priority, timelastused, timecreated, visible, accesscode, locked, hex(player_uuid), hitpoints, damage, fuel, fuelcargo, repaircargo, items, magazines, weapons, backpacks, magazinesturret, variables, animationstate, textures, direction, positiontype, positionx, positiony, positionz FROM `object` WHERE player_uuid = CAST(0x11E66B045F432626B28510BF48883ACE AS BINARY) OR player_uuid = CAST(0x11E66ABC1942138D82C510BF48883ACE AS BINARY)");
	std::vector< std::vector<std::string> > resultmatrix = dbhandler->verbosetest("SELECT hex(uuid), classname, priority, UNIX_TIMESTAMP(timelastused), UNIX_TIMESTAMP(timecreated), visible, accesscode, locked, hex(player_uuid), hitpoints, damage, fuel, fuelcargo, repaircargo, items, magazines, weapons, backpacks, magazinesturret, variables, animationstate, textures, direction, positiontype, positionx, positiony, positionz FROM `object`");
	matrix = "[";
	for (auto& row : resultmatrix) {
		matrix += "[";
		if (placecommaone) {
			matrix += ",";
		}
		placecommatwo = false;
		for (auto& value : row) {
			if (placecommatwo) {
				matrix += ", ";
			}
			//matrix += "\"" + value + "\"";
			matrix += value;
			placecommatwo = true;
		}
		matrix += "]";
		placecommaone = true;
	}
	matrix += "]";

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", " + matrix + "]";
}


std::string dbcon::dbVersion(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string version;

	version = dbhandler->querydbversion();

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", \"" + version + "\"]";
}

std::string dbcon::dumpObjects(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string matrix;
	bool placecommaone = false;
	bool placecommatwo = false;

	//std::vector< std::vector<std::string> > resultmatrix = dbhandler->verbosetest("SELECT hex(uuid), classname, priority, timelastused, timecreated, visible, accesscode, locked, hex(player_uuid), hitpoints, damage, fuel, fuelcargo, repaircargo, items, magazines, weapons, backpacks, magazinesturret, variables, animationstate, textures, direction, positiontype, positionx, positiony, positionz FROM `object` WHERE player_uuid = CAST(0x11E66B045F432626B28510BF48883ACE AS BINARY) OR player_uuid = CAST(0x11E66ABC1942138D82C510BF48883ACE AS BINARY)");
	std::vector< std::vector<std::string> > resultmatrix = dbhandler->dumpObjects();
	matrix = "[";
	for (auto& row : resultmatrix) {
		if (placecommaone) {
			matrix += ",";
		}
		matrix += "[";
		placecommatwo = false;
		for (auto& value : row) {
			if (placecommatwo) {
				matrix += ", ";
			}
			//matrix += "\"" + value + "\"";
			matrix += value;
			placecommatwo = true;
		}
		matrix += "]";
		placecommaone = true;
	}
	matrix += "]";

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", " + matrix + "]";
}

std::string dbcon::loadPlayer(boost::property_tree::ptree &dbarguments, db_handler *dbhandler) {
	std::string nickname = dbarguments.get<std::string>("nickname");
	std::string steamid = dbarguments.get<std::string>("steamid");
	std::string playerinfo = dbhandler->loadPlayer(nickname, steamid);

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", " + playerinfo + "]";
}
