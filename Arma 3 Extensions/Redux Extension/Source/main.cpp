#include "main.hpp"

void RVExtension(char *output, int outputSize, const char *function)
{
	outputSize -= 1;
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
