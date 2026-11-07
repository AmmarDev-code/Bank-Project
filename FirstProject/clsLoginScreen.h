#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsLoginRegister.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{


private:

	static bool _Login()
	{

		bool LoginFaild  = false;
		int FaildLoginCount = 0;

		string UserName, PassWord;
		do
		{
			
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvalid UserName/PassWord!\n";
				cout << "You have " <<  (3 - FaildLoginCount) << " Trial(s) to login.\n\n";
				
			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYou are  Locked after 3 faild trails \n\n";
				return false;

			}

			cout << "Enter UserName? ";
			cin >> UserName;

			cout << "Enter PassWord? ";
			cin >> PassWord;


			CurrentUser = clsUser::Find(UserName, PassWord);

			LoginFaild = CurrentUser.IsEmpty();

		


		} while (LoginFaild);
		
		clsLoginRegister::SaveDataToFile();
		clsMainScreen::ShowMainMenue();
		

	}



public:

	static bool ShowLoginScreen()
	{

		system("cls");
		clsScreen::_DrawScreenHeader("\t Login Screen");
		return _Login();

	}





};

