#include "stdafx.h"
#include "Menu.h"
#include "Functions.h"

Menu::Menu()
{
	setlocale(LC_ALL, "rus");
}

Menu::~Menu()
{

}

void Menu::Show_Menu()
{
	while (true)
	{
		Interface_Main();
		int Step_MinVariants = 1;
		int Step_MaxVariants = 3;
		step = InputController(Step_MinVariants, Step_MaxVariants);

		/*____________________________________________________________________________________________________*/

		//Задание 1:
		if (step == 1)
		{
			while (true)
			{
				Interface_Task1();
				Step_MinVariants = 1;
				Step_MaxVariants = 4;
				step = InputController(Step_MinVariants, Step_MaxVariants);

				//Ввод данных для карт:
				if (step == 1)
				{
					Controller1 = 1;
					system("cls");
					cout << "Меню ввода данных для карт." << endl;
					cout << "Банковская карта №1:" << endl;
					cout << "===========================" << endl;
					InputBankCard(BankCard1);
					cout << "===========================" << endl;
					cout << "Банковская карта №2:" << endl;
					cout << "===========================" << endl;
					InputBankCard(BankCard2);
					cout << "===========================" << endl;
					cout << "Ввод данных окончен!" << endl;
					system("pause");
				}

				//По коду вернуть срок действия карты:
				else if (step == 2)
				{
					if (Controller1 != 1)
					{
						system("cls");
						cout << "Для начала введите данные карт! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						cout << "Введите код владельца:" << endl;
						cin.ignore();
						cin.getline(TaskOwnerCode, 30);
						if (ValidityDefinedByCode(BankCard1, BankCard2, TaskOwnerCode) == 0)
						{
							system("cls");
							cout << "Карты с таким кодом владельца не существует! " << endl;
							system("pause");
						}
						else
						{
							system("cls");
							cout << "Карта действует до " << ValidityDefinedByCode(BankCard1, BankCard2, TaskOwnerCode) << " года." << endl;
							system("pause");
						}
					}
				}

				//Опеределить, имеют ли две карты одно название:
				else if (step == 3)
				{
					if (Controller1 == 0)
					{
						system("cls");
						cout << "Для начала введите данные карт! " << endl;
						system("pause");
					}
					else
					{
						if (OneCardNameForTwoCardsDetector(BankCard1, BankCard2))
						{
							system("cls");
							cout << "Да, эти карты имеют общее название." << endl;
							system("pause");
						}
						else
						{
							system("cls");
							cout << "Нет, эти карты не имеют общего названия." << endl;
							system("pause");
						}
					}
				}

				//Вернуться к выбору задания:
				else if (step == 4)
				{
					Controller1 = 0;
					step = 0;
					break;
				}
			}
		}

		/*____________________________________________________________________________________________________*/

		//Задание 2:
		else if (step == 2)
		{
			while (true)
			{
				Interface_Task2();
				Step_MinVariants = 1;
				Step_MaxVariants = 6;
				step = InputController(Step_MinVariants, Step_MaxVariants);

				//Ввод данных для карт:
				if (step == 1)
				{
					Controller2 = 1;
					system("cls");
					cout << "Меню ввода данных для карт." << endl;
					cout << "Дебетовая карта №1:" << endl;
					cout << "===========================" << endl;
					InputDebitCard(DebitCard1);
					cout << "===========================" << endl;
					cout << "Дебетовая карта №2:" << endl;
					cout << "===========================" << endl;
					InputDebitCard(DebitCard2);
					cout << "===========================" << endl;
					cout << "Ввод данных окончен!" << endl;
					system("pause");
				}

				//Пополнить счет карты:
				else if (step == 2)
				{
					if (Controller2 != 1)
					{
						system("cls");
						cout << "Для начала введите данные карт! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						cout << "Меню пополнения счёта." << endl;
						cout << "Выберите карту для пополнения, 1 или 2:" << endl;
						sub_step = InputController(1, 2);
						if (sub_step == 1)
						{
							cout << "Введите сумму пополнения (1...1000 у.е.):" << endl;
							Sum = BalanceController();
							DebitCard1.PutMoney(DebitCard1,Sum);
							system("pause");
						}
						else if (sub_step == 2)
						{
							cout << "Введите сумму пополнения (1...1000 у.е.):" << endl;
							Sum = BalanceController();
							DebitCard2.PutMoney(DebitCard2, Sum);
							system("pause");
						}				
					}
				}

				//Списать деньги со счета карты:
				else if (step == 3)
				{
					if (Controller2 != 1)
					{
						system("cls");
						cout << "Для начала введите данные карт! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						cout << "Меню списания денег со счёта." << endl;
						cout << "Выберите карту для списания денег, 1 или 2:" << endl;
						sub_step = InputController(1, 2);
						if (sub_step == 1)
						{
							cout << "Введите сумму списания (1...1000 у.е.):" << endl;
							Sum = BalanceController();
							DebitCardFlag1 = DebitCard1.WithdrawMoney(DebitCard1, Sum);
							system("pause");
						}
						else if (sub_step == 2)
						{
							cout << "Введите сумму списания (1...1000 у.е.):" << endl;
							Sum = BalanceController();
							DebitCardFlag2 = DebitCard2.WithdrawMoney(DebitCard2, Sum);
							system("pause");
						}
					}
				}

				//По коду положить деньги на карту:
				else if (step == 4)
				{
					if (Controller2 != 1)
					{
						system("cls");
						cout << "Для начала введите данные карт! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						cout << "Меню пополнения по коду владельца." << endl;
						cout << "Введите сумму пополнения (1...1000 у.е.):" << endl;
						Sum = BalanceController();
						cin.ignore();
						cout << "Введите код владельца:" << endl;
						cin.getline(TaskOwnerCode, 30);
						PutMoneyByOwnerCode(DebitCard1, DebitCard2, TaskOwnerCode, Sum);
						system("pause");						
					}
				}

				//Определить, с какой из карт были списаны деньги:
				else if (step == 5)
				{
					if (Controller2 != 1)
					{
						system("cls");
						cout << "Для начала введите данные карт! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						WithdrawnCardDetector(DebitCardFlag1, DebitCardFlag2);
						system("pause");
					}
				}

				//Вернуться к выбору задания:
				else if (step == 6)
				{
					Controller2 = 0;
					step = 0;
					break;
				}
			}
		}

		/*____________________________________________________________________________________________________*/

		//Выход из программы:
		else if (step == 3)
		{
			system("cls");
			cout << "Выход из программы осуществлен!" << endl;
			system("pause");
			break;
		}
	}
}

