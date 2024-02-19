cmake_minimum_required(VERSION 2.8)

project(Parsers)

add_executable(main graph.cpp)
add_library(lib Parsers.cpp)

target_link_libraries(main lib)