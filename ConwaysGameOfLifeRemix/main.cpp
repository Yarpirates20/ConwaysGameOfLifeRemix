#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#elif defined(__linux__)
#include <sys/ioctl.h>
#endif

void getTerminalSize(int& width, int& height)
{
#if defined(_WIN32)
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	width = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
	height = (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
#elif defined(__linux__)
	struct  winsize w;
	ioctl(fileno(stdout), TOPCGWINSZ, &w);
	width = (int)(w.ws_col);
	height = (int)(w.ws_row);
#endif
}

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <Windows.h>
#include "../GOLRemixLib/GOL.h"
using namespace std;



int main()
{

	srand(time(0));

	int height = 0, width = 0;
	getTerminalSize(width, height);
	vector<vector<int>> initialState = randomState(height, width);
	cout << "\u001b[2J";
	render(initialState);

	while (true)
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		cout << "\u001b[2J";
		vector<vector<int>> nextState = nextBoardState(initialState);
		render(nextState);

		initialState = nextState;

	}
	/*char block = 178;
	cout << block << endl;*/

	//SetConsoleOutputCP(CP_UTF8);
	//wchar_t a[] = L"\u2620";
	//wprintf(a);
	//wcout <<  L"\u2620" << endl;
	return 0;
}







