cmake_minimum_required(VERSION 2.6)
project(practice)

include_directories("/usr/include/eigen3")
add_executable(practice main.cpp)

install(TARGETS practice RUNTIME DESTINATION bin)
