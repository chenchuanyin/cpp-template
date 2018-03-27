cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_COMPILER "/usr/local/bin/g++")
set(CMAKE_C_COMPILER "/usr/local/bin/gcc")
project(cpp-template C CXX)

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC -g")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE "Debug")

add_subdirectory(third_party/gflags)
add_subdirectory(third_party/googletest)
add_subdirectory(third_party/benchmark)
add_subdirectory(third_party/glog)
add_subdirectory(third_party/cctz)
add_subdirectory(third_party/abseil-cpp)

add_subdirectory(src)
