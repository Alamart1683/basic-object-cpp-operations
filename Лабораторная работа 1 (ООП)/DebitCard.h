#pragma once
#include "BankCard.h"
class DebitCard :
	public BankCard
{
private:
	char PaySystemName[30];
public:
	//Конструктор с параметрами:
	DebitCard(char* CName, unsigned int CNumber, unsigned int VPeriod, char* Sur, char* Nam, char* Pat, char* OCode, double Bal):BankCard(CName, CNumber, VPeriod, Sur, Nam, Pat, OCode, Bal)
	{
		strcpy_s(PaySystemName, "");
	}
	//Конструктор без параметров:
	DebitCard()
	{
		strcpy_s(PaySystemName, "");
	}

	//Методы модификации:
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

	//Основные операции:
	//Положить деньги:
	void PutMoney(DebitCard DebitCard, double Sum);
	//Снять деньги
	bool WithdrawMoney(DebitCard DebitCard, double Sum);
};

