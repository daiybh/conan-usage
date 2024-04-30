cmake_minimum_required(VERSION 3.15)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DUNICODE -D_UNICODE)

project(loglib CXX)

find_package(spdlog REQUIRED)
find_package(RapidJSON REQUIRED)


add_library(loglib STATIC src/logLib.cpp)
target_link_libraries(loglib PUBLIC spdlog::spdlog rapidjson)

target_include_directories(loglib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

set_target_properties(loglib PROPERTIES PUBLIC_HEADER "include/logLib.h")

install(TARGETS loglib)
