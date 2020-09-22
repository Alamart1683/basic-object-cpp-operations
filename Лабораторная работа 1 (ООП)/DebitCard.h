#pragma once
#include "BankCard.h"
class DebitCard :
	public BankCard
{
private:
	char PaySystemName[30];
public:
	//����������� � �����������:
	DebitCard(char* CName, unsigned int CNumber, unsigned int VPeriod, char* Sur, char* Nam, char* Pat, char* OCode, double Bal):BankCard(CName, CNumber, VPeriod, Sur, Nam, Pat, OCode, Bal)
	{
		strcpy_s(PaySystemName, "");
	}
	//����������� ��� ����������:
	DebitCard()
	{
		strcpy_s(PaySystemName, "");
	}

	//������ �����������:
	//Set:
	void set_PaySystemName(char* PSN)
	{
		strcpy_s(PaySystemName, PSN);
	}
	//Get:
	char* get_PaySystemName()
	{
		return PaySystemName;
	}

	//�������� ��������:
	//�������� ������:
	void PutMoney(DebitCard DebitCard, double Sum);
	//����� ������
	bool WithdrawMoney(DebitCard DebitCard, double Sum);
};

