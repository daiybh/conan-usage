cmake_minimum_required(VERSION 3.15)
project(myloglib CXX)


find_package(spdlog CONFIG REQUIRED)

add_library(myloglib src/myloglib.cpp)
target_include_directories(myloglib PUBLIC include)

target_link_libraries(myloglib PUBLIC spdlog::spdlog)

set_target_properties(myloglib PROPERTIES PUBLIC_HEADER "include/myloglib.h")
install(TARGETS myloglib)
