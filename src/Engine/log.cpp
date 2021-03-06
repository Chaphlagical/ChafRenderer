#include <Engine/log.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <cstdio>

namespace Chaf
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	std::shared_ptr<spdlog::logger> Log::s_CoreFileLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientFileLogger;

	void Log::Init()
	{
		spdlog::flush_on(spdlog::level::info);

		remove("log.txt");

		s_CoreFileLogger = spdlog::basic_logger_mt("Chaf Engine", L"log.txt");
		s_CoreFileLogger->set_level(spdlog::level::trace);

		s_ClientFileLogger = spdlog::basic_logger_mt("App", L"log.txt");
		s_ClientFileLogger->set_level(spdlog::level::trace);

		s_CoreLogger = spdlog::stderr_color_mt("Chaf Engine Console");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stderr_color_mt("App Console");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}