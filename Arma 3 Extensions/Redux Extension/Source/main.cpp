/* main.cpp
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

#include "main.hpp"

void RVExtension(char *output, int outputSize, const char *function)
{
	try {
		std::string returnString = extension.processCallExtension(function, outputSize);
		strncpy(output, returnString.c_str(), outputSize);
		return;
	} catch (std::exception const& e) {
		std::string errstr = "[\"" + PROTOCOL_MESSAGE_TYPE_ERROR + "\", \"";
		errstr += e.what();
		errstr += "\"]";
		strncpy(output, errstr.c_str(), outputSize);
	}
}
