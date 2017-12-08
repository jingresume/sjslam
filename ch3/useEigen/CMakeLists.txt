cmake_minimum_required(VERSION 3.5)

PROJECT ( EIGENTEST )

include_directories( "/usr/include/eigen3" )

ADD_EXECUTABLE( eigenTest eigenMatrix.cpp )
