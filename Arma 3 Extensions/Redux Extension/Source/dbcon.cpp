#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <stdexcept>

#include "dbcon.hpp"
#include "uuid.hpp"

dbcon::dbcon() {
	dbfunctions.insert(
			std::make_pair(std::string("getUUID"),
					boost::bind(&dbcon::getUUID, this, _1)));
	dbfunctions.insert(
				std::make_pair(std::string("echo"),
						boost::bind(&dbcon::echo, this, _1)));
	return;
}
dbcon::~dbcon() {
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
	return "[\"" + PROTOCOL_MSG_STRING + "\", \"" + orderedUUID() + "\"]";
}

std::string dbcon::echo(boost::property_tree::ptree &dbarguments) {
	std::string echostring = dbarguments.get<std::string>("echostring");
	return "[\"" + PROTOCOL_MSG_STRING + "\", \"" + echostring + "\"]";
}
