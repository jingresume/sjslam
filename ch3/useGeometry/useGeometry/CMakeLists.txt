cmake_minimum_required(VERSION 2.6)
project(usegeometry)
include_directories("/usr/include/eigen3")
add_executable(usegeometry main.cpp)

install(TARGETS usegeometry RUNTIME DESTINATION bin)
