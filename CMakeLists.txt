cmake_minimum_required(VERSION 3.0)
project(test C CXX)

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC -g")
set(BUILD_SHARED_LIBS ON)
add_subdirectory(third_party/glog)
add_subdirectory(third_party/gflags)
add_subdirectory(third_party/googletest)
add_executable(demo demo.cc)
target_link_libraries(demo gflags glog)

add_executable(unittest gtest.cc)
target_link_libraries(unittest gtest_main)
