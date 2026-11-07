#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"


using namespace std;


class clsFindUserScreen : protected clsScreen
{

private:


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
		cout << "\nPerimissions : " << User.Perimission;
		cout << "\n__________________________\n";


	}


public:


	static void ShowFindUserScreen()
	{
		string UserName = "";

		_DrawScreenHeader("\tFind User Screen");

		cout << "\nPlease UserName Number: ";
		UserName = clsInputValidate::ReadStirng();


		while (!clsUser::IsUserExist(UserName))
		{

			cout << "\nUserName is not found, choose another one: ";
			UserName = clsInputValidate::ReadStirng();
		}



		clsUser User = clsUser::Find(UserName);


		if (!User.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}

		else
		{
			cout << "\nUser was not Found :-(\n";
		}
		_PrintUser(User);




	}



};

