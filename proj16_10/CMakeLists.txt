cmake_minimum_required(VERSION 3.3)
project(proj16_10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")

set(SOURCE_FILES teach.c)
add_executable(proj16_10 ${SOURCE_FILES})
include_directories(${MY_SOURCE_DIR} ./)