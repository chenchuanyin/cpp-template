#include "absl/algorithm/algorithm.h"
#include "absl/algorithm/container.h"
#include "absl/base/casts.h"
#include "absl/container/fixed_array.h"
#include "absl/debugging/leak_check.h"
#include "absl/memory/memory.h"
#include "absl/numeric/int128.h"
#include "absl/utility/utility.h"

#include "glog/logging.h"
#include "gtest/gtest.h"

TEST(LeakCheckTest, IgnoreLeakSuppressesLeakedMemoryErrors) {
  auto foo = absl::IgnoreLeak(new std::string("some ignored leaked string"));
  LOG(INFO) << "Ignoring leaked std::string " << foo;
}

TEST(LeakCheckTest, LeakCheckDisablerIgnoresLeak) {
  absl::LeakCheckDisabler disabler;
  auto foo =
      new std::string("some std::string leaked while checks are disabled");
  LOG(INFO) << "Ignoring leaked std::string " << foo;
}

TEST(MemoryCheckTest, MemoryCheckTest) {
  auto wp = absl::WeakenPtr(std::make_shared<int>(10));
  LOG(INFO) << wp.lock().get();
}
