cmake_minimum_required(VERSION 3.14)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(SwordToOffer)
add_subdirectory(NME)
add_executable(climbStairs climbStairs.cpp)
add_executable(fibonaci fibonaci.cpp)