#include "pch.h"
#include "gtest/gtest.h"
#include "../GOLRemixLib/GOL.h"

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}

TEST(SquareTest, square)
{
	EXPECT_EQ(25, square(5));
}

TEST(DeadCellsTest, nextBoardState)
{
	int rows = 5, cols = 5;
	std::vector<std::vector<int>> dead(rows, std::vector<int>(cols, 0));
	EXPECT_EQ(dead, nextBoardState(dead));
}