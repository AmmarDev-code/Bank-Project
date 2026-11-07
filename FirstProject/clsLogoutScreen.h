#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsLoginScreen.h"
#include "Global.h"


using namespace std;

class clsLogoutScreen : protected clsScreen
{


private:

	static void _GoBackToMainMenue()
	{
		cout << "\npress any key to go back to main menue...";
		system("pause>0");
		//clsLoginScreen::ShowLoginScreen();
	}



public:

	static void ShowLogotScreen()
	{
		clsScreen::_DrawScreenHeader("\t Show Logout Screen");


		CurrentUser.UserName = "";
		CurrentUser.PassWord = "";

		_GoBackToMainMenue();

	}


};

