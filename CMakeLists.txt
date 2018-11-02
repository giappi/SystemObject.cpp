cmake_minimum_required(VERSION 3.7)
project(system_object_cpp)

set(CMAKE_CXX_STANDARD 14)

# Add -H to show include path
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ggdb -O0 -std=c++14")

# Set warning options
## enable warning all
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

## disable bellow warnings
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS}"
    " -Wno-delete-non-virtual-dtor"
    " -Wno-deprecated-register"
    " -Wno-overloaded-virtual"
    " -Wno-unknown-pragmas"
    " -Wno-unused-private-field"
    " -Wno-unused-value"
    " -Wno-unused-variable"
)
# relace ";" by character space in CMAKE_CXX_FLAGS
string(REPLACE ";" " " CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})


include_directories( 
    "${PROJECT_SOURCE_DIR}/src"
)

file(
    GLOB SystemObjectFiles
    "${PROJECT_SOURCE_DIR}/src/cpp/lang/*.cpp" 
    "${PROJECT_SOURCE_DIR}/src/cpp/ability/*.cpp" 
    "${PROJECT_SOURCE_DIR}/src/cpp/memory/*.cpp" 
    "${PROJECT_SOURCE_DIR}/src/utils/*.cpp" 
)

file(
    GLOB ExecutableFiles
    "${PROJECT_SOURCE_DIR}/src/*.cpp" 
)

add_library(SystemObject ${SystemObjectFiles})
add_executable(SystemObjectTest ${ExecutableFiles})
target_link_libraries(SystemObjectTest SystemObject)

## PRINT ENVIRONMENT INFORMATION

if(NOT WIN32)
    string(ASCII 27 ESC)
    set(COLOR_RESET     "${ESC}[0m")
    set(COLOR_BOLD      "${ESC}[1m")
    set(COLOR_RED       "${ESC}[91m")
    set(COLOR_GREEN     "${ESC}[92m")
    set(COLOR_YELLOW    "${ESC}[93m")
    set(COLOR_BLUE      "${ESC}[94m")
    set(COLOR_MAGENTA   "${ESC}[95m")
    set(COLOR_CYAN      "${ESC}[96m")
    set(COLOR_WHITE     "${ESC}[97m")
endif()

message("")
message("-- ${COLOR_BOLD}${COLOR_BLUE}CMAKE_CXX_FLAGS${COLOR_RESET}: ${COLOR_GREEN}'${CMAKE_CXX_FLAGS}'${COLOR_RESET}")
message("")