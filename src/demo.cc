#include "absl/algorithm/algorithm.h"
#include "absl/algorithm/container.h"
#include "absl/base/call_once.h"
#include "absl/base/config.h"
#include "absl/memory/memory.h"
#include "absl/synchronization/internal/thread_pool.h"
#include "absl/synchronization/mutex.h"
#include "glog/logging.h"
#include "glog/raw_logging.h"

#include <algorithm>
#include <iostream>
#include <vector>

void func(int v) { std::cout << "v:" << v << std::endl; }

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);

  FLAGS_log_dir = "./log";
  LOG(INFO) << "hi demo";

  absl::Mutex mutex;
  absl::MutexLock lock(&mutex);

  absl::synchronization_internal::ThreadPool pool(4);
  while (1) {
    ::sleep(1);
    pool.Schedule([]() {
      LOG(INFO) << "1";
      std::cout << "1\n";
    });
  }
  return 0;
}
