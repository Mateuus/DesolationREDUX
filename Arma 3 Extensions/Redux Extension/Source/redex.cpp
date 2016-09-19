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
	return;
}
redex::~redex() {
	return;
}

std::string redex::processCallExtension(const char *function) {
	std::string returnstring;
	std::stringstream functionstream;
	functionstream << function;

	boost::property_tree::ptree pt;
	boost::property_tree::read_json(functionstream, pt);

	std::string dllfunction = pt.get<std::string>("dllfunction");
	boost::property_tree::ptree &dllarguments = pt.get_child("dllarguments");

	if (dllfunction.compare("dbcall") == 0) {
		returnstring = dbconnection.processDBCall(dllarguments);
	} else {
		throw std::runtime_error("Don't know dllfunction: " + dllfunction);
	}
	return returnstring;
}

