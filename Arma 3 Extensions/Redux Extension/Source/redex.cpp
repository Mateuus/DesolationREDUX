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
#include "uuid.hpp"

redex::redex() {
	dllfunctions.insert(
			std::make_pair(std::string("dbcall"),
					boost::bind(&redex::dbcall, this, _1)));
	dllfunctions.insert(
				std::make_pair(std::string("rcvmsg"),
						boost::bind(&redex::rcvmsg, this, _1)));
	return;
}
redex::~redex() {
	return;
}

std::string redex::processCallExtension(const char *function, int outputSize) {
	std::string returnString;
	std::stringstream functionstream;
	functionstream << function;

	boost::property_tree::ptree pt;
	boost::property_tree::read_json(functionstream, pt);

	std::string dllfunction = pt.get<std::string>("dllfunction");
	boost::property_tree::ptree &dllarguments = pt.get_child("dllarguments");

	DLL_FUNCTIONS::iterator it = dllfunctions.find(dllfunction);
	if (it != dllfunctions.end()) {
		const DLL_FUNCTION &func(it->second);
		returnString = func(dllarguments);
	} else {
		throw std::runtime_error("Don't know dllfunction: " + dllfunction);
	}

	if (returnString.length() > outputSize) {
		returnString = multipartMSGGenerator(returnString, outputSize);
	}

	return returnString;
}

std::string redex::multipartMSGGenerator(std::string returnString, int outputSize) {
	std::string msguuid = orderedUUID();
	std::queue<std::string> stringqueue;
	int stringlength;
	int i = 0;

	// safe some characters for the protocol overhead
	outputSize = outputSize - MAXCHARS_FOR_PROTOCOL_OVERHEAD;

	while ( (i=returnString.find("\"",i)) != std::string::npos )
	{
		returnString.insert(i,"\"");
		i+=2;
	}

	stringlength = returnString.length();

	for (i = 0; i < returnString.length(); i += outputSize) {
		stringqueue.push(returnString.substr(i, outputSize));
	}

	returnString = stringqueue.front();
	stringqueue.pop();

	msgmutex.lock();
	msgmap.insert(std::make_pair(msguuid, stringqueue));
	msgmutex.unlock();

	return "[\"" + PROTOCOL_MULTIPART_MSG_STRING + "\", " + std::to_string(stringqueue.size()) + ", \"" + msguuid + "\", \"" + returnString + "\"]";
}

std::string redex::rcvmsg(boost::property_tree::ptree &dllarguments) {
	std::string msguuid = dllarguments.get<std::string>("msguuid");
	std::queue<std::string> *stringqueue;
	std::string returnString;

	msgmutex.lock();
	MESSAGE_MAP::iterator it = msgmap.find(msguuid);
	msgmutex.unlock();

	if (it == msgmap.end()) {
		throw std::runtime_error("Message " + msguuid + " does not exist");
	}

	stringqueue = &it->second;
	returnString = stringqueue->front();
	stringqueue->pop();

	if (stringqueue->empty()) {
		msgmutex.lock();
		msgmap.erase (it);
		msgmutex.unlock();
	}

	return "[\"" + PROTOCOL_MULTIPART_MSG_STRING + "\", " + std::to_string(stringqueue->size()) + ", \"" + msguuid + "\", \"" + returnString + "\"]";
}

std::string redex::dbcall(boost::property_tree::ptree &dllarguments) {
	return dbconnection.processDBCall(dllarguments);
}

