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

TEST(DeadToAliveTest, nextBoardState)
{
	std::vector<std::vector<int>> initState = { {0, 0, 1}, {0, 1, 1}, {0, 0, 0} };
	std::vector<std::vector<int>> next = { {0, 1, 1}, {0, 1, 1}, {0, 0, 0} };
	EXPECT_EQ(next, nextBoardState(initState));
}