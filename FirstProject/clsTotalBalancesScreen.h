#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsString.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{

private:
    static void PrinClientRecordLine(clsBankClient Client)
    {
        cout << setw(15) << left << "" << "| " << setw(16) << left << Client.AccountNumber();
        cout << "| " << left << setw(55) << Client.FullName();
        cout << "| " << left << setw(8) << Client.AccountBalance;

    }

public:

    static void ShowTotalBalnces()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientList();

        string Title = "\tClient List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s).";
        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t___________________________________________________________";
        cout << "____________________________________________\n\n";

        cout << setw(15) << left << "" << "| " << left << setw(16) << "Account Number";
        cout << "| " << left << setw(55) << "Client Name";
        cout << "| " << left << setw(8) << "Balance";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalnces = clsBankClient::GetTotalBalances();

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

        cout <<"\n\t\t\t\t\t Total Balnces = " << TotalBalnces << endl;
        cout << "\t\t\t\t ( " <<  clsString::NumberToText(TotalBalnces) << " )\n";


    }


};

