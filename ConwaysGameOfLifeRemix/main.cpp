#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> randomState(int, int);
void render(vector<vector<int>>);

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
				cout << "#";
			}
		}

		cout << endl;
	}
}
