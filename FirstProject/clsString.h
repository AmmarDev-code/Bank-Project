#pragma once;

#include <iostream>
#include <vector>
using namespace std;


class clsString
{
private:
    string  _Value;



public:


    clsString(string Value)
    {
        _Value = Value;

    }

    clsString()
    {
        _Value = " ";

    }

    void SetValue(string Value)
    {

        _Value = Value;
    }


    string GetValue()
    {
        return  _Value;
    }




    static short  CountWords(string s1)
    {

        short pos = 0;
        string delim = " ";
        string sword;
        short Counter = 0;


        while ((pos = s1.find(delim)) != std::string::npos)
        {

            sword = s1.substr(0, pos);
            if (sword != "")
            {
                Counter++;

            }

            s1.erase(0, pos + delim.length());

        }
        if (s1 != "")
        {
            Counter++;
        }

        return Counter;


    }

    short CountWords()
    {
        return  CountWords(_Value);

    }


    static vector <string> Spilt(string s1, string delim)
    {
        vector <string> vstring;

        short pos = 0;
        string sword;


        while ((pos = s1.find(delim)) != std::string::npos)
        {

            sword = s1.substr(0, pos);
            if (sword != "")
            {
                vstring.push_back(sword);

            }

            s1.erase(0, pos + delim.length());

        }
        if (s1 != "")
        {
            vstring.push_back(s1);
        }
        return vstring;

    }


    vector <string> Spilt(string delim)
    {
        return Spilt(_Value, delim);
    }

    static char InvertLetterCase(char Letter)
    {
        return (isupper(Letter) ? tolower(Letter) : toupper(Letter));

    }

    static string InvertAllLetterCase(string s1)
    {
        for (int i = 0; i < s1.length(); i++)
        {
            s1[i] = InvertLetterCase(s1[i]);

        }
        return s1;

    }

    void InvertAllLetterCase()
    {
        _Value = InvertAllLetterCase(_Value);

    }

    enum enWhatToCount { SmallLetter = 0, CapitalLetter = 1, All = 3 };

    static short CountLetter(string s1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
        {
            return s1.length();

        }
        int Counter;

        for (int i = 0; i < s1.length(); i++)
        {

            if (WhatToCount == enWhatToCount::CapitalLetter && isupper(s1[i]))
                Counter++;

            if (WhatToCount == enWhatToCount::SmallLetter && islower(s1[i]))
                Counter++;

        }
        return Counter;


    }

    static int CountCapitalLetter(string s1)
    {
        int CapitalLetter;

        for (int i = 0; i < s1.length(); i++)
        {

            if (isupper(s1[i]))
                CapitalLetter++;
        }

        return CapitalLetter;

    }

    static int CountSmallLetter(string s2)
{
    int SmallLetter;

    for (int i = 0; i < s2.length(); i++)
    {

        if (islower(s2[i]))
            SmallLetter++;

    }
    return SmallLetter;

}


    static string NumberToText(int Number)
    {

        if (Number == 0)
        {

            return "";
        }

        if (Number >= 1 && Number <= 19)
        {

            string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
            "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
            "Nineteen" };

            return arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {

            string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
            return arr[Number / 10] + " " + NumberToText(Number % 10);

        }

        if (Number >= 100 && Number <= 199)
        {

            return "One Hundred " + NumberToText(Number % 100);

        }

        if (Number >= 200 && Number <= 999)
        {

            return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);

        }

        if (Number >= 1000 && Number <= 1999)
        {

            return "One Thousand " + NumberToText(Number % 1000);

        }

