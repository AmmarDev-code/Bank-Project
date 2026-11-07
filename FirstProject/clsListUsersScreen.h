#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"




using namespace std;




class clsListUsersScreen : protected clsScreen
{


private:
    static void PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << setw(14) << left << User.UserName;
        cout << "| " << left << setw(20) << User.FullName();
        cout << "| " << left << setw(12) << User.Phone;
        cout << "| " << left << setw(20) << User.Email;
        cout << "| " << left << setw(10) << User.PassWord;
        cout << "| " << left << setw(12) << User.Perimission;

    }

public:

    static void ShowUsersist()
    {
        vector <clsUser> vUsers = clsUser::GetUserList();

        string Title = "\tUser List Screen";
        string SubTitle = "\t   (" + to_string(vUsers.size()) + ") User(s).";
        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t___________________________________________________________";
        cout << "____________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(14) << "UserName";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "PassWord";
        cout << "| " << left << setw(12) << "Perimissions";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\t\tUser List is not Availble\n";

        }

        else
        {

            for (clsUser User : vUsers)
            {
                PrintUserRecordLine(User);
                cout << endl;
            }
            cout << setw(8) << left << "" << "\n\t____________________________________________________________________";
            cout << "___________________________________\n";
        }


    }





};

