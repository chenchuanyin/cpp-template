#ifndef BASE_CONVAR_H__
#define BASE_CONVAR_H__

#include "mutex.h"
#include "mutexlock.h"

#include <pthread.h>

namespace base {

class ConVar {
 public:
  ConVar(Mutex& mutex) : mutex_(mutex) {
    assert(0 == pthread_cond_init(&con_, NULL));
  }
  ~ConVar() { assert(0 == pthread_cond_destroy(&con_)); }
  void Wait() {
    MutexLock lock(mutex_);
    assert(0 == pthread_cond_wait(&con_, &mutex_.mu_));
  }
  void Signal() { assert(0 == pthread_cond_signal(&con_)); }
  void SignalAll() { assert(0 == pthread_cond_broadcast(&con_)); }

 private:
  pthread_cond_t con_;
  Mutex&         mutex_;

  ConVar(const ConVar& other) = delete;
  ConVar operator=(const ConVar& other) = delete;
};

}  // namespace base

#endif  // BASE_CONVAR_H__
