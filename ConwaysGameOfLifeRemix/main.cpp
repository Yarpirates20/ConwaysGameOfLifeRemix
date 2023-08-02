#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

vector<vector<int>> randomState(int, int);
void render(vector<vector<int>>);
void color(int color = 0x07);

int main()
{
	srand(time(0));

	int height = 10, width = 20;
	vector<vector<int>> deadState = randomState(height, width);
	render(deadState);

	return 0;
}

vector<vector<int>> randomState(int height, int width)
{
	vector<vector<int>> state(height, vector<int>(width));
	

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

void render(vector<vector<int>> stateVec)
{
	int rowSize = stateVec.size();
	int colSize = stateVec[0].size();

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
				cout << "#";
				color(0x07);

			}
		}

		cout << endl;
	}
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
void color(int color)
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
