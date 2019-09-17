cmake_minimum_required(VERSION 3.14)
project(CPPTestor)

set(CMAKE_CXX_STANDARD 14)

add_executable(rValueRef rValueRef.cpp)
add_executable(constructor constructor.cpp)
add_executable(localObject localObject.cpp)
add_executable(template template.cpp)