cmake_minimum_required(VERSION 3.15)
project(AppLoglib CXX)

find_package(loglib CONFIG REQUIRED)

find_package(lib_headeronly CONFIG REQUIRED)

add_executable(AppLoglib  src/main.cpp)

target_link_libraries(AppLoglib loglib::loglib lib_headeronly::lib_headeronly)

install(TARGETS AppLoglib DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
