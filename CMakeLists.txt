cmake_minimum_required(VERSION 3.12)
project(stringencoding)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")

set(CMAKE_CXX_STANDARD 11)

add_executable(stringencoding stringmain.cpp)
