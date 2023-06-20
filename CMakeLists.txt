cmake_minimum_required(VERSION 3.25)
project(LeetCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Easy)

add_executable(LeetCpp
        Easy/TwoSum.cpp)
