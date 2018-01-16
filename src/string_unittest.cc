#include "absl/algorithm/container.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "absl/strings/str_replace.h"
#include "absl/strings/str_split.h"
#include "glog/logging.h"
#include "gtest/gtest.h"

TEST(AbslTest, StringCat) {
  int         t   = 1;
  std::string str = "test";
  auto        s   = absl::StrCat(t, str);
  EXPECT_EQ(s, "1test");
}

TEST(AbslTest, StringSplit) {
  auto str        = "test test test";
  auto split_list = absl::StrSplit(str, " ");
  for (auto it = split_list.begin(); it != split_list.end(); ++it) {
    EXPECT_EQ(*it, "test");
  }
}

TEST(AbslTest, StringJoin) {
  auto hello = "hello";
  auto world = "world";
  auto join  = absl::StrJoin(std::vector<std::string>{hello, world}, " ");
  EXPECT_EQ(join, "hello world");
}
