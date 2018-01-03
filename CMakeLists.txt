cmake_minimum_required(VERSION 3.0)
project(test C CXX)

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC -g")
set(BUILD_SHARED_LIBS ON)
set(CMAKE_SOURCE_DIR src)

add_subdirectory(third_party/benchmark)
add_subdirectory(third_party/cctz)
add_subdirectory(third_party/glog)
add_subdirectory(third_party/gflags)
add_subdirectory(third_party/googletest)
add_subdirectory(third_party/abseil-cpp)

add_subdirectory(src)

add_executable(demo ${CMAKE_SOURCE_DIR}/demo.cc)
target_link_libraries(demo base gflags glog absl_base absl_algorithm absl_container absl_synchronization cctz)
