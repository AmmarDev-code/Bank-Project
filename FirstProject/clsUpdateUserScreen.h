#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"


using namespace std;




class clsUpdateUserScreen : protected clsScreen
{
private:


	static void ReadUser(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadStirng();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadStirng();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadStirng();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadStirng();

		cout << "\nEnter PassWord: ";
		User.PassWord = clsInputValidate::ReadStirng();

		cout << "\nEnter Perimission: ";
		User.Perimission = _ReadPermissionToSet();

	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n__________________________\n";
		cout << "\nFirstName    : " << User.FirstName;
		cout << "\nLastName     : " << User.LastName;
		cout << "\nFul Name     : " << User.FullName();
		cout << "\nEmail        : " << User.Email;
		cout << "\nPhone        : " << User.Phone;
		cout << "\nUserName     : " << User.UserName;
		cout << "\nPassWord     : " << User.PassWord;
		cout << "\nPerimission  : " << User.Perimission;
		cout << "\n__________________________\n";


	}



	static int _ReadPermissionToSet()
	{
		int Permissions = 0;
		char Answer = 'n';

		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}
		return Permissions;
	}


public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\tUpdate User Info Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName : ";
		UserName = clsInputValidate::ReadStirng();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName  is not found, choose another one: ";
			UserName = clsInputValidate::ReadStirng();

		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		char Option = 'n';

		cout << "\nAre you sure do you want to update this User y/n? ";
		cin >> Option;


		if (Option == 'y' || Option == 'Y')
		{
			cout << "\nUpdate Client Info: ";

			cout << "\n___________________________\n";

			ReadUser(User);

			clsUser::enSaveResults SaveResult;

			SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResults::svSucceeded:
			{
				cout << "\nUserName Updated Successfuly :-)\n";
				_PrintUser(User);
				break;
			}
			case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError User was not saved because it's Empty ";
				break;

			}

			}
		}
	}



};

