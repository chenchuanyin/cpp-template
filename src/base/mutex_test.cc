#include "gtest/gtest.h"

#include "mutex.h"

#include <thread>

TEST(Mutex, normalTest) {
  base::Mutex m;
  m.Lock();
  m.Unlock();
}

TEST(Mutex, deadLockTest) {
  base::Mutex m;
  base::Mutex n;
  m.Lock();
  n.Lock();
  m.Unlock();
  n.Unlock();
}
