cmake_minimum_required(VERSION 3.3)
project(polynomial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")

set(SOURCE_FILES main.c poly.c poly.h)
add_executable(polynomial ${SOURCE_FILES})
include_directories(./)