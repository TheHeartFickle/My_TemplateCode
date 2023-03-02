cmake_minimum_required(VERSION 3.0.0)

project(demo VERSION 0.1.0)
set(CMAKE_CXX_COMPILER "g++")

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(./src SrcFiles)
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(demo ${SrcFiles})
