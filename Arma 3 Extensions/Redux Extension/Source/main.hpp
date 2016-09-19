#ifndef SOURCE_MAIN_HPP_
#define SOURCE_MAIN_HPP_

#ifdef __MINGW32__
		#define RVExtension __stdcall _RVExtension
#endif
#ifdef _MSC_VER
		#define RVExtension __stdcall RVExtension
#endif

#include <sstream>
#include <string>
#include <string.h>            // strcmp, strncpy

#include "redex.hpp"
redex extension;

#ifndef __linux__
	#define WIN32_LEAN_AND_MEAN    // Exclude rarely-used stuff from Windows headers
	#include <windows.h>           // Windows Header Files
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

	__declspec (dllexport) void RVExtension(char *output, int outputSize, const char *function);

	#ifdef __cplusplus
		}
	#endif
#endif

#endif /* SOURCE_MAIN_HPP_ */
