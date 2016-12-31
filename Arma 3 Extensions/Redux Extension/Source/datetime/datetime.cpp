/* datetime.cpp
 *
 * Copyright 2016-2017 Desolation Redux
 *
 * Author: Legodev <legodevgit@mailbox.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <unistd.h>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <ctime>

#include "datetime/datetime.hpp"

datetime::datetime() {
	dtfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DTCALL_FUNCTION_GET_DATE_TIME_Array),
					boost::bind(&datetime::getDateTimeArray, this, _1)));
	dtfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DTCALL_FUNCTION_GET_EPOCH_TIME),
					boost::bind(&datetime::getEpochTime, this, _1)));
	dtfunctions.insert(
			std::make_pair(std::string(PROTOCOL_DTCALL_FUNCTION_GET_UNIX_TIME),
					boost::bind(&datetime::getEpochTime, this, _1)));
	return;
}

datetime::~datetime() {
	return;
}

std::string datetime::processDTCall(boost::property_tree::ptree &dtcall) {
	std::string returnString;

	std::string dtfunction = dtcall.get<std::string>("dtfunction");
	boost::property_tree::ptree &dtarguments = dtcall.get_child("dtarguments");

	DT_FUNCTIONS::iterator it = dtfunctions.find(dtfunction);
	if (it != dtfunctions.end()) {
		const DT_FUNCTION &func(it->second);

		try {
			returnString = func(dtarguments);
		} catch (std::exception const& e) {
			std::string error = e.what();
			int i = 0;
			while ((i = error.find("\"", i)) != std::string::npos) {
				error.insert(i, "\"");
				i += 2;
			}
			returnString = "[\"" + std::string(PROTOCOL_MESSAGE_TYPE_ERROR) + "\", \"";
			returnString += error;
			returnString += "\"]";
		}

	} else {
		throw std::runtime_error("Don't know dtfunction: " + dtfunction);
	}

	return returnString;
}

std::string datetime::getDateTimeArray(boost::property_tree::ptree &dtarguments) {
	std::stringstream returnString;
	std::time_t now = std::time(0);

	std::tm *ltm = std::localtime(&now);

	returnString << "[" << 1900 + ltm->tm_year
				<< ", " << 1 + ltm->tm_mon
				<< ", " << ltm->tm_mday
				<< ", " << ltm->tm_hour
				<< ", " << ltm->tm_min
				<< ", " << ltm->tm_sec << "]";

	return returnString.str();
}

std::string datetime::getEpochTime(boost::property_tree::ptree &dtarguments) {
	std::stringstream returnString;
	std::time_t now = std::time(0);
	returnString << now;

	return returnString.str();
}
