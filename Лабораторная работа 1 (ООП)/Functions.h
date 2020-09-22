#pragma once
#include"BankCard.h"
#include"DebitCard.h"

//�������������� �������� ��������� ������ BankCard:

//������� ���� �������� ����� �� ���� ���������:
unsigned int ValidityDefinedByCode(BankCard BankCard1, BankCard BankCard2, char* OCode)
{
	if (strcmp(BankCard1.get_OwnerCode(), OCode) == 0)
	{
		return BankCard1.get_ValidityPeriod();
	}
	else if (strcmp(BankCard2.get_OwnerCode(), OCode) == 0)
	{
		return BankCard2.get_ValidityPeriod();
	}
	else
	{
		return 0;
	}
}

//�����������, ����� �� ��� ����� ���� ��������:
bool OneCardNameForTwoCardsDetector(BankCard BankCard1, BankCard BankCard2)
{
	if (strcmp(BankCard1.get_CardName(), BankCard2.get_CardName()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�������������� �������� ������-���������� DebitCard:

//�� ���� ��������� �������� ������ �� �����:
void PutMoneyByOwnerCode(DebitCard DebitCard1, DebitCard DebitCard2, char* OCode, double Sum)
{
	if (strcmp(DebitCard1.get_OwnerCode(), OCode) == 0)
	{
		DebitCard1.PutMoney(DebitCard1, Sum);
		cout << "������ ��������, ��� ������ ����� ������ �� �����: " << DebitCard1.get_Balance() << " �.�." << endl;
	}
	else if (strcmp(DebitCard2.get_OwnerCode(), OCode) == 0)
	{
		DebitCard2.PutMoney(DebitCard2, Sum);
		cout << "������ ��������, ��� ������ ����� ������ �� �����: " << DebitCard2.get_Balance() << " �.�." << endl;
	}
	else
	{
		cout << "����� � ����� ����� ��������� �� ����������, �������� ����������!" << endl;
	}
}
//����������, � ����� �� ���� ���� ����� ������:
void WithdrawnCardDetector(bool DebitCardFlag1, bool DebitCardFlag2)
{
	if (DebitCardFlag1 && DebitCardFlag2)
	{
		cout << "�������� ������ ����� �� ����� ���� ����������� ��� ����� ����." << endl;
	}
	else if (DebitCardFlag1)
	{
		cout << "�������� ������ ����� �� ����� ���� ����������� ��� ������ �����." << endl;
	}
	else if (DebitCardFlag2)
	{
		cout << "�������� ������ ����� �� ����� ���� ����������� ��� ������ �����." << endl;
	}
	else
	{
		cout << "�������� ������ ����� �� ����� �� ������������� �� ��� ����� �� ����." << endl;
	}
}