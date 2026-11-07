#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "clsPerson.h";
#include <fstream>
#include <iomanip>
#include "clsUtil.h";
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
using namespace std;


class clsTransactionScreen : protected clsScreen
{

private:

	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithDraw = 2, eShowTotalBalances = 3,
		eShowMainMenue = 4};

	static void _GoBackToTransactionsMenue()
	{
		//system("cls");
		cout << "\n\nPress any key to go to Main Menue...";
		system("pause>0");
		ShowTransactionsMainMenue();

	}

	

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
		
	}

	static void _ShowWithDrawScreen()
	{
		clsWithDrawScreen::ShowWithDrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalnces();

	}

	static void _ShowTraMainMenueScreen()
	{
		//clsMainScreen::ShowMainMenue();
		

	}

	static void _PerformTransactionsMainMenueOption(enTransactionsMenueOptions TransactionsMenueOptions)
	{
		switch (TransactionsMenueOptions)
		{
			case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();

		}
		case enTransactionsMenueOptions::eWithDraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowMainMenue:
		{

		}
	

		}
	}

	static short ReadTransactionOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number Between 1 to 4? ");
		return Choise;
	}


public:

	static void ShowTransactionsMainMenue()
	{

		if (!CheckAccessRirhts(clsUser::enPermissions::pTranactions))
		{
			return;
		}


		system("cls");
		_DrawScreenHeader("\t\Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";
		_PerformTransactionsMainMenueOption(enTransactionsMenueOptions(ReadTransactionOptions()));


	}


};

