cmake_minimum_required(VERSION 3.15)
add_definitions(-DUNICODE -D_UNICODE)
project(loglib CXX)

#define SPDLOG_WCHAR_FILENAMES
#define SPDLOG_WCHAR_TO_UTF8_SUPPORT
#add_definitions(-DSPDLOG_WCHAR_FILENAMES)
#add_definitions(-DSPDLOG_WCHAR_TO_UTF8_SUPPORT)



add_library(loglib src/logLib.cpp)
target_include_directories(loglib PUBLIC include rapidjson/include spdlog/include)

set_target_properties(loglib PROPERTIES PUBLIC_HEADER "include/logLib.h")

install(TARGETS loglib)