        if (Number >= 2000 && Number <= 999999)
        {

            return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 100);
        }

        if (Number <= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);

        }

        if (Number <= 2000000 && Number <= 999999999)
        {

            return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number <= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {

            return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }

    }


    static short Length(string s1)
    {
        return s1.length();
    }
    short Length()
    {
        return Length(_Value);
    }

    int CountCapitalLetter()
    {
        return CountCapitalLetter(_Value);

    }

    
    static short CountSpecificLetter(string s1, char Letter = 'v', bool MatchCase = true)
    {
        int Counter ;
        
        for (int i = 0; i < s1.length(); i++)
        {

            if (MatchCase)
            {
                if (s1[i] == Letter)
                    Counter++;

            }

            else
            {
                if (toupper(s1[i]) == toupper(Letter))
                    Counter++;
            }

        }

        return Counter;
    }

    short CountSpecificLetter(char Letter, bool MatchCase = true)
    {

        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    int  CountSmallLetter()
    {

        return CountSmallLetter(_Value);

    }

    static bool IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

    }

    static int CountVowels(string s1)
    {
        int Counter = 0;

        for (int i = 0; i < s1.length(); i++)
        {

            if (IsVowel(s1[i]))
            {
                Counter++;
            }

        }

        return Counter;
    }

    int CountVowels()
    {

        return CountVowels(_Value);
    }

    string JoinString(vector <string> vstring, string delim)
    {
        string s1;

        for (string& s : vstring)
        {
            s1 = s1 + s + delim;

        }

        return s1.substr(0, s1.length() - delim.length());

    }

    string JoinString(string arr[], int  length, string delim)
    {
        string s1;

        for (int i = 0; i < length; i++)
        {
            s1 = s1 + arr[i] + delim;

        }

        return s1.substr(0, s1.length() - delim.length());
    }



    static string RemovePunctuations(string s1)
    {
        string s2 = "";

        for (int i = 0; i < s1.length(); i++)
        {

            if (!ispunct(s1[i]))
            {
                s2 += s1[i];

            }

        }
        return s2;
    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);

    }

    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool IsFirstLetter = true;

        for (int i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && IsFirstLetter)
            {
                S1[i] = toupper(S1[i]);

            }
            IsFirstLetter = (S1[i] == ' ' ? true : false);
        }
        return S1;

    }

    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);


    }

    static string ReplaceWord(string s1, string StringToReplace, string SReplaceTo)
    {


        short pos = s1.find(StringToReplace);

        while (pos != s1.npos)
        {

            s1 = s1.replace(pos, StringToReplace.length(), SReplaceTo);
            pos = s1.find(StringToReplace);

        }
        return s1;

    }

    string ReplaceWord(string StringToReplace, string SReplaceTo)
    {
        return ReplaceWord(_Value, StringToReplace, SReplaceTo);
    }

    static string ChangeTheWord(string s1)
    {
        string s2;

        for (int i = 0; i < s1.length(); i++)
        {


            s2 += tolower(s1[i]);

        }
        return s2;

    }

    string ChangeTheWord()
    {

        return ChangeTheWord(_Value);
    }

    static string LowerAllString(string s1)
    {
        for (int i = 0; i < s1.length(); i++)
        {

            s1 = tolower(s1[i]);

        }
        return s1;
    }

    void  LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static string ReverseWordsInString(string s1)
    {

        vector <string> vstring;
        string s2 = "";
        vstring = Spilt(s1, " ");

        vector <string>::iterator iter = vstring.end();

        while (iter != vstring.begin())
        {


            --iter;

            s2 += *iter + " ";
        }
        return s2.substr(0, s2.length() - 1);


    }

    void ReverseWordsInString()
    {

        _Value = ReverseWordsInString(_Value);

    }

    static string TrimLeft(string s1)
    {
        for (int i = 0; i < s1.length(); i++)
        {

            if (s1[i] != ' ')
            {
                return s1.substr(i, s1.length() - i);
            }
        }
        return "";
    }


    void TrimLeft()
    {

        _Value = TrimLeft(_Value);

    }

    static string TrimRight(string s1)
    {

        for (int i = s1.length(); i >= 0; i--)
        {

            if (s1[i] != ' ')
            {
                return s1.substr(0, i + 1);
            }

        }
        return "";
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }


    static string Trime(string s1)
    {

        return TrimLeft(TrimRight(s1));
    }

    void  Trime()
    {
        _Value = Trime(_Value);
    }

    static string UpperAllString(string s1)
    {

        for (int i = 0; i < s1.length(); i++)
        {

            s1[i] = toupper(s1[i]);

        }

        return s1;
    }

    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }




};


