cmake_minimum_required(VERSION 3.21)

project(CppProjectTemplate LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(SampleProject)
add_subdirectory(UnitTest)
add_subdirectory(ThirdParty/googletest EXCLUDE_FROM_ALL)

