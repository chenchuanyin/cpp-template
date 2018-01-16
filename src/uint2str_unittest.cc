#include "uint2str.h"

#include "gtest/gtest.h"

TEST(uint2strTest, normalTest) {
  EXPECT_EQ(uint2str(1234), "1234");
  EXPECT_EQ(uint2str2(1234), "1234");
  EXPECT_NE(uint2str2(1234), "12345");
}

TEST(uint2strTest, exceptionTest) {
  EXPECT_NE(uint2str(12345), "1234");
  EXPECT_NE(uint2str2(12345), "1234");
}

TEST(uint2strTest, boundaryTest) {
  EXPECT_EQ(uint2str(123456789012345), "123456789012345");
}
