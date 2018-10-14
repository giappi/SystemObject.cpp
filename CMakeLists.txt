cmake_minimum_required(VERSION 3.7)
project(system_object_cpp)

set(CMAKE_CXX_STANDARD 14)
# Add -H to show include path
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ggdb -O0 -std=c++14 ")

include_directories( 
    "${PROJECT_SOURCE_DIR}/src"
)

file(
        GLOB SOURCES 
        "${PROJECT_SOURCE_DIR}/src/cpp/lang/*.cpp" 
        "${PROJECT_SOURCE_DIR}/src/*.cpp" 
)

add_executable(system_object_cpp ${SOURCES})