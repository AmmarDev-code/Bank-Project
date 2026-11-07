#pragma once
#include <iostream>
#include "Global.h"
#include "clsString.h"
#include <fstream>
#include <vector>
#include "clsDate.h"

using namespace std;



class clsLoginRegister
{


private:

    static void   _SaveUserDataToFile(string Line)
    {
        fstream MyFile;

        MyFile.open("LoginRegister.txt", ios::out | ios::app);


        if (MyFile.is_open())
        {

                    MyFile << Line << endl;
            
            MyFile.close();
        }
    }


public:

    static void SaveDataToFile()
    {

        string Line = "";

       
       Line = clsDate::DateToString(clsDate()) +  " - "  + clsDate::TimeToString() + "#//#" + CurrentUser.UserName + "#//#" + CurrentUser.PassWord + "#//#" + to_string(CurrentUser.Perimission);

        
        _SaveUserDataToFile(Line);
        
    }


    



};

