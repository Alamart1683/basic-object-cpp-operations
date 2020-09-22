#pragma once
#include "iostream"
using namespace std;


class BankCard
{
private:
	//Поля
	char CardName[30];
	unsigned int CardNumber;
	unsigned int ValidityPeriod;
	char Surname[20];
	char Name[20];
	char Patronymic[30];
	char OwnerCode[30];
	double Balance;
public:
	//Конструктор без параметров:
	BankCard()
	{
		strcpy_s(CardName, "");
		CardNumber = 0;
		ValidityPeriod = 0;
		strcpy_s(Surname, "");
		strcpy_s(Name, "");
		strcpy_s(Patronymic, "");
		strcpy_s(OwnerCode, "");
		Balance = 0;
	}
	//Конструктор с параметрами:
	BankCard(char* CName, unsigned int CNumber, unsigned int VPeriod, char* Sur, char* Nam, char* Pat, char* OCode, double Bal)
	{
		strcpy_s(CardName, CName);
		CardNumber = CNumber;
		ValidityPeriod = VPeriod;
		strcpy_s(Surname, Sur);
		strcpy_s(Name, Nam);
		strcpy_s(Patronymic, Pat);
		strcpy_s(OwnerCode, OCode);
		Balance = Bal;
	}
	//Деструктор:
	~BankCard()
	{
		
	}
	//Методы модификации:
	//Set:
	void set_CardName(char* CName)
	{
		strcpy_s(CardName, CName);
	}
	void set_CardNumber(unsigned int CNumber)
	{
		CardNumber = CNumber;
	}
	void set_ValidityPeriod(unsigned int VPeriod)
	{
		ValidityPeriod = VPeriod;
	}
	void set_Surname(char* Sur)
	{
		strcpy_s(Surname, Sur);
	}
	void set_Name(char* Nam)
	{
		strcpy_s(Name, Nam);
	}
	void set_Patronymic(char* Pat)
	{
		strcpy_s(Patronymic, Pat);
	}
	void set_OwnerCode(char* OCode)
	{
		strcpy_s(OwnerCode, OCode);
	}
	void set_Balance(double Bal)
	{
		Balance += Bal;
	}
	//Get:
	char* get_CardName()
	{
		return CardName;
	}
	unsigned int get_CardNumber()
	{
		return CardNumber;
	}
	unsigned int get_ValidityPeriod()
	{
		return ValidityPeriod;
	}
	char* get_Surname()
	{
		return Surname;
	}
	char* get_Name()
	{
		return Name;
	}
	char* get_Patronymic()
	{
		return Patronymic;
	}
	char* get_OwnerCode()
	{
		return OwnerCode;
	}
	double get_Balance()
	{
		return Balance;
	}	
};

