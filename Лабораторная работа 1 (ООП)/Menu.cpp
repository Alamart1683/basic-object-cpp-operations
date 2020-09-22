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

		//������� 1:
		if (step == 1)
		{
			while (true)
			{
				Interface_Task1();
				Step_MinVariants = 1;
				Step_MaxVariants = 4;
				step = InputController(Step_MinVariants, Step_MaxVariants);

				//���� ������ ��� ����:
				if (step == 1)
				{
					Controller1 = 1;
					system("cls");
					cout << "���� ����� ������ ��� ����." << endl;
					cout << "���������� ����� �1:" << endl;
					cout << "===========================" << endl;
					InputBankCard(BankCard1);
					cout << "===========================" << endl;
					cout << "���������� ����� �2:" << endl;
					cout << "===========================" << endl;
					InputBankCard(BankCard2);
					cout << "===========================" << endl;
					cout << "���� ������ �������!" << endl;
					system("pause");
				}

				//�� ���� ������� ���� �������� �����:
				else if (step == 2)
				{
					if (Controller1 != 1)
					{
						system("cls");
						cout << "��� ������ ������� ������ ����! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						cout << "������� ��� ���������:" << endl;
						cin.ignore();
						cin.getline(TaskOwnerCode, 30);
						if (ValidityDefinedByCode(BankCard1, BankCard2, TaskOwnerCode) == 0)
						{
							system("cls");
							cout << "����� � ����� ����� ��������� �� ����������! " << endl;
							system("pause");
						}
						else
						{
							system("cls");
							cout << "����� ��������� �� " << ValidityDefinedByCode(BankCard1, BankCard2, TaskOwnerCode) << " ����." << endl;
							system("pause");
						}
					}
				}

				//�����������, ����� �� ��� ����� ���� ��������:
				else if (step == 3)
				{
					if (Controller1 == 0)
					{
						system("cls");
						cout << "��� ������ ������� ������ ����! " << endl;
						system("pause");
					}
					else
					{
						if (OneCardNameForTwoCardsDetector(BankCard1, BankCard2))
						{
							system("cls");
							cout << "��, ��� ����� ����� ����� ��������." << endl;
							system("pause");
						}
						else
						{
							system("cls");
							cout << "���, ��� ����� �� ����� ������ ��������." << endl;
							system("pause");
						}
					}
				}

				//��������� � ������ �������:
				else if (step == 4)
				{
					Controller1 = 0;
					step = 0;
					break;
				}
			}
		}

		/*____________________________________________________________________________________________________*/

		//������� 2:
		else if (step == 2)
		{
			while (true)
			{
				Interface_Task2();
				Step_MinVariants = 1;
				Step_MaxVariants = 6;
				step = InputController(Step_MinVariants, Step_MaxVariants);

				//���� ������ ��� ����:
				if (step == 1)
				{
					Controller2 = 1;
					system("cls");
					cout << "���� ����� ������ ��� ����." << endl;
					cout << "��������� ����� �1:" << endl;
					cout << "===========================" << endl;
					InputDebitCard(DebitCard1);
					cout << "===========================" << endl;
					cout << "��������� ����� �2:" << endl;
					cout << "===========================" << endl;
					InputDebitCard(DebitCard2);
					cout << "===========================" << endl;
					cout << "���� ������ �������!" << endl;
					system("pause");
				}

				//��������� ���� �����:
				else if (step == 2)
				{
					if (Controller2 != 1)
					{
						system("cls");
						cout << "��� ������ ������� ������ ����! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						cout << "���� ���������� �����." << endl;
						cout << "�������� ����� ��� ����������, 1 ��� 2:" << endl;
						sub_step = InputController(1, 2);
						if (sub_step == 1)
						{
							cout << "������� ����� ���������� (1...1000 �.�.):" << endl;
							Sum = BalanceController();
							DebitCard1.PutMoney(DebitCard1,Sum);
							system("pause");
						}
						else if (sub_step == 2)
						{
							cout << "������� ����� ���������� (1...1000 �.�.):" << endl;
							Sum = BalanceController();
							DebitCard2.PutMoney(DebitCard2, Sum);
							system("pause");
						}				
					}
				}

				//������� ������ �� ����� �����:
				else if (step == 3)
				{
					if (Controller2 != 1)
					{
						system("cls");
						cout << "��� ������ ������� ������ ����! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						cout << "���� �������� ����� �� �����." << endl;
						cout << "�������� ����� ��� �������� �����, 1 ��� 2:" << endl;
						sub_step = InputController(1, 2);
						if (sub_step == 1)
						{
							cout << "������� ����� �������� (1...1000 �.�.):" << endl;
							Sum = BalanceController();
							DebitCardFlag1 = DebitCard1.WithdrawMoney(DebitCard1, Sum);
							system("pause");
						}
						else if (sub_step == 2)
						{
							cout << "������� ����� �������� (1...1000 �.�.):" << endl;
							Sum = BalanceController();
							DebitCardFlag2 = DebitCard2.WithdrawMoney(DebitCard2, Sum);
							system("pause");
						}
					}
				}

				//�� ���� �������� ������ �� �����:
				else if (step == 4)
				{
					if (Controller2 != 1)
					{
						system("cls");
						cout << "��� ������ ������� ������ ����! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						cout << "���� ���������� �� ���� ���������." << endl;
						cout << "������� ����� ���������� (1...1000 �.�.):" << endl;
						Sum = BalanceController();
						cin.ignore();
						cout << "������� ��� ���������:" << endl;
						cin.getline(TaskOwnerCode, 30);
						PutMoneyByOwnerCode(DebitCard1, DebitCard2, TaskOwnerCode, Sum);
						system("pause");						
					}
				}

				//����������, � ����� �� ���� ���� ������� ������:
				else if (step == 5)
				{
					if (Controller2 != 1)
					{
						system("cls");
						cout << "��� ������ ������� ������ ����! " << endl;
						system("pause");
					}
					else
					{
						system("cls");
						WithdrawnCardDetector(DebitCardFlag1, DebitCardFlag2);
						system("pause");
					}
				}

				//��������� � ������ �������:
				else if (step == 6)
				{
					Controller2 = 0;
					step = 0;
					break;
				}
			}
		}

		/*____________________________________________________________________________________________________*/

		//����� �� ���������:
		else if (step == 3)
		{
			system("cls");
			cout << "����� �� ��������� �����������!" << endl;
			system("pause");
			break;
		}
	}
}

