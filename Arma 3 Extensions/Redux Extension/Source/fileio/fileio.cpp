/* fileio.cpp
 *
 * Copyright 2016-2017 Desolation Redux
 *
 * Author: Legodev <legodevgit@mailbox.org>
 *         Kegan <ryancheek@hush.com>
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

#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <cassert>
#include <exception>
#include <stdexcept>
#include <fstream>

#include "fileio/fileio.hpp"

fileio::fileio() {
	iofunctions.insert(
			std::make_pair(std::string(PROTOCOL_IOCALL_FUNCTION_READ_FILE),
					boost::bind(&fileio::readFile, this, _1)));
	iofunctions.insert(
			std::make_pair(std::string(PROTOCOL_IOCALL_FUNCTION_WRITE_FILE),
					boost::bind(&fileio::writeFile, this, _1)));
	iofunctions.insert(
			std::make_pair(std::string(PROTOCOL_IOCALL_FUNCTION_APPEND_FILE),
					boost::bind(&fileio::appendFile, this, _1)));

    boost::property_tree::ptree configtree;
    boost::property_tree::json_parser::read_json("redex.json", configtree);


    for (auto& item : configtree.get_child("fileio.readonce")) {
		readlist.insert(std::make_pair(item.second.get_value<std::string>(), 1));
	}

	for (auto& item : configtree.get_child("fileio.read")) {
		readlist.insert(std::make_pair(item.second.get_value<std::string>(), 0));
	}

	for (auto& item : configtree.get_child("fileio.write")) {
		writelist.insert(std::make_pair(item.second.get_value<std::string>(), 0));
	}

	return;
}

fileio::~fileio() {
	return;
}

std::string fileio::processIOCall(boost::property_tree::ptree &iocall) {
	std::string returnString;

	std::string iofunction = iocall.get<std::string>("iofunction");
	boost::property_tree::ptree &ioarguments = iocall.get_child("ioarguments");

	IO_FUNCTIONS::iterator it = iofunctions.find(iofunction);
	if (it != iofunctions.end()) {
		const IO_FUNCTION &func(it->second);

		try {
			returnString = func(ioarguments);
		} catch (std::exception const& e) {
			returnString = "[\"" + std::string(PROTOCOL_MESSAGE_TYPE_ERROR)+ "\", \"";
			returnString += e.what();
			returnString += "\"]";
		}

	} else {
		throw std::runtime_error("Don't know iofunction: " + iofunction);
	}

	return returnString;
}

std::string fileio::readFile(boost::property_tree::ptree &ioarguments) {
	std::string filename = ioarguments.get<std::string>("filename");

	FILE_IO_MAP::iterator it = readlist.find(filename);
	if (it != readlist.end()) {
		if (it->second == 1) {
			readlist.erase(it);
		}

		int charpos, linenum;
		std::string returnString = "[";
		std::ifstream infile(filename);
		std::string line;

		linenum = 0;
		while (std::getline(infile, line)) {
			std::istringstream iss(line);

			// add second " to get the string after call compile to concatinate with the remaining parts
			charpos = 0;
			while ((charpos = line.find("\"", charpos)) != std::string::npos) {
				line.insert(charpos, "\"");
				charpos += 2;
			}

			if (linenum != 0) {
				returnString += ",";
			}

			returnString += "\"" + line + "\"";

			linenum++;
		}

		returnString += "]";
	} else {
			throw std::runtime_error("cannot read file: " + filename);
		}

	return "[\"" + std::string(PROTOCOL_MESSAGE_TYPE_MESSAGE) + "\", " + filename + "]";
}

std::string fileio::writeFile(boost::property_tree::ptree &ioarguments) {
	return "[\"" + std::string(PROTOCOL_MESSAGE_TYPE_MESSAGE) + "\", \"" + "not implemented" + "\"]";
}

std::string fileio::appendFile(boost::property_tree::ptree &ioarguments) {
	return "[\"" + std::string(PROTOCOL_MESSAGE_TYPE_MESSAGE) + "\", \"" + "not implemented" + "\"]";
}
