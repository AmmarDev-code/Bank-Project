#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{

	static void _PrintUser(clsUser User)
	{
		cout << "\User Card:";
		cout << "\n__________________________\n";
		cout << "\UserName      : " << User.UserName;
		cout << "\nFirstName    : " << User.FirstName;
		cout << "\nLastName     : " << User.LastName;
		cout << "\nFul Name     : " << User.FullName();
		cout << "\nEmail        : " << User.Email;
		cout << "\nPhone        : " << User.Phone;
		cout << "\nPassWord     : " << User.PassWord;
		cout << "\nPerimission  : " << User.Perimission;
		cout << "\n__________________________\n";


	}

public:


	static void ShowDeleteUserScreen()
	{


		_DrawScreenHeader("\t Delete User Screen");

		string UserName = "";

		cout << "Please Enter UserName: ";
		UserName = clsInputValidate::ReadStirng();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not Exists, Try another one: ";
			UserName = clsInputValidate::ReadStirng();
		}


		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "\nAre you sure you want to delete this User y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			if (User.Delete())
			{

				cout << "\n User Deleted succeessfult :-)\n";
				_PrintUser(User);

			}	

		}
		else
		{
			cout << "\nError User was not Deleted\n";
		}



	}









};

