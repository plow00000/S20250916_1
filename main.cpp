#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum{
	WindowWidth = 120,
	WindowHeight = 28
};

int main()
{
	int PlayerX = 2;
	int PlayerY = 2;
	char PlayerShape = 'P';

	bool bIsRunning = true;
	int KeyCode = 0;


	// 35='#' 벽, 46 = '.' 갈 수 있는 길, 32=' ' 공허 공간, 10='\n' 개행용
	char Map[WindowHeight][WindowWidth];

	for (int Y = 0; Y < WindowHeight; Y++)
	{
		for(int X = 0; X < WindowWidth; X++)
		{
			if (Y == 0 || Y == WindowHeight - 1 || X == 0 || X == WindowWidth - 1)
			{
				Map[Y][X] = 32;
			}
			else if (Y == 1 || Y == WindowHeight - 2 || X == 1 || X == WindowWidth - 2)
			{
				Map[Y][X] = 35;
			}
			else
			{
				Map[Y][X] = 46;
			}
		}
	}

	while (bIsRunning)
	{
		system("cls");
		for (int Y = 0; Y < WindowHeight; Y++)
		{
			for (int X = 0; X < WindowWidth; X++)
			{
				cout << ((PlayerX == X && PlayerY == Y) ? PlayerShape : Map[Y][X]);
			}
			cout << '\n';
		}

		KeyCode = _getch();

		switch (KeyCode)
		{
		case 'w':
			PlayerY--;
			if (Map[PlayerY][PlayerX] == 35) { PlayerY++; }
			break;
		case 's':
			PlayerY++;
			if (Map[PlayerY][PlayerX] == 35) { PlayerY--; }
			break;
		case 'a':
			PlayerX--;
			if (Map[PlayerY][PlayerX] == 35) { PlayerX++; }
			break;
		case 'd':
			PlayerX++;
			if (Map[PlayerY][PlayerX] == 35) { PlayerX--; }
			break;
		case 'q':
			bIsRunning = false;
			break;
		default:
			break;
		}
	}

	return 0;
}