#pragma once
#include <iostream>
#include "clsDate.h";
#include "clsInputValidate.h"


using namespace std;


class clsInputValidate
{



public:



	static  bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetweenm(int Number, int From, int To)
	{
		return (Number > From && Number < To);
	}

	static bool IsNumberBetweenm(double Number, double From, double To)
	{
		return (Number > From && Number < To);
	}


	//static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	//{
	//	if (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From
	//	) &&
	//		clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
	//	{
	//		return true;
	//	}

	//	if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)
	//		&&
	//		(clsDate::IsDate1BeforeDate2(Date, From)) || clsDate::IsDate1EqualDate2(Date, From)))
	//	{
	//		return true;
	//	}

	//	return false;

	//}

	static int ReadIntNumber(string Errormessage = "Invalid NUmber, Enter again:")
	{
		int Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Errormessage;

		}
		return Number;
	}

	static double ReadDblNumber(string Errormessage = "Invalid Number, Enter again:")
	{

		double Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << Errormessage;
		}
		return Number;
	}

	static string ReadStirng()
	{
		string Message;
		getline(cin >> ws, Message);

		return Message;
	}

	static float ReadFloatNumber()
	{
		float Number;

		cin >> Number;
		return Number;
	}


	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Invalid Number, Enter again:")
	{
		short Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();

		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Invalid Number, Enter again:")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();

		}
		return Number;
	}


	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Invalid Number, Enter again:")
	{
		double Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();

		}
		return Number;
	}

	//static bool IsValidDate(clsDate Date)
	//{
	//	return clsDate::IsValidDate(Date);
	//}




};



