set(CMAKE_SOURCE_DIR .)

add_subdirectory(base)

add_executable(demo ${CMAKE_SOURCE_DIR}/demo.cc)
target_link_libraries(demo base gflags glog absl_base absl_algorithm absl_container absl_synchronization cctz gtest gtest_main)

add_executable(benchmark_demo ${CMAKE_SOURCE_DIR}/benchmark_demo.cc)
target_link_libraries(benchmark_demo benchmark)
