/* main.hpp
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

#include "constants.hpp"
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
			break;
			case DLL_THREAD_ATTACH:
			break;
			case DLL_THREAD_DETACH:
			break;
			case DLL_PROCESS_DETACH:
				extension.terminate();
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
