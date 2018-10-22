cmake_minimum_required(VERSION 3.7)
project(system_object_cpp)

set(CMAKE_CXX_STANDARD 14)

# Add -H to show include path
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ggdb -O0 -std=c++14")

# Set warning options
## enable warning all
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

## disable bellow warnings
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} \
    -Wno-delete-non-virtual-dtor \
    -Wno-deprecated-register \
    -Wno-overloaded-virtual \
    -Wno-unused-private-field \
    -Wno-unused-value \
    -Wno-unused-variable \
")

include_directories( 
    "${PROJECT_SOURCE_DIR}/src"
)

file(
    GLOB SystemObjectFiles 
    "${PROJECT_SOURCE_DIR}/src/cpp/lang/*.cpp" 
    "${PROJECT_SOURCE_DIR}/src/utils/*.cpp" 
)

file(
    GLOB ExecutableFiles
    "${PROJECT_SOURCE_DIR}/src/*.cpp" 
)

add_library(SystemObject ${SystemObjectFiles})
add_executable(SystemObjectTest ${ExecutableFiles})
target_link_libraries(SystemObjectTest SystemObject)
