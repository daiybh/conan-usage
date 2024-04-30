cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(loglib CONFIG REQUIRED)

find_package(spdlog CONFIG REQUIRED)

add_executable(example src/example.cpp)
target_link_libraries(example loglib::loglib spdlog::spdlog)
