// GOLRemixLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "GOL.h"
#include <Windows.h>
#include <iostream>
using namespace std;

// TODO: This is an example of a library function
//void fnGOLRemixLib()
//{
//}

std::vector<std::vector<int>> randomState(int height, int width)
{
	std::vector<std::vector<int>> state(height, std::vector<int>(width));


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int randomBit = rand() % 2;
			state[i][j] = randomBit;
		}
	}
	return state;
}

int square(int x)
{
	return x * x;
}

std::vector<std::vector<int>> nextBoardState(std::vector<std::vector<int>> initialState)
{
	return std::vector<std::vector<int>>();
}

//Changes console text color. Two hex digits are supplied, the first is the background and the second is the foreground. 
//	0 = Black       8 = Gray
//	1 = Blue        9 = Light Blue
//	2 = Green       A = Light Green
//	3 = Aqua        B = Light Aqua
//	4 = Red         C = Light Red
//	5 = Purple      D = Light Purple
//	6 = Yellow      E = Light Yellow
//	7 = White       F = Bright White

void color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void render(vector<vector<int>> stateVec)
{
	int rowSize = stateVec.size();
	int colSize = stateVec[0].size();
	const char BLOCK = 176;

	/*HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		GetLastError();
	}*/


	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			if (stateVec[row][col] == 0)
			{
				cout << " ";
			}
			else
			{
				color(0x0E);
				cout << BLOCK;
				color(0x07);

			}
		}

		cout << endl;
	}
}