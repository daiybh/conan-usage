cmake_minimum_required(VERSION 3.15)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DUNICODE -D_UNICODE)

project(PackageTest CXX)

find_package(loglib CONFIG REQUIRED)



add_executable(example src/example.cpp)
target_link_libraries(example loglib::loglib)
