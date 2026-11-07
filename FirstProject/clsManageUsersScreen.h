#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsTransactionScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:

    enum enManageUsersMenueOptions
    {
        eListUsers = 1, eAddNewUser = 2,
        eDeleteUser = 3, eUpdateUser = 4,
        eFindUser = 5, eMainMenue = 6
    };

    static void _GoBackToManageUsersMenue()
    {
        cout << "\nPress any key to go back to Main Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void  _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersist();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOptions)
    {
        switch (ManageUsersMenueOptions)
        {
        case enManageUsersMenueOptions::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;

        case enManageUsersMenueOptions::eAddNewUser:
            system("cls");
              _ShowAddNewUserScreen();
              _GoBackToManageUsersMenue();
            break;

        case enManageUsersMenueOptions::eDeleteUser:
              system("cls");
              _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case enManageUsersMenueOptions::eUpdateUser:
            system("cls");
             _ShowUpdateUserScreen();
             _GoBackToManageUsersMenue();
            break;

        case enManageUsersMenueOptions::eFindUser:
            system("cls");
             _ShowFindUserScreen();
             _GoBackToManageUsersMenue();
            break;

            // case enMainMenueOptions::eShowTransactionMuen:
            system("cls");
            // ShowTransactionScreen();
            break;

            // case enMainMenueOptions::enManageUsers:
            system("cls");
            // ShowMainMenue();
            break;

            // case enMainMenueOptions::eExit:
            system("cls");
            // Login();
            break;
        }

    }


    static short ReadManageUsersMenueOptions()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choise = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 to 6? ");
        return Choise;
    }

public:

    static  void ShowManageUsersMenue()
    {


        if (!CheckAccessRirhts(clsUser::enPermissions::pManageUsers))
        {

            return;
        }



        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menu Screen\n";
        cout << setw(37) << left << "" << "============================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "=============================================\n";
        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOptions());

    }

};




