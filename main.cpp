#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum {
	WindowWidth = 60,
	WindowHeight = 28
};

//�� ���� �� ũ�� ����
char Map[WindowHeight][WindowWidth] = {};

//�÷��̾� ����
int PlayerX = 2;
int PlayerY = 2;
char PlayerShape = 'P';

//���� ����
class Monster {
	int x;
	int y;
	char shape;
	int hp;
	int mp;
	void Attack() {

	}
};

int MonsterX = 20;
int MonsterY = 20;
char MonsterShape = 'M';

//���� ���� ���� �� �Է� Ű�ڵ�
bool bIsRunning = true;
int KeyCode = 0;

//�浹 ��� �˻�
char CollidedObject(int X, int Y)
{
	return Map[Y][X];
}

//�浹 ��� �˻� �� �̵� ������ ĭ���� Ȯ��
bool EnableToGo(int X, int Y)
{
	switch (CollidedObject(X, Y))
	{
	case 46: // '.'
		return true;
		break;
	default:
		return false;
		break;
	}
}

//�Է�
void Input() {
	KeyCode = _getch();

	switch (KeyCode)
	{
	case 'w':
		if (EnableToGo(PlayerX, PlayerY - 1))
		{
			--PlayerY;
		}
		break;
	case 's':
		if (EnableToGo(PlayerX, PlayerY + 1))
		{
			++PlayerY;
		}
		break;
	case 'a':
		if (EnableToGo(PlayerX - 1, PlayerY))
		{
			--PlayerX;
		}
		break;
	case 'd':
		if (EnableToGo(PlayerX + 1, PlayerY))
		{
			++PlayerX;
		}
		break;
	case 'q':
		bIsRunning = false;
		break;
	default:
		break;
	}
}

//������
void Render() {
	system("cls");
	char drawChar = ' ';
	for (int Y = 0; Y < WindowHeight; Y++)
	{
		for (int X = 0; X < WindowWidth; X++)
		{
			cout << ((PlayerX == X && PlayerY == Y) ? PlayerShape : Map[Y][X]) << ' ';
		}
		cout << endl;
	}
}

int main()
{
	//�ʱ� �⺻ �� ����
	// 35='#' ��, 46 = '.' �� �� �ִ� ��, 32=' ' ���� ����
	for (int Y = 0; Y < WindowHeight; Y++)
	{
		for (int X = 0; X < WindowWidth; X++)
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
	//���� ��ġ
	Map[MonsterY][MonsterX] = MonsterShape;

	Render();
	while (bIsRunning)
	{
		Input();

		Render();
	}

	return 0;
}