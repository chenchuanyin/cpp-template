set(SRCS mutex.cc)

add_library(base STATIC ${SRCS})
target_link_libraries(base pthread)

add_executable(mutex_test mutex_test.cc)
target_link_libraries(mutex_test base gtest_main gtest)

add_executable(mutexlock_test mutexlock_test.cc)
target_link_libraries(mutexlock_test base gtest_main gtest)

add_executable(convar_test convar_test.cc)
target_link_libraries(convar_test base gtest_main gtest)
