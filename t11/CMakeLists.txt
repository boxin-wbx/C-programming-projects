cmake_minimum_required(VERSION 3.5)
project(homework2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")

set(SOURCE_FILES main.c)
add_executable(homework2 ${SOURCE_FILES})