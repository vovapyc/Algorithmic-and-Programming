cmake_minimum_required(VERSION 3.6)
project(fromVB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(fromVB ${SOURCE_FILES})

set(BUILD_2 main3)
set(SOURCE_FILES_2 main3.cpp)
add_executable(${BUILD_2} ${SOURCE_FILES_2})

set(BUILD_2 main3_1)
set(SOURCE_FILES_3 main3_1.cpp)
add_executable(${BUILD_2} ${SOURCE_FILES_3})