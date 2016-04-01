cmake_minimum_required(VERSION 3.3)
project(proj16_5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")

set(SOURCE_FILES rational.c rational.h main.c)
add_executable(proj16_5 ${SOURCE_FILES})
include_directories(${MY_SOURCE_DIR} ./)