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

//class boardState : public ::testing::Test
//{
//protected:
//	void SetUp() override
//	{
//		
//	}
//
//	std::vector<std::vector<int>> deadState = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
//	std::vector<std::vector<int>> initState = { {0, 0, 1}, {0, 1, 1}, {0, 0, 0} };
//
//};

namespace boardState
{
	class boardStateTest : public ::testing::Test
	{
	protected:
		void SetUp() override
		{

		}

		std::vector<std::vector<int>> deadState_ = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
		std::vector<std::vector<int>> initState_ = { {0, 0, 1}, {0, 1, 1}, {0, 0, 0} };
		std::vector<std::vector<int>> livingState_ = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
		

	};
	
	TEST_F(boardStateTest, DeadStaysDead)
	{
		/*int rows = 5, cols = 5;
		std::vector<std::vector<int>> dead(rows, std::vector<int>(cols, 0));*/
		EXPECT_EQ(deadState_, nextBoardState(deadState_));
		SUCCEED();
	}

	TEST_F(boardStateTest, DeadToAlive)
	{
		/*std::vector<std::vector<int>> initState = { {0, 0, 1}, {0, 1, 1}, {0, 0, 0} };*/
		std::vector<std::vector<int>> next = { {0, 1, 1}, {0, 1, 1}, {0, 0, 0} };
		EXPECT_EQ(next, nextBoardState(initState_));
	}

	TEST_F(boardStateTest, AliveToDead)
	{
		std::vector<std::vector<int>> next = { {1, 0, 1}, {0, 0, 0}, {1, 0, 1} };
		EXPECT_EQ(next, nextBoardState(livingState_));
	}
}