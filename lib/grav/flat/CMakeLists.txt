cmake_minimum_required(VERSION 3.6)
project(flat-grav-prj)
add_library(grav-flat grav-flat.cpp)

include_directories(../)

add_subdirectory(../../atmos/gost-4401 ../../atmos/gost-4401)

add_executable(example example.cpp)
target_link_libraries(example grav-flat)
