cmake_minimum_required(VERSION 3.15)

add_definitions(-DUNICODE -D_UNICODE)

project(PackageTest CXX)

find_package(loglib CONFIG REQUIRED)



add_executable(example src/example.cpp)
target_link_libraries(example loglib::loglib)
