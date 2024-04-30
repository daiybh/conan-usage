#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define MYLOGLIB_EXPORT __declspec(dllexport)
#else
  #define MYLOGLIB_EXPORT
#endif

MYLOGLIB_EXPORT void myloglib();
MYLOGLIB_EXPORT void myloglib_print_vector(const std::vector<std::string> &strings);

#include <string>

namespace MyLogLib {
enum class LogLevel { DEBUG, INFO, WARNING, ERROR };

void log(LogLevel level, const std::string& file, int line, const std::string& message);

inline void debug(const std::string& file, int line, const std::string& message) {
    log(LogLevel::DEBUG, file, line, message);
}

inline void info(const std::string& file, int line, const std::string& message) {
    log(LogLevel::INFO, file, line, message);
}

inline void warn(const std::string& file, int line, const std::string& message) {
    log(LogLevel::WARNING, file, line, message);
}

inline void error(const std::string& file, int line, const std::string& message) {
    log(LogLevel::ERROR, file, line, message);
}
} // namespace MyLogLib