#include "mutex.h"

#include <assert.h>

namespace base {

Mutex::Mutex() { assert(0 == pthread_mutex_init(&mu_, NULL)); }

Mutex::~Mutex() { assert(0 == pthread_mutex_destroy(&mu_)); }

void Mutex::Lock() { assert(0 == pthread_mutex_lock(&mu_)); }

void Mutex::Unlock() { assert(0 == pthread_mutex_unlock(&mu_)); }

}  // namespace base
