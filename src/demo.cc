#include "base/annotation.h"

#include "absl/algorithm/algorithm.h"
#include "absl/algorithm/container.h"
#include "absl/base/call_once.h"
#include "absl/base/config.h"
#include "absl/memory/memory.h"
#include "absl/synchronization/internal/thread_pool.h"
#include "absl/synchronization/mutex.h"
#include "glog/logging.h"
#include "glog/raw_logging.h"
#include "glog/stl_logging.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  LOG(WARNING) << "hi demo";
  LOG(ERROR) << "error";
  LOG(INFO) << "info";
  LOG_IF(ERROR, 1 == 0) << "1 == 0";
  absl::Mutex mutex;
  absl::MutexLock lock(&mutex);
  absl::synchronization_internal::ThreadPool pool(4);
  while (1) {
    ::sleep(1);
    pool.Schedule([]() { LOG(ERROR) << "1"; });
  }
  return 0;
}
