#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include <vector>

using namespace std;

class clsDepositScreen : protected clsScreen
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

    static void ShowDepositScreen()
    {

        _DrawScreenHeader("\t Deposit Screen");


        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "]" << " dose not exists. ";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        _Print(Client);


        double Amount = 0;

        cout << "\nPlease Enter deposit amount? ";
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
            Client.Deposit(Amount);
            cout << "\nAmount Deposited succeessfuly.\n";
            cout << "\nAmount Balance Is: " << Client.AccountBalance;
            
        }

        else
        {
            cout << "\nOpreation was cancelled.\n";
        }
       
   }


};

