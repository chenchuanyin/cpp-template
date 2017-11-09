cmake_minimum_required(VERSION 3.0)
project(test C CXX)

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC -g")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_SOURCE_DIR src)

add_subdirectory(third_party/glog)
add_subdirectory(third_party/gflags)
add_subdirectory(third_party/googletest)

add_subdirectory(src)

add_executable(demo ${CMAKE_SOURCE_DIR}/demo.cc)
target_link_libraries(demo gflags glog)
