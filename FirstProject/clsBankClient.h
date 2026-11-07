#pragma once;
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "clsPerson.h"
#include "clsString.h";
#include "clsScreen.h"
#include <iomanip>

using namespace std;


class   clsBankClient :public clsPerson
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3};
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;




    
   static string _ConvertClientObjectToLine(clsBankClient Client, string Sperator = "#//#")
    {
        string stClinetRecord = "";

        stClinetRecord += Client.FirstName+ Sperator;
        stClinetRecord += Client.LastName + Sperator;
        stClinetRecord += Client.Email + Sperator;
        stClinetRecord += Client.Phone + Sperator;
        stClinetRecord += Client.AccountNumber() + Sperator;
        stClinetRecord += Client.PinCode + Sperator;
        stClinetRecord += to_string(Client.AccountBalance);

        return stClinetRecord;

    }

  static vector <clsBankClient> _LoadClientsDataFromFile()
   {
       vector <clsBankClient> vClients;

       fstream MyFile;

       MyFile.open("Client.txt", ios::in);

       if (MyFile.is_open())
       {

           string Line;

           while (getline(MyFile, Line))
           {

               clsBankClient Client = _ConvertLineToClientObject(Line);

               vClients.push_back(Client);

           }
           MyFile.close();
       }
       return vClients;

   }

 

   static void  _SaveClientDataToFile(vector <clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Client.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for ( clsBankClient& c : vClients)
            {
                if (c._MarkForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(c);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }


    static clsBankClient  _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& c : _vClients)
        {
            if (c.AccountNumber() == AccountNumber())
            {
                c = *this;
                break;
            }

        }
        _SaveClientDataToFile(_vClients);
    }

   
    static void _AddDataLineToFile(string sDataLine)
    {
        fstream MyFile;
        MyFile.open("Client.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << sDataLine << endl;

            MyFile.close();
        }
    }

 

    void _AddNew()
    {

        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
        
    }

 


public:

    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountBalance = AccountBalance;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
    }

    static clsBankClient _ConvertLineToClientObject(string s1, string Sperator = "#//#")
    {

        vector <string> vClientData;

        vClientData = clsString::Spilt(s1, Sperator);

        return clsBankClient(enMode::UpdateMode, vClientData.at(0), vClientData.at(1), vClientData.at(2), vClientData.at(3), vClientData.at(4), vClientData.at(5), stod(vClientData.at(6)));
        //  return  clsBankClient(enMode::UpdateMode, "", "", "", "", "", "", 0);
    }


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    _declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


    enum  enSaveResults { svFaildEmptyObject = 1, svSucceeded = 2, svFaildAccountNumberExists = 3, svDeleted = 4};

    
    enSaveResults Save()
    {

        switch (_Mode)
        {

        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }
        
        case enMode::UpdateMode:
        {
             _Update();
             return enSaveResults::svSucceeded;
             break;
        }

        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;

            }
        }

       


        }

    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }


    bool WithDraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            AccountBalance -= Amount;
            Save();
            return true;

        }
       
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients;

        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& c : _vClients)
        {
            if (c.AccountNumber() == AccountNumber())
            {
                c._MarkForDelete = true;
                break;
            }

        }
        _SaveClientDataToFile(_vClients);
        *this = _GetEmptyClientObject();
        return true;
    }


    string  AccountNumber()
    {
        return _AccountNumber;
    }

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }

   // _declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;
    
    _declspec(property( get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;



    static vector <clsBankClient> GetClientList()
    {
        return _LoadClientsDataFromFile();
    }


    static clsBankClient Find(string AccountNumber)
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Client.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                                                         
                clsBankClient  Client  = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

                vClients.push_back(Client);
                
            }
            MyFile.close();
        }
        
        return _GetEmptyClientObject();

    }

    static  clsBankClient GetAddNewClient(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);

    }


    static clsBankClient Find(string AccountNumber, string PinCode)
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Client.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                clsBankClient  Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();

    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        double TotalBalances = 0;
        
        for (clsBankClient Client: vClients)
        {
            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }

     
    static bool IsClientExist(string AccountNumber)
    {
          clsBankClient Client1 = clsBankClient::Find(AccountNumber);
          return (!Client1.IsEmpty());
    }

      
     
    



};
