// GOLRemixLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "GOL.h"

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
