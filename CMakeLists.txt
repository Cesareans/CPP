cmake_minimum_required(VERSION 3.14)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Testor)
add_subdirectory(Algorithm)
add_subdirectory(Problem)
add_subdirectory(Structure)
add_executable(test test.cpp)