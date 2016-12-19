/* datetime.hpp
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

#ifndef SOURCE_DATETIME_HPP_
#define SOURCE_DATETIME_HPP_

#include <algorithm>
#include <string>
#include <map>
#include <tuple>
#include <boost/property_tree/ptree.hpp>
#include <boost/function.hpp>

#include "constants.hpp"

class datetime {
public:
	datetime();
	~datetime();
	std::string processDTCall(boost::property_tree::ptree &dtcall);

private:
	typedef boost::function<std::string(boost::property_tree::ptree &dtarguments)> DT_FUNCTION;
	typedef std::map<std::string, DT_FUNCTION> DT_FUNCTIONS;
	DT_FUNCTIONS dtfunctions;

	std::string getDateTimeArray(boost::property_tree::ptree &dtarguments);
	std::string getEpochTime(boost::property_tree::ptree &dtarguments);
};


#endif /* SOURCE_DATETIME_HPP_ */
