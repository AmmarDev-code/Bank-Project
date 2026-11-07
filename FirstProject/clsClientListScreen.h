#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"


using namespace std;



class clsClientListScreen : protected clsScreen
{

private:
    static void PrinClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(14) << left << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) <<  Client.Phone;
        cout << "| " << left << setw(20) << Client.Email;
        cout << "| " << left << setw(10) << Client.PinCode;
        cout << "| " << left << setw(12) << Client.AccountBalance;

    }

public:

    static void ShowClientsist()
    {

        if (!CheckAccessRirhts(clsUser::enPermissions::pListClients))
        {
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientList();

        string Title = "\tClient List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";
        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t___________________________________________________________";
        cout << "____________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(14) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
        {
            cout << "\t\t\t\t\tClient List is not Availble\n";

        }

        else
        {

            for (clsBankClient Client : vClients)
            {
                PrinClientRecordLine(Client);
                cout << endl;
            }
            cout << setw(8) << left << "" << "\n\t____________________________________________________________________";
                cout << "___________________________________\n";
        }


    }





};

