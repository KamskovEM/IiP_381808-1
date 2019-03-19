#pragma once
#include "Octal.h"


using namespace std;

Octal::Octal(void) // konstruktor po ymolchaniuy
{
	length = 0;
	for (int i = 0; i < length; i++) {
		digit[i] = '0';
	}
}
Octal::Octal(int _length) // konstruktor inicializacii
{
	length = _length;
	digit = new unsigned char[length];
}
Octal::Octal(const Octal &O) // konstruktor kopirovaniya
{
	length = O.length;
	digit = new unsigned char[length];
	for (int i = 0; i < length; i++)
	{
		digit[i] = O.digit[i];
	}
}
Octal::Octal(const string OctalStr) // konstruktor pr. tipa iz stroki
{
	length = OctalStr.length();
	digit = new unsigned char[length];
	for (int i = 0; i < length; i++)
	{
			digit[i] = OctalStr[length - 1 - i] - '0';
	}
}
Octal::~Octal() // destruktor
{
	length = 0;
	digit = NULL;
}
//peregruzka operacij:
Octal Octal::operator*(const Octal& O) // operaciya ymnozheniya
{
	int _max = max(this->length, O.length);
	Octal tmp1(*this);
	Octal tmp2(O);
	Octal res;
	tmp1.To10();
	tmp2.To10();
	int tmp = tmp1.ToInt() * tmp2.ToInt();
	res = ToChar(tmp);
	res.To8();
	if (res.length > _max) // proverka na lishnij razryad
	{
		int tmp = res.ToInt();
		int b = pow(10, _max);
		tmp = tmp % b;
		res = ToChar(tmp);
	}
	return res;
}
Octal Octal::operator+(const Octal& O) // operaciya slojeniya
{
	int _max = max(this->length, O.length);
	Octal tmp1(*this);
	Octal tmp2(O);
	Octal res;
	tmp1.To10(); 
	tmp2.To10();
	int tmp = tmp1.ToInt() + tmp2.ToInt();
	res = ToChar(tmp);
	res.To8();
	if (res.length > _max) // proverka na lishnij razryad
	{
		int tmp = res.ToInt();
		int b = pow(10, _max);
		tmp = tmp % b;
		res = ToChar(tmp);
	}
	return res;
}
Octal Octal::operator-(const Octal& O) // operaciya vichitaniya
{
	int _max = max(O.length, length);
	int _min = min(O.length, length);
	Octal res(_max);
	int ost = 0;
	for (int i = 0; i < _min; i++)
	{
		if (digit[i] + ost < O.digit[i])
		{
			res.digit[i] = digit[i] - O.digit[i] + 8 + ost;
			ost = -1;
		}
		else
		{
			res.digit[i] = digit[i] - O.digit[i] + ost;
			ost = 0;
		}
	}
	if (O.length != length) // proverka esli dlini ne ravni
	{
		if (length > O.length) 
		{
			for (int i = _min; i < _max; i++)
			{
				if (digit[i] + ost < 0)
				{
					res.digit[i] = digit[i] + ost + 8;
					ost = -1;
				}
				else 
				{
					res.digit[i] = digit[i] + ost;
					ost = 0;
				}
			}
		}
		else
		{
			for (int i = _min; i < _max; i++) 
			{
				if (O.digit[i] - ost > 0)
				{
					res.digit[i] = -O.digit[i] + ost + 8;
					ost = -1;
				}
				else 
				{
					res.digit[i] = O.digit[i] + ost;
					ost = 0;
				}
			}
		}
	}
	return res;
}
Octal& Octal::operator=(const Octal& O) // operaciya prisvaivaniya
{

	length = O.length;
	digit = new unsigned char[length];
	for (int i = 0; i < length; i++) 
		digit[i] = O.digit[i];
	return *this;
}
// operacii vvoda/vivoda v potok:
ostream& operator<<(ostream& stream, const Octal& O)
{
	for (int i = 0; i < O.length; i++)
	{
		stream << (int)(O.digit[O.length - i - 1]);
	}
	return stream;
}
istream& operator>>(istream& stream, Octal& O)
{
	string str;
	stream >> str;
	O = str;
	return stream;
}
// operacii sravneniya:
bool Octal::operator==(const Octal& O)
{
	if (length != O.length) return false;
	for (int i = 0; i < length; i++)
	{
		if (digit[i] != O.digit[i]) return false;
	}
	return true;
}
bool Octal::operator!=(const Octal& O)
{
	if (length != O.length) return true;
	for (int i = 0; i < length; i++)
	{
		if (digit[i] != O.digit[i]) return true;
	}
	return false;
}
bool Octal::operator>(const Octal& O)
{
	if (length > O.length) return true;
	if (length < O.length) return false;
	for (int i = length - 1; i >= 0; i--)
	{
		if (digit[i] <= O.digit[i]) return false;
	}
	return true;
}
bool Octal::operator<(const Octal& O)
{
	if (length > O.length) return false;
	if (length < O.length) return true;
	for (int i = length - 1; i >= 0; i--)
	{
		if (digit[i] <= O.digit[i]) return true;
	}
	return true;
}

int Octal::ToInt() // perevod v Int
{
	int OctalInt = 0;
	for (int i = 0; i < length; i++)
	{
		OctalInt = OctalInt + (this->digit[ i ]) * pow(10, i);
	}
	return OctalInt;
}
Octal Octal::ToChar(int T) // perevod v peremennuyu klassa
{
	string s = to_string(T);
	Octal Str(s);
	return Str;
}
Octal Octal::To10() // perevod v 10 s.s.
{
	int _Octal = ToInt(); // perevod chisla v int
	int res = 0;
	for (int i = 0; i < length; i++)
	{
		res = res + _Octal % 10 * pow(8, i); // berem poslednee chislo, ymnozhaem na stepen 8-ki
		_Octal = _Octal / 10; // "otrybaem" poslednyuyu cifry 
	}
	*this = this->ToChar(res);
	return *this;
}
Octal Octal::To8() // perevod v 8 s.s.
{
	int _Octal = ToInt(); // perevod chisla v int
	int res = 0;
	int i = 1;
	do
	{
		res = res + _Octal % 8 * i; // berem ostatok ot deleniya na 8, ymnozhaem na razryad
		i = i * 10; // yvelichivaem razryad
		_Octal = _Octal / 8; // "otrybaem" poslednyuyu cifry
	} while (_Octal > 0);
	*this = this->ToChar(res);
	return *this;
}