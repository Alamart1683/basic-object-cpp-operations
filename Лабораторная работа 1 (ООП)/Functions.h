#pragma once
#include"BankCard.h"
#include"DebitCard.h"

//Дополнительные операции основного класса BankCard:

//Вернуть срок действия карты по коду владельца:
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

//Опеределить, имеют ли две карты одно название:
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

//Дополнительные операции класса-наследника DebitCard:

//По коду владельца положить деньги на карту:
void PutMoneyByOwnerCode(DebitCard DebitCard1, DebitCard DebitCard2, char* OCode, double Sum)
{
	if (strcmp(DebitCard1.get_OwnerCode(), OCode) == 0)
	{
		DebitCard1.PutMoney(DebitCard1, Sum);
		cout << "Баланс пополнен, для первой карты теперь он равен: " << DebitCard1.get_Balance() << " у.е." << endl;
	}
	else if (strcmp(DebitCard2.get_OwnerCode(), OCode) == 0)
	{
		DebitCard2.PutMoney(DebitCard2, Sum);
		cout << "Баланс пополнен, для второй карты теперь он равен: " << DebitCard2.get_Balance() << " у.е." << endl;
	}
	else
	{
		cout << "Карты с таким кодом владельца не существует, операция невозможна!" << endl;
	}
}
//Определить, с какой из карт были сняты деньги:
void WithdrawnCardDetector(bool DebitCardFlag1, bool DebitCardFlag2)
{
	if (DebitCardFlag1 && DebitCardFlag2)
	{
		cout << "Операция снятия денег со счёта была произведена для обеих карт." << endl;
	}
	else if (DebitCardFlag1)
	{
		cout << "Операция снятия денег со счёта была произведена для первой карты." << endl;
	}
	else if (DebitCardFlag2)
	{
		cout << "Операция снятия денег со счёта была произведена для второй карты." << endl;
	}
	else
	{
		cout << "Операция снятия денег со счёта не производилась ни для одной из карт." << endl;
	}
}