#include "gtest/gtest.h"

#include "mutexlock.h"

TEST(MutexLock, normalTest) {
  base::Mutex mutex;
  base::MutexLock lock(mutex);
}
