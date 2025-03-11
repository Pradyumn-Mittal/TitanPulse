#pragma once

#ifdef TP_PLATFORM_WINDOWS
	#ifdef TP_BUILD_DLL
		#define TITAN_PULSE_API __declspec(dllexport)
	#else
		#define TITAN_PULSE_API __declspec(dllimport)
	#endif 
#else
	#error TitanPulse only supports Windows!
#endif
