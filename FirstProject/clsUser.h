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


class clsUser :public clsPerson
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
    enMode _Mode;

    string _UserName;
    string _Password;
    int _Perimission;
    bool _MarkForDelete = false;



    static string _ConvertUserObjectToLine(clsUser User, string Sperator = "#//#")
    {
        string stUserRecord = "";

        stUserRecord += User.FirstName + Sperator;
        stUserRecord += User.LastName + Sperator;
        stUserRecord += User.Email + Sperator;
        stUserRecord += User.Phone + Sperator;
        stUserRecord += User.UserName + Sperator;
        stUserRecord += User.PassWord + Sperator;
        stUserRecord += to_string(User.Perimission);

        return stUserRecord;

    }


    static vector <clsUser> _LoadUsersDataFromFile()
    {
        vector <clsUser> vUsers;

        fstream MyFile;

        MyFile.open("User.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLineToUserObject(Line);

                vUsers.push_back(User);

            }
            MyFile.close();
        }
        return vUsers;

    }



    static void  _SaveUserDataToFile(vector <clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("User.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser& U : vUsers)
            {
                if (U._MarkForDelete == false)
                {
                    DataLine = _ConvertUserObjectToLine(U);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    static clsUser _ConvertLineToUserObject(string s1, string Sperator = "#//#")
    {

        vector <string> vUserData;

        vUserData = clsString::Spilt(s1, Sperator);

        return clsUser(enMode::UpdateMode, vUserData.at(0), vUserData.at(1), vUserData.at(2), vUserData.at(3), vUserData.at(4), vUserData.at(5), stod(vUserData.at(6)));
        //  return  clsBankClient(enMode::UpdateMode, "", "", "", "", "", "", 0);
    }

    static clsUser  _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "","", "", 0);
            
    }


    void _Update()
    {
        vector <clsUser> _vUsers;

        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }
        _SaveUserDataToFile(_vUsers);
    }


    static void _AddDataLineToFile(string sDataLine)
    {
        fstream MyFile;
        MyFile.open("User.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << sDataLine << endl;

            MyFile.close();
        }
    }



    void _AddNew()
    {

        _AddDataLineToFile(_ConvertUserObjectToLine(*this));

    }




public:

    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string PassWord ,int Perimission)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _Perimission = Perimission;
        _Password = PassWord;
        _UserName = UserName;
     
    }


    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClient = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
    };

    void SetPassword(string PassWord)
    {
        _Password = PassWord;
    }

    string GetPassWord()
    {
        return _Password;
    }

    _declspec(property(get = GetPassWord, put = SetPassword)) string PassWord;


    bool MarkForDeleted()
    {
        return _MarkForDelete;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    void SetPerimission(int Perimission)
    {
        _Perimission = Perimission;
    }

    int GetAPerimission()
    {
        return _Perimission;
    }

    _declspec(property(get = GetAPerimission, put = SetPerimission)) int Perimission;


    void SetUserName(string UserName)
    {
        _UserName = UserName;

    }

    string GetUserName()
    {
        return _UserName;
    }

    _declspec(property(get = GetUserName, put = SetUserName)) string UserName;




    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Perimission == enPermissions::eAll)
            return true;

        if ((Permission & this->Perimission) == Permission)
            return true;
        else
            return false;


    }


    enum  enSaveResults { svFaildEmptyObject = 1, svSucceeded = 2, svFaildAccountNumberExists = 3, svDeleted = 4 };


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
            if (clsUser::IsUserExist(_UserName))
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


    bool Delete()
    {
        vector <clsUser> _vUsers;

        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.PassWord == PassWord)
            {
                U._MarkForDelete = true;
                break;
            }

        }
        _SaveUserDataToFile(_vUsers);
        *this = _GetEmptyUserObject();
        return true;
    }



   

    static vector <clsUser> GetUserList()
    {
        return _LoadUsersDataFromFile();
    }


    static clsUser Find(string UserName)
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("User.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                clsUser  User = _ConvertLineToUserObject(Line);

                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }

                vUsers.push_back(User);

            }
            MyFile.close();
        }

        return _GetEmptyUserObject();

    }

   

    static clsUser Find(string UserName, string PassWord)
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("User.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                clsUser  User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName && User.PassWord == PassWord)
                {
                    MyFile.close();
                    return User;
                }

                vUsers.push_back(User);
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();

    }

    //static double GetTotalBalances()
    //{
    //    vector <clsBankClient> vClients = _LoadClientsDataFromFile();

    //    double TotalBalances = 0;

    //    for (clsBankClient Client : vClients)
    //    {
    //        TotalBalances += Client.AccountBalance;
    //    }

    //    return TotalBalances;

    //}


    static  clsUser GetAddNewUser(string PassWord)
    {
        return clsUser(enMode::AddNewMode, "", "","", "", PassWord, "", 0);

    }


    static bool IsUserExist(string UserName)
    {
        clsUser User1 = clsUser::Find(UserName);
        return (!User1.IsEmpty());
    }


    static bool IsUserExist(string UserName, string PassWord)
    {
        clsUser User1 = clsUser::Find(UserName, PassWord);
        return (!User1.IsEmpty());
    }





};
