#include "uuid.hpp"

#ifdef __linux__
#include <string.h>            // strcmp, strncpy

#else

#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers
#include <windows.h>           // Windows Header Files:
#ifdef _MSC_VER
#include <boost/config/compiler/visualc.hpp>
#endif

BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __MINGW32__
	__declspec (dllexport) void __stdcall _RVExtension(char *output, int outputSize, const char *function);
#endif

#ifdef _MSC_VER
	__declspec(dllexport) void __stdcall RVExtension(char *output, int outputSize, const char *function);
#endif

#ifdef __cplusplus
}
#endif
#endif

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

#ifdef __MINGW32__
void __stdcall _RVExtension(char *output, int outputSize, const char *function)
#endif
#ifdef _MSC_VER
void __stdcall RVExtension(char *output, int outputSize, const char *function)
#endif
#ifdef __linux__
void RVExtension(char *output, int outputSize, const char *function)
#endif
{
	outputSize -= 1;
	try {
		std::stringstream functionstream;
		functionstream << function;

		boost::property_tree::ptree pt;
		boost::property_tree::read_json(functionstream, pt);

		boost::property_tree::ptree &dllarguments = pt.get_child(
				"dllarguments");

		std::string dllfunction = pt.get<std::string>("dllfunction");

		if (dllfunction.compare("dbcall") == 0) {
			std::string dbfunction = dllarguments.get<std::string>(
					"dbfunction");

			if (dbfunction.compare("uuid") == 0) {
				std::string uuid = orderedUUID();
				strncpy(output, uuid.c_str(), outputSize);
			} else {
				std::string errstr = "Don't know dbfunction";
				errstr += errstr;
				strncpy(output, errstr.c_str(), outputSize);
			}
		} else {
			std::string errstr = "Don't know dllfunction";
			errstr += errstr;

			strncpy(output, errstr.c_str(), outputSize);
		}
		return;
	} catch (std::exception const& e) {
		std::string errstr = "ERROR: ";
		errstr += e.what();
		strncpy(output, errstr.c_str(), outputSize);
	}
}
