cmake_minimum_required(VERSION 3.21)

project(HLSL2021 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")

add_subdirectory(HLSL2021)

