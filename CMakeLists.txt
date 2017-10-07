cmake_minimum_required(VERSION 3.8)
project(iotir)

set(CMAKE_CXX_STANDARD 11)

include_directories("library")

set(SOURCE_FILES
#        opdracht-2/main.cpp
#        opdracht-3/main.cpp
#        opdracht-4/test1/main.cpp opdracht-4/test2/main.cpp
#        opdracht-5/main.cpp
#        opdracht-6/main.cpp
#        opdracht-7/main.cpp opdracht-7/circulairbuffer.cpp
        opdracht-8/main.cpp opdracht-8/circulairbuffer.cpp
        )
add_executable(iotir ${SOURCE_FILES})