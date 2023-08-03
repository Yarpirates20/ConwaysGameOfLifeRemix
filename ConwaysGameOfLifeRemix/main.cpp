#include <iostream>
#include <vector>
#include <Windows.h>
#include "../GOLRemixLib/GOL.h"
using namespace std;

//vector<vector<int>> randomState(int, int);
//void render(vector<vector<int>>);
//void color(int color = 0x07);

int main()
{
	/*int square1 = square(5);
	cout << square1 << endl;*/
	srand(time(0));

	int height = 10, width = 20;
	vector<vector<int>> deadState = randomState(height, width);
	render(deadState);

	/*char block = 178;
	cout << block << endl;*/

	//SetConsoleOutputCP(CP_UTF8);
	//wchar_t a[] = L"\u2620";
	//wprintf(a);
	//wcout <<  L"\u2620" << endl;
	return 0;
}







