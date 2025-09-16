#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
	int PlayerX = 1;
	int PlayerY = 1;
	char PlayerShape = '#';

	bool bIsRunning = true;
	int KeyCode = 0;

	int Map[10][10] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};

	while (bIsRunning)
	{
		system("cls");
		for (int Y = 0; Y < 10; Y++)
		{
			for (int X = 0; X < 10; X++)
			{
				if (PlayerX == X && PlayerY == Y) { cout << PlayerShape; }
				else { cout << ((bool)Map[Y][X] ? '*' : ' '); }
			}
			cout << '\n';
		}

		KeyCode = _getch();

		switch (KeyCode)
		{
		case 'w':
			PlayerY--;
			if (Map[PlayerY][PlayerX] == 1) { PlayerY++; }
			break;
		case 's':
			PlayerY++;
			if (Map[PlayerY][PlayerX] == 1) { PlayerY--; }
			break;
		case 'a':
			PlayerX--;
			if (Map[PlayerY][PlayerX] == 1) { PlayerX++; }
			break;
		case 'd':
			PlayerX++;
			if (Map[PlayerY][PlayerX] == 1) { PlayerX--; }
			break;
		default:
			break;
		}
	}

	return 0;
}