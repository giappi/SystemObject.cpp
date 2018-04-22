cmake_minimum_required(VERSION 3.7)
project(system_object_cpp)

set(CMAKE_CXX_STANDARD 11)
include_directories(src)
set(SOURCE_FILES
        src/cpp/lang/Array.cpp
        src/cpp/lang/Array.h
        src/cpp/lang/Integer.cpp
        src/cpp/lang/Integer.h
        src/cpp/lang/Number.cpp
        src/cpp/lang/Number.h
        src/cpp/lang/Object.cpp
        src/cpp/lang/Object.h
        src/cpp/lang/String.cpp
        src/cpp/lang/String.h
        src/_typedef.h
        src/Test.cpp)

add_executable(system_object_cpp ${SOURCE_FILES})