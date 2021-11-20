cmake_minimum_required(VERSION 3.20)
project(DynamicArrayLib)

set(CMAKE_CXX_STANDARD 14)

add_executable(DynamicArrayLib main.cpp LoopedArray.h LoopedArrayTemplate.h)
