cmake_minimum_required(VERSION 3.6)
project(as1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    dummy.c
    dummy.h
    ex1.c
    ex2.c
    timing.c
    timing.h)

add_executable(as1 ${SOURCE_FILES})