void Menu::Interface_Main()
{
	system("cls");
	cout << "Лабораторная работа №5: Вариант 14" << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Операции над основным классом (Задание 1);" << endl;
	cout << "2. Операции над классом-наследником (Задание 2);" << endl;
	cout << "3. Выход из программы." << endl;
}

void Menu::Interface_Task1()
{
	system("cls");
	cout << "Выбрано меню операций над основным классом (Задание 1)." << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Указать данные для банковских карт." << endl;
	cout << "2. По коду владельца определить и вернуть срок действия карты." << endl;
	cout << "3. Определить, имеют ли две карты одно название." << endl;
	cout << "4. Вернуться к выбору задания." << endl;
}

void Menu::Interface_Task2()
{
	system("cls");
	cout << "Выбрано меню операций над основным классом (Задание 1)." << endl;
	cout << "Выберите действие:" << endl;
	cout << "1. Указать данные для дебетовых карт." << endl;
	cout << "2. Пополнить счёт карты." << endl;
	cout << "3. Снять деньги со счёта карты." << endl;
	cout << "4. По коду положить деньги на карту." << endl;
	cout << "5. Определить, с какой из карт были списаны деньги." << endl;
	cout << "6. Вернуться к выбору задания." << endl;
}

void Menu::InputBankCard(BankCard &BankCard)
{
	char CardName[30], Name[20], Surname[20], Patronymic[30], OwnerCode[30];
	unsigned int CardNumber, ValidityPeriod;
	double Balance;

	cout << "Имя карты:" << endl;
	cin >> CardName;
	BankCard.set_CardName(CardName);

	cout << "Номер карты:" << endl;
	CardNumber = InputController(0, 1000);
	BankCard.set_CardNumber(CardNumber);

	cout << "Срок действия:" << endl;
	ValidityPeriod = InputController(2018, 2100);
	BankCard.set_ValidityPeriod(ValidityPeriod);

	cout << "Фамилия:" << endl;
	cin >> Surname;
	BankCard.set_Surname(Surname);

	cout << "Имя:" << endl;
	cin >> Name;
	BankCard.set_Name(Name);

	cout << "Отчество:" << endl;
	cin >> Patronymic;
	BankCard.set_Patronymic(Patronymic);

	cout << "Код владельца:" << endl;
	cin >> OwnerCode;
	BankCard.set_OwnerCode(OwnerCode);


	cout << "Изначальный баланс (1...1000):" << endl;
	Balance = BalanceController();
	BankCard.set_Balance(Balance);
}

void Menu::InputDebitCard(DebitCard &DebitCard)
{
	char PaySystemName[30], CardName[30], Name[20], Surname[20], Patronymic[30], OwnerCode[30];
	unsigned int CardNumber, ValidityPeriod;
	double Balance;

	cout << "Название платежной системы:" << endl;
	cin >> PaySystemName;
	DebitCard.set_PaySystemName(PaySystemName);

	cout << "Имя карты:" << endl;
	cin >> CardName;
	DebitCard.set_CardName(CardName);

	cout << "Номер карты:" << endl;
	CardNumber = InputController(0, 1000);
	DebitCard.set_CardNumber(CardNumber);

	cout << "Срок действия:" << endl;
	ValidityPeriod = InputController(2018, 2100);
	DebitCard.set_ValidityPeriod(ValidityPeriod);

	cout << "Фамилия:" << endl;
	cin >> Surname;
	DebitCard.set_Surname(Surname);

	cout << "Имя:" << endl;
	cin >> Name;
	DebitCard.set_Name(Name);

	cout << "Отчество:" << endl;
	cin >> Patronymic;
	DebitCard.set_Patronymic(Patronymic);

	cout << "Код владельца:" << endl;
	cin >> OwnerCode;
	DebitCard.set_OwnerCode(OwnerCode);


	cout << "Изначальный баланс (1...1000):" << endl;
	Balance = BalanceController();
	DebitCard.set_Balance(Balance);
}

int Menu::InputController(int Min_Variants, int Max_Variants)
{
	int Input_Value;
	while (!(cin >> Input_Value) || Input_Value < Min_Variants || Input_Value > Max_Variants)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Вы ввели некорректное значение!" << endl;
		cout << "Повторите ввод." << endl;
	}
	return Input_Value;
}

double Menu::BalanceController() 
{
	double Input_Value;
	while (!(cin >> Input_Value) || Input_Value < 1 || Input_Value > 1000)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Сумма для пополнения/cнятия лежит от 1 до 1000 у.е.!" << endl;
		cout << "Повторите ввод." << endl;
	}
	return Input_Value;
}

