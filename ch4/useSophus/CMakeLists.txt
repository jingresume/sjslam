cmake_minimum_required(VERSION 2.6)
project(usesophus)

find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )



add_executable(useSophus main.cpp)

target_link_libraries( useSophus ${Sophus_LIBRARIES} )


