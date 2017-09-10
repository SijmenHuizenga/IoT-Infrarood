cmake_minimum_required(VERSION 3.8)
project(iotir)

set(CMAKE_CXX_STANDARD 11)

include_directories("library")

set(SOURCE_FILES opdracht-2/main.cpp opdracht-3/main.cpp)
add_executable(iotir ${SOURCE_FILES})