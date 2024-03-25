cmake_minimum_required(VERSION 3.6)
project(flat-grav-prj)

include_directories(../)
include_directories(../../atmos/gost-4401)

add_subdirectory(../../atmos/gost-4401 ../../../atmos/gost-4401)


add_library(grav-flat grav-flat.cpp)
target_link_libraries(grav-flat atmos-4401)

add_executable(example-grav-flat example.cpp)
target_link_libraries(example-grav-flat grav-flat)
