#include <iostream>
#include <cmath>
#include <algorithm>
#include "BigNumber.h"
#include <fstream>
#include <clocale>
//opisanie/////////////////////////////////////////////////////////////////////////////////////
using namespace std;
// input and output to stream------------------------------------------
ostream& operator<<(ostream& Ostream, const Decimal& Dcm)
{
	for (int j = Dcm.lgth - 1; j >= 0; j--) 
	{
		Ostream << (int)Dcm.num[j];
	}
	return Ostream;
}
istream& operator>>(istream& Istream, Decimal& Dcm)
{
		char* stroka = new char[Dcm.lgth + 1];
		cin.ignore();
		Istream.getline(stroka, Dcm.lgth + 1);
		for (int j = 0; j < Dcm.lgth; j++) 
		{
			Dcm.num[Dcm.lgth - j - 1] = stroka[j] - '0';
		}
		return Istream;
	}
//comparison operations----------------------------------------
bool Decimal::operator==(const Decimal& Dcm) 
{
	if (Dcm.lgth ==lgth )
	{
		int k = lgth;
		while (k >= 0) 
		{
			if (num[k] != Dcm.num[k])
			{
				return false;
			}
			else 
			{
				k =k - 1;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
////////////////////////////////////////////////////////////////////////
bool Decimal::operator!=(const Decimal& Dcm)
{
	if (lgth == Dcm.lgth) 
	{
		int j = lgth;
		while (j >= 0) 
		{
			if (Dcm.num[j] != num[j] )
			{
				return true;
			}
			else
			{
				j =j - 1;
			}
		}
		return false;
	}
	else 
	{
		return true;
	}
}
/////////////////////////////////////////////////////////////////////////////////////
bool Decimal::operator>(const Decimal& Dcm)
{
	if (lgth > Dcm.lgth)
	{
		return true;
	}
	else if (lgth < Dcm.lgth)
	{
		return false;
	}
	else {
		int j = lgth;
		while (j >= 0) {
			if (num[j] > Dcm.num[j])
			{
				return true;
			}
			else if (num[j] < Dcm.num[j]) 
			{
				return false;
			}
			else
			{
				j =j - 1;
			}
		}
		return false;
	}
}
//////////////////////////////////////////////////////////////////////////////////
bool Decimal::operator>=(const Decimal& Dcm) 
{
	if (lgth > Dcm.lgth) 
	{
		return true;
	}
	else if (lgth < Dcm.lgth) 
	{
		return false;
	}
	else {
		int j = lgth;
		while (j >= 0)
		{
			if (num[j] > Dcm.num[j]) 
			{
				return true;
			}
			else if (num[j] < Dcm.num[j])
			{
				return false;
			}
			else 
			{
				j =j - 1;
			}
		}
		return true;
	}
}
//////////////////////////////////////////////////////////////////////////////////
bool Decimal::operator<=(const Decimal& Dcm)
{
	if (lgth < Dcm.lgth)
	{
		return true;
	}
	else if (lgth > Dcm.lgth)
	{
		return false;
	}
	else 
	{
		int j = lgth;
		while (j >= 0)
		{
			if (num[j] < Dcm.num[j])
			{
				return true;
			}
			else if (num[j] > Dcm.num[j])
			{
				return false;
			}
			else 
			{
				j = j - 1;
			}
		}
		return true;
	}
}
/////////////////////////////////////////////////////////////////////////////
bool Decimal::operator<(const Decimal& Dcm)
{
	if (lgth < Dcm.lgth) 
	{
		return true;
	}
	else if (lgth > Dcm.lgth)
	{
		return false;
	}
	else 
	{
		int j = lgth;
		while (j >= 0)
		{
			if (num[j] < Dcm.num[j])
			{
				return true;
			}
			else if (num[j] > Dcm.num[j])
			{
				return false;
			}
			else 
			{
				j = j - 1;
			}
		}
		return false;
	}
}
//prisvaivaniye--------------------------------
Decimal& Decimal::operator=(const Decimal& Dcm)
{
	if (Dcm.lgth > lgth)
		{
		lgth = Dcm.lgth;
		delete[] num;
		num = new unsigned char[lgth];
	}
	int j = 0;
	while (Dcm.num[j])
	{
		num[j] = Dcm.num[j];
		j++;
	}
	return *this;
}
//summa and difference---------------------------------------------------------------------
Decimal Decimal::operator+(const Decimal& Dcm)
{
	int len = 0;
	if (lgth > Dcm.lgth) 
	{
		len = lgth;
	}
	else if (lgth < Dcm.lgth)
	{
		len = Dcm.lgth;
	}
	else
	{
		if (num[lgth - 1] + Dcm.num[Dcm.lgth - 1] > 9)
		{
			len = lgth + 1;
		}
		else
		{
			len = lgth;
		}
	}
	
	Decimal Result(len);
	int tmp = 0;
	for (int j = 0; j < Result.lgth; j++) 
	{
		if (j < Dcm.lgth) {
			Result.num[j] = (num[j] + Dcm.num[j] + tmp) % 10;
			tmp = (num[j] + Dcm.num[j] + tmp) / 10;
		}
		else 
		{
			Result.num[j] = (num[j] + tmp) % 10;
			tmp = (num[j] + tmp) / 10;
		}
	}
	return Result;
}
//////////////////////////////////////////////////////////////////////
Decimal Decimal::operator-(const Decimal& Dcm)
{
	Decimal Result(lgth);
	for (int j = 0; j < lgth; j++)
	{
		Result.num[j] = num[j];
	}
	if (lgth == Dcm.lgth) {
		for (int i = 0; i < lgth; i++) 
		{
			if (num[i] != Dcm.num[i]) 
			{
				break;
			}
			else if (i == lgth - 1 && num[i] == Dcm.num[i])
			{
				Result.lgth = 1;
				Result.num[0] = 0;
			}
		}
	}
	else 
	{
		for (int j = 0; j < Result.lgth; j++)
		{
			if (j < Result.lgth - 1) 
			{
				Result.num[j + 1] = Result.num[j + 1] - 1;
				Result.num[j] = Result.num[j] + 10;
			}
			Result.num[j] = Result.num[j] - Dcm.num[j];
			if ((Result.num[j] / 10) > 0) 
			{
				Result.num[j + 1] = Result.num[j] + 1;
				Result.num[j] = Result.num[j]% 10;
			}
		}
		if (Result.num[lgth - 1] == 0) 
		{
			Result.lgth = lgth - 1;
		}
	}
	return Result;
}


// Constructor ----------------------
Decimal::Decimal(int razmer)
{
	lgth = razmer;
	num = new unsigned char[lgth];
}
// Destructor------------------------------------
Decimal::~Decimal()
{
	lgth = NULL;
	delete[] num;
	num = NULL;
}