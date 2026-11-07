#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"
 
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{

private:
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n__________________________\n";
		cout << "\nFirstName    : " << Client.FirstName;
		cout << "\nLastName     : " << Client.LastName;
		cout << "\nFul Name     : " << Client.FullName();
		cout << "\nEmail        : " << Client.Email;
		cout << "\nPhone        : " << Client.Phone;
		cout << "\nAcc. Number  : " << Client.AccountNumber();
		cout << "\nPassWord     : " << Client.PinCode;
		cout << "\nBalance      : " << Client.AccountBalance;
		cout << "\n__________________________\n";


	}

public:

	

	static void ShowDeleteClientScreen()
	{


		if (!CheckAccessRirhts(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}


		_DrawScreenHeader("\t Delete Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Nmuber: ";
		AccountNumber = clsInputValidate::ReadStirng();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not Exists, Try another one: ";
			AccountNumber = clsInputValidate::ReadStirng();
		}


		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		cout << "\nAre you sure you want to delete this client y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			if (Client.Delete())
			{

				cout << "\n Client Deleted succeessfult :-)\n";
				_Print(Client);

			}

		
		}
		else
		{
			cout << "\nError Client was not Deleted\n";
		}



	}



	






};

