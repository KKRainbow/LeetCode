project("LeetCode")
cmake_minimum_required(VERSION 3.2)

set(srcs Solving/main.cpp)
set(CMAKE_CXX_FLAGS "-g -std=c++11 -O0")

add_executable(main ${srcs})
