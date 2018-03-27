#ifndef BASE_MUTEXLOCK_H__
#define BASE_MUTEXLOCK_H__

#include "mutex.h"

namespace base {

class MutexLock {
 public:
  MutexLock(Mutex& mu) : mu_(mu) { mu_.Lock(); }
  ~MutexLock() { mu_.Unlock(); }

 private:
  Mutex& mu_;

  MutexLock(const Mutex& other) = delete;
  MutexLock operator=(const Mutex& other) = delete;
};

}

#endif
