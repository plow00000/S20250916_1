#include <iostream>

using namespace std;

int main()
{
	//������ �켱���� : *, /, % > +, -

	//�÷��̾� ����
	int PlayerHP = 100;
	int PlayerDef = 20;
	int PlayerReg = 3;

	//���� ����
	int MonsterAD = 30;
	int MonsterAP = 10;

	int Damage = (MonsterAD - PlayerDef) + (MonsterAP - PlayerReg);

	PlayerHP = PlayerHP - Damage;

	cout << "�÷��̾ ���Ϳ��� ���� ���ط� : " << Damage << endl << "���� �÷��̾� HP : " << PlayerHP << endl;

	return 0;
}