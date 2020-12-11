#pragma once

#ifdef ZNT_PLATFORM_WINDOWS
	#ifdef ZNT_BUILD_DLL
		#define ZENTO_API __declspec(dllexport)
    #else
		#define ZENTO_API __declspec(dllimport)
    #endif
#else
	#error Windows Support only, currently
#endif