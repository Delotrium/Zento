#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>
namespace Zento {

	class ZENTO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


//Core Log Macros 
#define ZNT_CORE_FATAL(...) ::Zento::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define ZNT_CORE_ERROR(...) ::Zento::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZNT_CORE_WARN(...)  ::Zento::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZNT_CORE_INFO(...)  ::Zento::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZNT_CORE_TRACE(...) ::Zento::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client Log Macros
#define ZNT_FATAL(...) ::Zento::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define ZNT_ERROR(...) ::Zento::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZNT_WARN(...)  ::Zento::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZNT_INFO(...)  ::Zento::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZNT_TRACE(...) ::Zento::Log::GetClientLogger()->trace(__VA_ARGS__)