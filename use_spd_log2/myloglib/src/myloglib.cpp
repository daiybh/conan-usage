#include <iostream>
#include "myloglib.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>


void myloglib(){
    

    #ifdef NDEBUG
    std::cout << "myloglib/1.0: Hello World Release!\n";
    #else
    std::cout << "myloglib/1.0: Hello World Debug!\n";
    #endif

    // ARCHITECTURES
    #ifdef _M_X64
    std::cout << "  myloglib/1.0: _M_X64 defined\n";
    #endif

    #ifdef _M_IX86
    std::cout << "  myloglib/1.0: _M_IX86 defined\n";
    #endif

    #ifdef _M_ARM64
    std::cout << "  myloglib/1.0: _M_ARM64 defined\n";
    #endif

    #if __i386__
    std::cout << "  myloglib/1.0: __i386__ defined\n";
    #endif

    #if __x86_64__
    std::cout << "  myloglib/1.0: __x86_64__ defined\n";
    #endif

    #if __aarch64__
    std::cout << "  myloglib/1.0: __aarch64__ defined\n";
    #endif

    // Libstdc++
    #if defined _GLIBCXX_USE_CXX11_ABI
    std::cout << "  myloglib/1.0: _GLIBCXX_USE_CXX11_ABI "<< _GLIBCXX_USE_CXX11_ABI << "\n";
    #endif

    // MSVC runtime
    #if defined(_DEBUG)
        #if defined(_MT) && defined(_DLL)
        std::cout << "  myloglib/1.0: MSVC runtime: MultiThreadedDebugDLL\n";
        #elif defined(_MT)
        std::cout << "  myloglib/1.0: MSVC runtime: MultiThreadedDebug\n";
        #endif
    #else
        #if defined(_MT) && defined(_DLL)
        std::cout << "  myloglib/1.0: MSVC runtime: MultiThreadedDLL\n";
        #elif defined(_MT)
        std::cout << "  myloglib/1.0: MSVC runtime: MultiThreaded\n";
        #endif
    #endif

    // COMPILER VERSIONS
    #if _MSC_VER
    std::cout << "  myloglib/1.0: _MSC_VER" << _MSC_VER<< "\n";
    #endif

    #if _MSVC_LANG
    std::cout << "  myloglib/1.0: _MSVC_LANG" << _MSVC_LANG<< "\n";
    #endif

    #if __cplusplus
    std::cout << "  myloglib/1.0: __cplusplus" << __cplusplus<< "\n";
    #endif

    #if __INTEL_COMPILER
    std::cout << "  myloglib/1.0: __INTEL_COMPILER" << __INTEL_COMPILER<< "\n";
    #endif

    #if __GNUC__
    std::cout << "  myloglib/1.0: __GNUC__" << __GNUC__<< "\n";
    #endif

    #if __GNUC_MINOR__
    std::cout << "  myloglib/1.0: __GNUC_MINOR__" << __GNUC_MINOR__<< "\n";
    #endif

    #if __clang_major__
    std::cout << "  myloglib/1.0: __clang_major__" << __clang_major__<< "\n";
    #endif

    #if __clang_minor__
    std::cout << "  myloglib/1.0: __clang_minor__" << __clang_minor__<< "\n";
    #endif

    #if __apple_build_version__
    std::cout << "  myloglib/1.0: __apple_build_version__" << __apple_build_version__<< "\n";
    #endif

    // SUBSYSTEMS

    #if __MSYS__
    std::cout << "  myloglib/1.0: __MSYS__" << __MSYS__<< "\n";
    #endif

    #if __MINGW32__
    std::cout << "  myloglib/1.0: __MINGW32__" << __MINGW32__<< "\n";
    #endif

    #if __MINGW64__
    std::cout << "  myloglib/1.0: __MINGW64__" << __MINGW64__<< "\n";
    #endif

    #if __CYGWIN__
    std::cout << "  myloglib/1.0: __CYGWIN__" << __CYGWIN__<< "\n";
    #endif
}

void myloglib_print_vector(const std::vector<std::string> &strings) {
    for(std::vector<std::string>::const_iterator it = strings.begin(); it != strings.end(); ++it) {
        std::cout << "myloglib/1.0 " << *it << std::endl;
    }
}

namespace MyLogLib {
void log(LogLevel level, const std::string& file, int line, const std::string& message) {
    static auto console_logger = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    static auto file_logger = 
    std::make_shared<spdlog::sinks::basic_file_sink_mt>("mylog.txt", true);
    static spdlog::logger logger("mylog", {console_logger, file_logger});

    switch (level) {
    case LogLevel::DEBUG:
        logger.debug("[{}:{}] {}", file, line, message);
        break;
    case LogLevel::INFO:
        logger.info("[{}:{}] {}", file, line, message);
        break;
    case LogLevel::WARNING:
        logger.warn("[{}:{}] {}", file, line, message);
        break;
    case LogLevel::ERROR:
        logger.error("[{}:{}] {}", file, line, message);
        break;
    }
}
} // namespace MyLogLib