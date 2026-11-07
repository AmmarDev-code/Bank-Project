#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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


	static void ShowFindClientScreen()
	{


		if (!CheckAccessRirhts(clsUser::enPermissions::pFindClient))
		{
			return;
		}



		string AccountNumber = "";

		_DrawScreenHeader("\tFind Client Screen");

			cout << "\nPlease Enter Account Number: ";
			AccountNumber = clsInputValidate::ReadStirng();


			while (!clsBankClient::IsClientExist(AccountNumber))
			{

				cout << "\nAccount Number is not found, choose another one: ";
				AccountNumber = clsInputValidate::ReadStirng();
			}



		clsBankClient Client = clsBankClient::Find(AccountNumber);


		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}

		else
		{
			cout << "\nClient was not Found :-(\n";
		}
		_Print(Client);

		


	}


};

