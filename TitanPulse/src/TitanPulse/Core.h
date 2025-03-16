#pragma once

#ifdef TP_PLATFORM_WINDOWS
#if TP_DYNAMIC_LINK
#ifdef TP_BUILD_DLL
#define  Titan_Pulse_api  __declspec(dllexport)
#else
#define Titan_Pulse_api __declspec(dllimport)
#endif 
#else
#define  Titan_Pulse_api
#endif
#else
#error TitanPulse only supports Windows!
#endif

#ifdef TP_DEBUG
#define TP_ENABLE_ASSERTS
#endif // !TP_DEBUG


#ifdef TP_ENABLE_ASSERTS
#define TP_ASSERT(x, ...) { if(!(x)) { TP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define TP_CORE_ASSERT(x, ...) { if(!(x)) { TP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define TP_ASSERT(x, ...)
#define TP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)