#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


using namespace std;

class clsUpdateClientScreen : protected clsScreen
{

private:

	static void ReadClient(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadStirng();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadStirng();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadStirng();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadStirng();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadStirng();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}

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

	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRirhts(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}



		_DrawScreenHeader("\tUpdate Client Info Screen");
		


		string AccountNumber = "";

		cout << "\nPlease Enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadStirng();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadStirng();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		char Option = 'n';

		cout << "\nAre you sure do you want to update this client y/n? ";
		cin >> Option;


		if (Option == 'y' || Option == 'Y')
		{
			cout << "\nUpdate Client Info: ";

			cout << "\n___________________________\n";

			ReadClient(Client);

			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\nAccount Updated Successfuly :-)\n";
				_Print(Client);
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty ";
				break;

			}

			}
		}
	}


};

