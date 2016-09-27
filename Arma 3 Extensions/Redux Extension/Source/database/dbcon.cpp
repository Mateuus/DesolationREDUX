#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <stdexcept>

#include "database/dbcon.hpp"
#include "utils/uuid.hpp"

dbcon::dbcon(unsigned int threadcount) {
	dbfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_UUID),
					boost::bind(&dbcon::getUUID, this, _1)));
	dbfunctions.insert(
				std::make_pair(std::string(PROTOCOL_DBCALL_FUNCTION_RETURN_ECHO_STRING),
						boost::bind(&dbcon::echo, this, _1)));

//	boost::asio::io_service::work work(DBioService);

//	threadpool.create_thread(
//	    boost::bind(&boost::asio::io_service::run, &DBioService)
//	);

	return;
}

dbcon::~dbcon() {
	threadpool.join_all();
	return;
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
