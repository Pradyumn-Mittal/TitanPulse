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

#ifdef TP_ENABLE_ASSERTS
	#define TP_ASSERT(x, ...) { if(!(x)) { TP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TP_CORE_ASSERT(x, ...) { if(!(x)) { TP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TP_ASSERT(x, ...)
	#define TP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)