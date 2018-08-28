cmake_minimum_required(VERSION 2.8)
project(Numerical Calculation)

set(CMAKE_CXX_STANDARD 11)

add_library(NAlib NAlib.h NAlib.cpp)
add_library(matrix matrix.h matrix.cpp)

add_executable(Numerical Calculation main.cpp)

target_link_libraries(Numerical Calculation NAlib matrix)