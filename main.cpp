#include <iostream>

using namespace std;

int main()
{
	//연산자 우선순위 : *, /, % > +, -

	//플레이어 정보
	int PlayerHP = 100;
	int PlayerPhysicalDefence = 20;
	int PlayerMagicalRegist = 3;

	//몬스터 정보
	int MonsterPhysicalPower = 30;
	int MonsterMagicalPower = 10;

	int Damage = (MonsterPhysicalPower - PlayerPhysicalDefence) + (MonsterMagicalPower - PlayerMagicalRegist);

	PlayerHP = PlayerHP - Damage;

	cout << "플레이어가 몬스터에게 입은 피해량 : " << Damage << endl << "현재 플레이어 HP : " << PlayerHP << endl;

	return 0;
}