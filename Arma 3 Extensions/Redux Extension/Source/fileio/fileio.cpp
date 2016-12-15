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

#include <unistd.h>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/regex.hpp>
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
	iofunctions.insert(
			std::make_pair(std::string(PROTOCOL_IOCALL_FUNCTION_PLUGINSYSTEM_GETINITORDER),
					boost::bind(&fileio::GetInitOrder, this, _1)));
	iofunctions.insert(
				std::make_pair(std::string(PROTOCOL_IOCALL_FUNCTION_PLUGINSYSTEM_GETCFGFILE),
						boost::bind(&fileio::GetCfgFile, this, _1)));

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

std::string fileio::GetInitOrder(boost::property_tree::ptree &ioarguments) {
#if defined(__linux__)
	std::string filename = "@DesolationServer/Config/pluginlist.cfg";
	if (access(filename.c_str(), F_OK) == -1) {
		std::transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
	}
#else
	std::string filename = "@DesolationServer\\Config\\PluginList.cfg";
#endif

	if (access(filename.c_str(), F_OK) != -1) {
		int charpos, linenum;
		std::string returnString = "[";
		std::ifstream infile(filename);
		std::string line;

		linenum = 0;
		while (std::getline(infile, line)) {
			std::istringstream iss(line);

			// remove comments
			boost::regex commentexpression("\\s*#.*");
			line = boost::regex_replace(line, commentexpression, "");

			// skip empty lines
			boost::regex nonEmptyLineRegex("\\S");
			boost::cmatch what;
			if (!boost::regex_match(line.c_str(), what, nonEmptyLineRegex)) {
				continue;
			}

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

		return returnString;
	} else {
		throw std::runtime_error("cannot read file" + filename);
	}

	return "";
}

std::string fileio::GetCfgFile(boost::property_tree::ptree &ioarguments) {
#if defined(__linux__)
	std::string path = "@DesolationServer/Config/";
#else
	std::string path = "@DesolationServer\\Config\\";
#endif
	std::string returnString = "[";
	int linenum = 0;

	for (auto& item : ioarguments.get_child("configfiles")) {
		std::string filename = item.second.get_value<std::string>();

		boost::regex dirupexpression("\\.\\.");
		filename = boost::regex_replace(filename, dirupexpression, "", boost::match_default | boost::format_all);

		filename = path + filename + ".cfg";

#if defined(__linux__)
		if (access(filename.c_str(), F_OK) == -1) {
			std::transform(filename.begin(), filename.end(), filename.begin(), ::tolower);
		}
#endif

		if (access(filename.c_str(), F_OK) != -1) {
			boost::property_tree::ptree configtree;
			boost::property_tree::ini_parser::read_ini(filename, configtree);

			BOOST_FOREACH(boost::property_tree::ptree::value_type &val, configtree) {
			    // val.first is the name of the child.
			    // val.second is the child tree.
				std::string key = val.first;
				std::string value = val.second.get_value<std::string>();

				// remove comments
				boost::regex commentexpression("\\s*#.*");
				value = boost::regex_replace(value, commentexpression, "");

				if (linenum != 0) {
					returnString += ",";
				}

				returnString += "[\"";
				returnString += key;
				returnString += "\",\"";
				returnString += value;
				returnString += "\"]";

				linenum++;
			}
		}
	}

	returnString += "]";
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
