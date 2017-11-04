cmake_minimum_required(VERSION 3.0)
project(test C CXX)

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC -g")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_SOURCE_DIR src)
SET(COVERAGE OFF CACHE BOOL "Coverage")

add_subdirectory(third_party/glog)
add_subdirectory(third_party/gflags)
add_subdirectory(third_party/googletest)

add_executable(demo ${CMAKE_SOURCE_DIR}/demo.cc)
target_link_libraries(demo gflags glog)

if (COVERAGE)
  # target_compile_options(unittest PRIVATE --coverage)
  add_executable(unittest ${CMAKE_SOURCE_DIR}/gtest.cc)
  target_link_libraries(unittest PRIVATE --coverage gtest_main gtest)
endif()