void Menu::Interface_Main()
{
	system("cls");
	cout << "������������ ������ �5: ������� 14" << endl;
	cout << "�������� ��������:" << endl;
	cout << "1. �������� ��� �������� ������� (������� 1);" << endl;
	cout << "2. �������� ��� �������-����������� (������� 2);" << endl;
	cout << "3. ����� �� ���������." << endl;
}

void Menu::Interface_Task1()
{
	system("cls");
	cout << "������� ���� �������� ��� �������� ������� (������� 1)." << endl;
	cout << "�������� ��������:" << endl;
	cout << "1. ������� ������ ��� ���������� ����." << endl;
	cout << "2. �� ���� ��������� ���������� � ������� ���� �������� �����." << endl;
	cout << "3. ����������, ����� �� ��� ����� ���� ��������." << endl;
	cout << "4. ��������� � ������ �������." << endl;
}

void Menu::Interface_Task2()
{
	system("cls");
	cout << "������� ���� �������� ��� �������� ������� (������� 1)." << endl;
	cout << "�������� ��������:" << endl;
	cout << "1. ������� ������ ��� ��������� ����." << endl;
	cout << "2. ��������� ���� �����." << endl;
	cout << "3. ����� ������ �� ����� �����." << endl;
	cout << "4. �� ���� �������� ������ �� �����." << endl;
	cout << "5. ����������, � ����� �� ���� ���� ������� ������." << endl;
	cout << "6. ��������� � ������ �������." << endl;
}

void Menu::InputBankCard(BankCard &BankCard)
{
	char CardName[30], Name[20], Surname[20], Patronymic[30], OwnerCode[30];
	unsigned int CardNumber, ValidityPeriod;
	double Balance;

	cout << "��� �����:" << endl;
	cin >> CardName;
	BankCard.set_CardName(CardName);

	cout << "����� �����:" << endl;
	CardNumber = InputController(0, 1000);
	BankCard.set_CardNumber(CardNumber);

	cout << "���� ��������:" << endl;
	ValidityPeriod = InputController(2018, 2100);
	BankCard.set_ValidityPeriod(ValidityPeriod);

	cout << "�������:" << endl;
	cin >> Surname;
	BankCard.set_Surname(Surname);

	cout << "���:" << endl;
	cin >> Name;
	BankCard.set_Name(Name);

	cout << "��������:" << endl;
	cin >> Patronymic;
	BankCard.set_Patronymic(Patronymic);

	cout << "��� ���������:" << endl;
	cin >> OwnerCode;
	BankCard.set_OwnerCode(OwnerCode);


	cout << "����������� ������ (1...1000):" << endl;
	Balance = BalanceController();
	BankCard.set_Balance(Balance);
}

void Menu::InputDebitCard(DebitCard &DebitCard)
{
	char PaySystemName[30], CardName[30], Name[20], Surname[20], Patronymic[30], OwnerCode[30];
	unsigned int CardNumber, ValidityPeriod;
	double Balance;

	cout << "�������� ��������� �������:" << endl;
	cin >> PaySystemName;
	DebitCard.set_PaySystemName(PaySystemName);

	cout << "��� �����:" << endl;
	cin >> CardName;
	DebitCard.set_CardName(CardName);

	cout << "����� �����:" << endl;
	CardNumber = InputController(0, 1000);
	DebitCard.set_CardNumber(CardNumber);

	cout << "���� ��������:" << endl;
	ValidityPeriod = InputController(2018, 2100);
	DebitCard.set_ValidityPeriod(ValidityPeriod);

	cout << "�������:" << endl;
	cin >> Surname;
	DebitCard.set_Surname(Surname);

	cout << "���:" << endl;
	cin >> Name;
	DebitCard.set_Name(Name);

	cout << "��������:" << endl;
	cin >> Patronymic;
	DebitCard.set_Patronymic(Patronymic);

	cout << "��� ���������:" << endl;
	cin >> OwnerCode;
	DebitCard.set_OwnerCode(OwnerCode);


	cout << "����������� ������ (1...1000):" << endl;
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
		cout << "�� ����� ������������ ��������!" << endl;
		cout << "��������� ����." << endl;
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
		cout << "����� ��� ����������/c����� ����� �� 1 �� 1000 �.�.!" << endl;
		cout << "��������� ����." << endl;
	}
	return Input_Value;
}

