#include "stdafx.h"
#include "DebitCard.h"
//Основные операции:
//Положить деньги:
void DebitCard::PutMoney(DebitCard DebitCard, double Sum)
{
	DebitCard.set_Balance(Sum);
	cout << "Баланс пополнен, теперь он равен: " << DebitCard.get_Balance() << " у.е." << endl;
}
//Снять деньги:
bool DebitCard::WithdrawMoney(DebitCard DebitCard, double Sum)
{
	DebitCard.set_Balance(-Sum);
	cout << "Деньги списаны со счёта, теперь он равен: " << DebitCard.get_Balance() << " у.е." << endl;
	return true;
}
