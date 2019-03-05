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
		Ostream << (int)Dcm.num[j]; //Ostream << endl;
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
{ lgth = Dcm.lgth;
if (this == &Dcm)
return *this;
if (Dcm.lgth > lgth)
{
	lgth = Dcm.lgth;
	delete[] num;
	num = new unsigned char[lgth];
}
int j = 0;
for (j = 0; j < Dcm.num[j]; j++)
{
	num[j] = Dcm.num[j];
	
}
return *this;
}
//summa and difference---------------------------------------------------------------------
Decimal Decimal::operator+(const Decimal& Dcm)
{
	int len = 0;

	if (lgth >= Dcm.lgth) 
	{
		len = lgth;
	}
	else if (lgth < Dcm.lgth)
	{
		len = Dcm.lgth;
	}
	else
	{
		if (num[lgth - 1] + Dcm.num[Dcm.lgth - 1] > 9 )//|| lgth < Dcm.lgth
		{
			len = lgth + 1;
		}
		else
		{
			len = lgth;
		}
	}
	
	Decimal Result(len);//INICIALIZATOR
	int tmp = 0;
	for (int j = 0; j < Result.lgth; j++) 
	{
		if (j < Dcm.lgth && j<=len )//
		{
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
//////////////////////////////////////////////////////////
Decimal Decimal::operator-(const Decimal& Dcm)
{
	Decimal Resul(lgth);
	int tmp = 0;
	int len = 0;

	if (lgth >= Dcm.lgth)
	{
		len = lgth;
	}
	else if (lgth < Dcm.lgth)
	{
		len = Dcm.lgth;
	}

	if (num >= Dcm.num && Dcm.lgth<=lgth)
	{
		for (int j = 0; j < lgth; j++)
		{
			if (num[j] >= Dcm.num[j])
				Resul.num[j] = num[j] - Dcm.num[j];
			else if (num[j] < Dcm.num[j] && num[j + 1] != 0)//   
			{
				tmp = 1;
				Resul.num[j] = (num[j] + 10 - Dcm.num[j]) % 10;
				num[j + 1] = num[j + 1] - tmp;

			}

		}
	}
	else if (num < Dcm.num)
	{
		/*	len = Dcm.lgth;
			for (int j = 0; j < len; j++)
			Resul.num[j] = (~(num[j] - Dcm.num[j]))|128;*/

		for (int j = 0; j < Dcm.lgth; j++)
		{
			if (j < Dcm.lgth)
			{
				Resul.num[j] = Resul.num[j] + 10;
				Resul.num[j + 1] = Resul.num[j + 1] - 1;

			}
			Resul.num[j] = Resul.num[j] - Dcm.num[j];
			
				
		}
	}
	return  Resul;
}
// Constructor ----------------------
Decimal::Decimal(void)
{
	lgth = 0;
	num = NULL;
}
Decimal::Decimal(int razmer)
{
	lgth = razmer;
	num = new unsigned char[lgth];
}
 
// Destructor------------------------------------
Decimal::~Decimal(void)
{
	lgth = 0;
	delete[] num;
	
}