#pragma once


#include <iostream>
#include "clsBankClient.h"
#include <iomanip>
#include <vector>
#include "Global.h"
#include "clsDate.h"


using namespace std;


class clsScreen 
{
public:

	static void  _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		cout << "\n\t\t\t\t\t User: " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\t Date: " << clsDate::DateToString(clsDate()) << "\n\n";
	}

	static bool CheckAccessRirhts(clsUser::enPermissions Perimission)
	{

		if (!CurrentUser.CheckAccessPermission(Perimission))
		{
			cout << "\t\t\t\t\t____________________________________________________________";
			cout << "\n\n\t\t\t\t\t   Access Denied! Contact your Admin";
			cout << "\n\t\t\t\t\t___________________________________________________________\n";
			return false;

		}
		else
		{
			return true;
		}

	}


	

	

};

