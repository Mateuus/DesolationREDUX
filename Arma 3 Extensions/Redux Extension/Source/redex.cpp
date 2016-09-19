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
						boost::bind(&redex::dbcall, this, _1)));
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

	// safe some characters for the protocol overhead
	outputSize = outputSize - MAXCHARS_FOR_PROTOCOL_OVERHEAD;

	DLL_FUNCTIONS::iterator it = dllfunctions.find(dllfunction);
	if (it != dllfunctions.end()) {
		const DLL_FUNCTION &func(it->second);
		returnString = func(dllarguments);
	} else {
		throw std::runtime_error("Don't know dllfunction: " + dllfunction);
	}

	if (returnString.length() > outputSize) {
		returnString = multipartMSGGenerator(returnString);
	}

	return returnString;
}

std::string redex::multipartMSGGenerator(std::string returnString) {
	int n = 0;
	while ( (n=returnString.find("\"",n)) != std::string::npos )
	{
		returnString.insert(n,"\\");
		n+=2;
	}

	return "[\"" + PROTOCOL_MULTIPART_MSG_STRING + "\", 0, \"" + returnString + "\"]";
}

std::string redex::dbcall(boost::property_tree::ptree &dllarguments) {
	return dbconnection.processDBCall(dllarguments);
}

