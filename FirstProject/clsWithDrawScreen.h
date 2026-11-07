#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


using namespace std;


class clsWithDrawScreen : protected clsScreen
{

    static string _ReadAccountNumber()
    {
        string AccountNumber;

        cout << "\nPlease Enter AccountNumber: ";
        cin >> AccountNumber;
        return AccountNumber;
    }

private:



    static void _Print(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n__________________________\n";
        cout << "\nFirstName    : " << Client.FirstName;
        cout << "\nLastName     : " << Client.LastName;
        cout << "\nFul Name     : " << Client.FullName();
        cout << "\nEmail        : " << Client.Email;
        cout << "\nPhone        : " << Client.Phone;
        cout << "\nAcc. Number  : " << Client.AccountNumber();
        cout << "\nPassWord     : " << Client.PinCode;
        cout << "\nBalance      : " << Client.AccountBalance;
        cout << "\n__________________________\n";


    }

public:

    static void ShowWithDrawScreen()
    {

        _DrawScreenHeader("\t WithDraw Screen");


        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "]" << " dose not exists. ";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _Print(Client);


        double Amount = 0;

        cout << "\nPlease Enter WithDraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        while (Amount <= 0)
        {
            cout << "\nPlease Enter a Positive Number: ";
            Amount = clsInputValidate::ReadDblNumber();

        }

        char Answer = 'n';



        
            cout << "\nAre sure do you want to perform this transaction? ";
            cin >> Answer;

            if (toupper(Answer) == 'Y')
            {
                if (Client.WithDraw(Amount))
                {

                    cout << "\nAmount WithDrawed succeessfuly.\n";
                    cout << "\nAmount Balance Is: " << Client.AccountBalance;
                }
                else
                {
                    cout << "\ncannot withdraw, Insuffecient Balance!\n";
                    cout << "\nAmount Withdraw is: " << Amount;
                    cout << "\nYour Balance is: " << Client.AccountBalance;
                }

            }

            else
            {
                cout << "\nOpreation was cancelled.\n";
            }
        }
   


};


