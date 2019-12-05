cmake_minimum_required(VERSION 3.14)
project(Q1 C)

set(CMAKE_C_STANDARD 90)

add_executable(Q1 myset.c set.c set.h utilities.c utilities.h)