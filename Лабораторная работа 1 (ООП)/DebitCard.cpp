#include "stdafx.h"
#include "DebitCard.h"
//�������� ��������:
//�������� ������:
void DebitCard::PutMoney(DebitCard DebitCard, double Sum)
{
	DebitCard.set_Balance(Sum);
	cout << "������ ��������, ������ �� �����: " << DebitCard.get_Balance() << " �.�." << endl;
}
//����� ������:
bool DebitCard::WithdrawMoney(DebitCard DebitCard, double Sum)
{
	DebitCard.set_Balance(-Sum);
	cout << "������ ������� �� �����, ������ �� �����: " << DebitCard.get_Balance() << " �.�." << endl;
	return true;
}
