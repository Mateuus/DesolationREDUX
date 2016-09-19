#include "main.hpp"

void RVExtension(char *output, int outputSize, const char *function)
{
	outputSize -= 1;
	try {
		std::string returnstring = extension.processCallExtension(function);
		strncpy(output, returnstring.c_str(), outputSize);
		return;
	} catch (std::exception const& e) {
		std::string errstr = "ERROR: ";
		errstr += e.what();
		strncpy(output, errstr.c_str(), outputSize);
	}
}
