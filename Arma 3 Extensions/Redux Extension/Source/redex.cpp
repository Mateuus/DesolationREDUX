#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <cassert>
#include <exception>
#include <stdexcept>

#include "redex.hpp"
#include "utils/uuid.hpp"

redex::redex() {
	dllfunctions.insert(
			std::make_pair(std::string(PROTOCOL_LIBARY_FUNCTION_EXECUTE_INIT_DB),
					boost::bind(&redex::initdb, this, _1)));
	dllfunctions.insert(
			std::make_pair(std::string(PROTOCOL_LIBARY_FUNCTION_EXECUTE_DB_CALL),
					boost::bind(&redex::dbcall, this, _1)));
	dllfunctions.insert(
				std::make_pair(std::string(PROTOCOL_LIBARY_FUNCTION_RECEIVE_MESSAGE),
						boost::bind(&redex::rcvmsg, this, _1)));
	dllfunctions.insert(
					std::make_pair(std::string(PROTOCOL_LIBARY_FUNCTION_CHECK_MESSAGE_STATE),
							boost::bind(&redex::chkmsg, this, _1)));
	return;
}
redex::~redex() {
	return;
}

std::string redex::processCallExtension(const char *function, int outputSize) {
	std::string returnString;
	std::stringstream functionstream;
	functionstream << function;

	// NEEDED to make sure there is room for the last '\0'
	outputSize -= 1;

	boost::property_tree::ptree pt;
	boost::property_tree::read_json(functionstream, pt);

	std::string dllfunction = pt.get<std::string>("dllfunction");
	boost::property_tree::ptree &dllarguments = pt.get_child("dllarguments");

	DLL_FUNCTIONS::iterator it = dllfunctions.find(dllfunction);
	if (it != dllfunctions.end()) {
		const DLL_FUNCTION &func(it->second);

		try {
			returnString = func(dllarguments);
		} catch (std::exception const& e) {
			returnString = "[\"" + PROTOCOL_MESSAGE_TYPE_ERROR+ "\", \"";
			returnString += e.what();
			returnString += "\"]";
		}

	} else {
		throw std::runtime_error("Don't know dllfunction: " + dllfunction);
	}

	if (returnString.length() > outputSize) {
		returnString = multipartMSGGenerator(returnString, outputSize);
	}

	return returnString;
}

std::string redex::multipartMSGGenerator(std::string returnString, int outputSize) {
	PROTOCOL_IDENTIFIER_DATATYPE messageIdentifier = PROTOCOL_IDENTIFIER_GENERATOR;
	std::string firststring;
	std::queue<std::string> stringqueue;
	int firststringlength;
	int i = 0;

	// safe some characters for the protocol overhead
	// int firstoutputSize = outputSize - MAXCHARS_FOR_PROTOCOL_OVERHEAD;
	int firstoutputSize = outputSize - STATIC_MULTIPART_MESSAGE_PROTOCOL_OVERHEAD;

	// BEGIN TODO
	// find better way to find the perfect length for first string because escaping
	// the double quotes causes a problem if there are many double quotes
	firststring = returnString.substr(0, firstoutputSize);
	firststringlength = firststring.length();
	i = 0;
	while ((i = firststring.find("\"", i)) != std::string::npos) {
		firststring.insert(i, "\"");
		i += 2;
	}
	// END TODO

	firstoutputSize = firstoutputSize - firststring.length() + firststringlength;
	firststring = returnString.substr(0, firstoutputSize);
	i = 0;
	// add second " to get the string after call compile to concatinate with the remaining parts
	while ((i = firststring.find("\"", i)) != std::string::npos) {
		firststring.insert(i, "\"");
		i += 2;
	}

	// split the remaining string at outputSize
	for (i = firstoutputSize; i < returnString.length(); i += outputSize) {
		stringqueue.push(returnString.substr(i, outputSize));
	}

	msgmutex.lock();
	msgmap.insert(std::make_pair(messageIdentifier, stringqueue));
	msgmutex.unlock();

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MULTIPART + "\", \"" + messageIdentifier + "\", \"" + firststring + "\"]";
}


std::string redex::initdb(boost::property_tree::ptree &dbcall) {
	int poolsize = dbcall.get<int>("poolsize");
	std::string worlduuid = dbcall.get<std::string>("worlduuid");

	//poolsize =
	dbconnection.spawnHandler(poolsize, worlduuid);

	return "[\"" + PROTOCOL_MESSAGE_TYPE_MESSAGE + "\", [\"" + std::to_string(poolsize) + "\", \"Threads spawned\"]]";
}

std::string redex::rcvmsg(boost::property_tree::ptree &dllarguments) {
	PROTOCOL_IDENTIFIER_DATATYPE messageIdentifier = dllarguments.get<PROTOCOL_IDENTIFIER_DATATYPE>(PROTOCOL_IDENTIFIER_NAME);
	std::queue<std::string> *stringqueue;
	std::string returnString;

	msgmutex.lock();
	MESSAGE_MAP::iterator it = msgmap.find(messageIdentifier);
	msgmutex.unlock();

	// check if message object was found
	if (it == msgmap.end()) {
		throw std::runtime_error("Message " + messageIdentifier + " does not exist");
	}

	// extract message object
	stringqueue = &it->second;

	if (stringqueue->empty()) {
		// delete message object
		msgmutex.lock();
		msgmap.erase (it);
		msgmutex.unlock();
		// signal arma that it got the last message
		returnString = PROTOCOL_MESSAGE_TRANSMIT_FINISHED_MSG;
	} else {
		// get next message and remove it from queue
		returnString = stringqueue->front();
		stringqueue->pop();
	}

	return returnString;
}

std::string redex::chkmsg(boost::property_tree::ptree &dllarguments) {
	PROTOCOL_IDENTIFIER_DATATYPE messageIdentifier = dllarguments.get<PROTOCOL_IDENTIFIER_DATATYPE>("messageIdentifier");
	std::queue<PROTOCOL_IDENTIFIER_DATATYPE> *stringqueue;
	std::string returnString;

	msgmutex.lock();
	MESSAGE_MAP::iterator it = msgmap.find(messageIdentifier);
	msgmutex.unlock();

	// check if message object was found
	if (it == msgmap.end()) {
		returnString = PROTOCOL_MESSAGE_NOT_EXISTING;
	} else {
		returnString = PROTOCOL_MESSAGE_EXISTING;

		/*
		 * dunno if we want more information
		stringqueue = &it->second;
		if (stringqueue->empty()) {
			returnString = PROTOCOL_MESSAGE_EMPTY;
		} else {
			returnString = PROTOCOL_MESSAGE_EXISTING;
		}
		*/
	}

	return returnString;
}

std::string redex::dbcall(boost::property_tree::ptree &dllarguments) {
	return dbconnection.processDBCall(dllarguments);
}

