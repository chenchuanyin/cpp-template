#ifndef BASE_CONCURRENT_QUEUE_H_
#define BASE_CONCURRENT_QUEUE_H_

#include "mutex.h"
#include "mutexlock.h"
#include "convar.h"

#include <queue>

namespace base {

template <typename T>
class ConcurrentQueue {
 public:
  ConcurrentQueue() : queue_(), mutex_(), con_() {}

  virtual ~ConcurrentQueue() {}

  void Push(const T& t);

  bool Pop(T& t, bool is_blocked = true);

  int32_t  Size() {
    MutexLock lock(mutex_);
    return queue_.size();
  }

  bool Empty() {
    MutexLock lock(mutex_);
    return queue_.empty();
  }

 private:
  std::queue<T> queue_;
  mutable Mutex mutex_;
  ConVar con_;

  ConcurrentQueue &operator=(const ConcurrentQueue &) = delete;
  ConcurrentQueue(const ConcurrentQueue &) = delete;
};

#include "concurrent_queue.tcc"
}

#endif // BASE_CONCURRENT_QUEUE_H_
