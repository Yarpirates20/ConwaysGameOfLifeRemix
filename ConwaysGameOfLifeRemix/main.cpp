#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> randomState(int, int);

int main()
{
	int height = 10, width = 20;
	vector<vector<int>> deadState = randomState(height, width);
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			cout << deadState[row][col];
		}
		cout << endl;
	}
	return 0;
}

vector<vector<int>> randomState(int height, int width)
{
	vector<vector<int>> state(height, vector<int>(width));

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			state[i][j] = 0;
		}
	}
	return state;
}
