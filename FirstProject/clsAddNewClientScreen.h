#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"



using namespace std;


class clsAddNewClientScreen : protected clsScreen
{

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

private:

	static 	void _ReadClientInfo(clsBankClient& Client)
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

public:

	static void ShowAddNewClientScreen()
	{
		
		if (!CheckAccessRirhts(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		
		_DrawScreenHeader("\t   Add New Client Scrren ");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadStirng();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is Already Used, choose another one: ";
			AccountNumber = clsInputValidate::ReadStirng();
		}


		clsBankClient Client = clsBankClient::GetAddNewClient(AccountNumber);

		_ReadClientInfo(Client);



		clsBankClient::enSaveResults Result;

		Result = Client.Save();

		switch (Result)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\n________________________\n";
			cout << "\nClient Added Succefuly :-)";
			cout << "\n__________________________\n\n";
			_Print(Client);

		}

		}
	}

	};