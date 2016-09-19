#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
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

	boost::property_tree::ptree &dllarguments = pt.get_child("dllarguments");

	std::string dllfunction = pt.get<std::string>("dllfunction");

	if (dllfunction.compare("dbcall") == 0) {
		std::string dbfunction = dllarguments.get<std::string>("dbfunction");

		if (dbfunction.compare("uuid") == 0) {
			returnstring = orderedUUID();
		} else {
			throw std::runtime_error("Don't know dbfunction: " + dbfunction);
		}
	} else {
		throw std::runtime_error("Don't know dllfunction: " + dllfunction);
	}
	return returnstring;
}

