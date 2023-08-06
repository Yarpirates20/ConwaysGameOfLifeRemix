
// GOLRemixLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "GOL.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
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
	int height = initialState.size();
	int width = initialState[0].size();

	std::vector<std::vector<int>> nextState(height, std::vector<int>(width, 0));
	int dirs[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

	for (int row = 0; row < height; ++row)
	{
		for (int col = 0; col < width; ++col)
		{
			// Count neighbors
			int numNeighbors = 0;
			for (const auto& d : dirs)
			{
				int x = row + d[0];
				int y = col + d[1];
				if (x >= 0 && x < height && y >= 0 && y < width && initialState[x][y] == 1)
				{
					++numNeighbors;
				}

			}
			//int left = (col - 1 + width) % width;
			//int right = (col + 1 + width) % width;
			//int above = (row - 1 + height) % height;
			//int below = (row + 1 + height) % height;

			//if (initialState[above][left] == 1)
			//{
			//	numNeighbors++;
			//}
			//if (initialState[above][col] == 1)
			//{
			//	numNeighbors++;
			//}
			//if (initialState[above][right] == 1)
			//{
			//	numNeighbors++;
			//}
			//if (initialState[row][left] == 1)
			//{
			//	numNeighbors++;
			//}
			//if (initialState[row][right] == 1)
			//{
			//	numNeighbors++;
			//}
			//if (initialState[below][left] == 1)
			//{
			//	numNeighbors++;
			//}
			//if (initialState[below][col] == 1)
			//{
			//	numNeighbors++;
			//}
			//if (initialState[below][right] == 1)
			//{
			//	numNeighbors++;
			//}

			// Set next state cells based on num neighbors
			//if (initialState[row][col] == 1)
			//{
			//	if (numNeighbors == 0 || numNeighbors == 1)
			//	{
			//		nextState[row][col] = 0;
			//	} 
			//	else if (numNeighbors == 2 || numNeighbors == 3)
			//	{
			//		nextState[row][col] = 1;
			//	}
			//	else if (numNeighbors > 3)
			//	{
			//		nextState[row][col] = 0;
			//	}
			//}
			//else if (initialState[row][col] == 0)
			//{
			//	if (numNeighbors == 3)
			//	{
			//		nextState[row][col] = 1;
			//	}
			//}
			if (initialState[row][col] == 1 && (numNeighbors == 2 || numNeighbors == 3))
			{
				nextState[row][col] = 1;
			}
			else if (initialState[row][col] == 0 && numNeighbors == 3)
			{
				nextState[row][col] = 1;
			}
			else
			{
				nextState[row][col] = 0;
			}

		}
	}

	return nextState;
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
	const char BLOCK = 254;

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

std::vector<std::vector<int>> loadBoardState(std::string filename)
{
	std::ifstream infile(filename);
	if (!infile)
	{
		cout << "File could not be found.\n";
		exit(0);
	}
	std::vector<std::vector<int>> loadVec;

	std::string line;
	//std::istringstream iss(line);

	while (!infile.eof())
	{
		vector<int> temp;
		getline(infile, line);
		for (auto c : line)
		{
			temp.push_back(c - '0');
		}
		loadVec.push_back(temp);
	}


	infile.close();

	return loadVec;
}
