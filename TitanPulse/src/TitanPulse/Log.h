#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // Include this to ensure proper formatting

namespace TitanPulse
{
	class  Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros

#define TP_CORE_TRACE(...)  ::TitanPulse::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TP_CORE_INFO(...)   ::TitanPulse::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TP_CORE_WARN(...)   ::TitanPulse::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TP_CORE_ERROR(...)  ::TitanPulse::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TP_CORE_FATAL(...)  ::TitanPulse::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros

#define TP_TRACE(...)       ::TitanPulse::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TP_INFO(...)        ::TitanPulse::Log::GetClientLogger()->info(__VA_ARGS__)
#define TP_WARN(...)        ::TitanPulse::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TP_ERROR(...)       ::TitanPulse::Log::GetClientLogger()->error(__VA_ARGS__)
#define TP_FATAL(...)       ::TitanPulse::Log::GetClientLogger()->fatal(__VA_ARGS__)
