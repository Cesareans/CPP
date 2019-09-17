cmake_minimum_required(VERSION 3.14)
project(CPPTestor)

set(CMAKE_CXX_STANDARD 14)
#set (CMAKE_CXX_FLAGS "-fno-elide-constructors")

add_executable(rValueRef rValueRef.cpp)
add_executable(constructor constructor.cpp)
add_executable(localObject localObject.cpp)
add_executable(template template.cpp)
add_executable(virtualInherit virtualInherit.cpp)
add_executable(vptr vptr.cpp)
add_executable(vtable vtable.cpp)
add_executable(refField refField.cpp)