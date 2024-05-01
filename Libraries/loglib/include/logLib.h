#pragma once
#include <memory>
#include <any>
#include <format>
#include <string_view>

namespace SimplyLive
{
	class Logger
	{
	public:
		enum class Level
		{
			debug = 10000,
			info = 20000,
			warn = 30000,
			error = 40000,
			fatal = 50000,
		};

		struct LogConfig
		{
			Level logLevelThreshold = Level::info;
			bool asyncLog = true;
			uint32_t maxLogFileSizeMB = 20;
			uint32_t maxNumberOfRollingFile = 5;
			bool addProcessName = false;
			bool relativePath = true;
		};

		explicit Logger(std::wstring_view path, LogConfig *logConfig = nullptr);

		void setPath(std::wstring_view path, LogConfig *logConfig = nullptr);

		template <typename T, typename... Args>
		void debug2(const T *fmt, Args &&...args)
		{
			auto x=std::vformat(fmt, std::forward<Args>(args)...);
			log(Level::debug, x);
		}
		template <typename... Args>
		inline void debug(const std::format_string<Args...> fmt, Args &&...args)
		{
			auto x=  std::vformat(fmt.get(), std::make_format_args(args...)) ;
			log(Level::debug, x);
		}

		void debug(const std::string_view fmt) const { log(Level::debug, fmt); }
		void debug(const std::wstring_view fmt) const { log(Level::debug, fmt); }

		template <typename T, typename... Args>
		void info(const T *fmt, Args &&...args) { log(Level::info, std::vformat(fmt, std::forward<Args>(args)...)); }

		void info(const std::string_view fmt) const { log(Level::info, fmt); }
		void info(const std::wstring_view fmt) const { log(Level::info, fmt); }

		template <typename T, typename... Args>
		void warn(const T *fmt, Args &&...args) { log(Level::warn, std::vformat(fmt, std::forward<Args>(args)...)); }

		void warn(const std::string_view fmt) const { log(Level::warn, fmt); }
		void warn(const std::wstring_view fmt) const { log(Level::warn, fmt); }

		template <typename T, typename... Args>
		void error3(const T *fmt, Args &&...args) 
		{ 
			auto x=std::vformat(fmt, std::forward<Args>(args)...);
			log(Level::error, x); 
		}
		template <typename... Args>
		inline void error(const std::format_string<Args...> fmt, Args &&...args)
		{
			auto x=  std::vformat(fmt.get(), std::make_format_args(args...)) ;
			log(Level::error, x);
		}

		void error(const std::string_view fmt) const { log(Level::error, fmt); }
		void error(const std::wstring_view fmt) const { log(Level::error, fmt); }

		template <typename T, typename... Args>
		void fatal(const T *fmt, Args &&...args) { log(Level::fatal, std::vformat(fmt, std::forward<Args>(args)...)); }

		void fatal(const std::string_view fmt) const { log(Level::fatal, fmt); }
		void fatal(const std::wstring_view fmt) const { log(Level::fatal, fmt); }

		Logger();
		~Logger();
		Logger(const Logger &) = delete;
		Logger(Logger &&) = delete;
		Logger &operator=(const Logger &) = delete;
		Logger &operator=(Logger &&) = delete;

	private:
		std::any m_logger;

		void log(Level level, std::string_view log) const;
		void log(Level level, std::wstring_view log) const;
	};
}

using simplyLogger = std::shared_ptr<SimplyLive::Logger>;
