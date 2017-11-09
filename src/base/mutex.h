#ifndef BASE_MUTEX_H__
#define BASE_MUTEX_H__

#include <pthread.h>

namespace base {

class ConVar;

class Mutex {
 public:
  Mutex();
  ~Mutex();

  void Lock();
  void Unlock();

 private:
  friend class ConVar;
  pthread_mutex_t mu_;

  Mutex(const Mutex& other) = delete;
  Mutex operator=(const Mutex& other) = delete;
};

}  // namespace base

#endif  // BASE_MUTEX_H__
