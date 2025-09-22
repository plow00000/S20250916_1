#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum {
	WindowWidth = 60,
	WindowHeight = 28
};

//맵 생성 및 크기 지정
char Map[WindowHeight][WindowWidth] = {};

//플레이어 정보
int PlayerX = 2;
int PlayerY = 2;
char PlayerShape = 'P';

//몬스터 정보
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

//게임 진행 여부 및 입력 키코드
bool bIsRunning = true;
int KeyCode = 0;

//충돌 대상 검사
char CollidedObject(int X, int Y)
{
	return Map[Y][X];
}

//충돌 대상 검사 후 이동 가능한 칸인지 확인
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

//입력
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

//렌더링
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
	//초기 기본 맵 생성
	// 35='#' 벽, 46 = '.' 갈 수 있는 길, 32=' ' 공허 공간
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
	//몬스터 배치
	Map[MonsterY][MonsterX] = MonsterShape;

	Render();
	while (bIsRunning)
	{
		Input();

		Render();
	}

	return 0;
}