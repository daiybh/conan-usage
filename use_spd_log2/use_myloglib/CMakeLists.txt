cmake_minimum_required(VERSION 3.15)
project(app_myloglib CXX)

find_package(myloglib CONFIG REQUIRED)

add_executable(app_myloglib  src/main.cpp)

target_link_libraries(app_myloglib myloglib::myloglib)

install(TARGETS app_myloglib DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
