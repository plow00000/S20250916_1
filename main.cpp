#include <iostream>

using namespace std;

int main()
{
	//������ �켱���� : *, /, % > +, -

	//�÷��̾� ����
	int PlayerHP = 100;
	int PlayerPhysicalDefence = 20;
	int PlayerMagicalRegist = 3;

	//���� ����
	int MonsterPhysicalPower = 30;
	int MonsterMagicalPower = 10;

	int Damage = (MonsterPhysicalPower - PlayerPhysicalDefence) + (MonsterMagicalPower - PlayerMagicalRegist);

	PlayerHP = PlayerHP - Damage;

	cout << "�÷��̾ ���Ϳ��� ���� ���ط� : " << Damage << endl << "���� �÷��̾� HP : " << PlayerHP << endl;

	return 0;
}