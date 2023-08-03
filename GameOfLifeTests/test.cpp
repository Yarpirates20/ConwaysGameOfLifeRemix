#include "pch.h"
#include "gtest/gtest.h"
#include "../GOLRemixLib/GOLRemixLib.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(testSquare, square)
{
	EXPECT_EQ(25, square(5));
}