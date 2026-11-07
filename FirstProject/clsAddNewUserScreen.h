#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"



using namespace std;

class clsAddNewUserScreen : protected clsScreen
{


	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n__________________________\n";
		cout << "\nUserName      : " << User.UserName;
		cout << "\nFullName      : " << User.FullName();
		cout << "\nPhone         : " << User.Phone;
		cout << "\nEmail         : " << User.Email;
		cout << "\nPassWord      : " << User.PassWord;
		cout << "\nPerimission   : " << User.Perimission;
		cout << "\n__________________________\n";


	}

private:

	static 	void _ReadUserInfo(clsUser& User)
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

	static void ShowAddNewUserScreen()
	{



		_DrawScreenHeader("\t   Add New User Scrren ");

		string UserName = "";

		cout << "\nPlease Enter User Name: ";
		UserName = clsInputValidate::ReadStirng();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is Already Used, choose another one: ";
			UserName = clsInputValidate::ReadStirng();
		}


		clsUser User = clsUser::GetAddNewUser(UserName);

		_ReadUserInfo(User);


		clsUser::enSaveResults Result;

		Result = User.Save();

		switch (Result)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\n________________________\n";
			cout << "\User Added Succefuly :-)";
			cout << "\n__________________________\n\n";
			_PrintUser(User);

		}

		}
	}

};

