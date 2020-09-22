#pragma once
#include "BankCard.h"
#include "DebitCard.h"


class Menu
{
public:
	Menu();
	~Menu();
	void Show_Menu();
	void Interface_Main();
	void Interface_Task1();
	void Interface_Task2();
	void InputBankCard(BankCard &BankCard);
	void InputDebitCard(DebitCard &DebitCard);
	int InputController(int Min_Variants, int Max_Variants);
	double Menu::BalanceController();
private:
	int step;
	int sub_step;
	bool DebitCardFlag1 = false;
	bool DebitCardFlag2 = false;
	int Controller1 = 0;
	int Controller2 = 0;
	double Sum;
	char TaskOwnerCode[30];
	BankCard BankCard1;
	BankCard BankCard2;
	DebitCard DebitCard1;
	DebitCard DebitCard2;
};

