set(CMAKE_SOURCE_DIR .)
add_subdirectory(base)


add_executable(demo ${CMAKE_SOURCE_DIR}/demo.cc)
target_link_libraries(demo base gflags glog absl_base absl_algorithm absl_container absl_synchronization cctz gtest gtest_main)

add_executable(demo_benchmark ${CMAKE_SOURCE_DIR}/demo_benchmark.cc)
target_link_libraries(demo_benchmark benchmark)

add_executable(uint2str_benchmark ${CMAKE_SOURCE_DIR}/uint2str_benchmark.cc)
target_link_libraries(uint2str_benchmark benchmark)

add_executable(uint2str_unittest ${CMAKE_SOURCE_DIR}/uint2str_unittest.cc)
target_link_libraries(uint2str_unittest gtest gtest_main)

add_executable(absl_unittest ${CMAKE_SOURCE_DIR}/absl_unittest.cc)
target_link_libraries(absl_unittest gflags glog absl_base absl_algorithm absl_container absl_synchronization absl_memory absl_debugging cctz gtest gtest_main)

add_executable(gflags_demo ${CMAKE_SOURCE_DIR}/gflags_demo.cc)
target_link_libraries(gflags_demo gflags glog)

add_executable(string_unittest ${CMAKE_SOURCE_DIR}/string_unittest.cc)
target_link_libraries(string_unittest glog absl_strings gtest gtest_main)
