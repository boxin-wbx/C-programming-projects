cmake_minimum_required(VERSION 3.5)
project(snowflake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")

set(SOURCE_FILES main.c)
aux_source_directory(./libgraphics LIB_SOURCE)
include_directories("./include")
add_executable(snowflake ${SOURCE_FILES} ${LIB_SOURCE})