#include <clocale>

#include <iostream>

#include <fstream>
#include "Money.h"
using namespace std;







//constructors
Money::Money()//default constructor

{
	A = 0; B = 0;
}
Money::Money(const Money &t)//copy constructor
{
	A = t.A;
	B = t.B;
}
Money::Money(int _A)//type conversion constructor
{
	A = 1;
}
//Destructor
Money::~Money()//Destructor
{
	A = 0;
	B = 0;
}



Money& Money::operator=(const Money& c)
{
	(*this).A = c.A;
	B = c.B;
	return *this;
}
Money Money ::operator+(const Money& c)
{
	Money tmp;
	tmp.A = A + c.A;
	tmp.B = B + c.B;
	while (tmp.B >= 100)
	{
		tmp.B = tmp.B - 100;
		tmp.A = tmp.A + 1;
	}
	return tmp;
}
Money Money ::operator-(const Money& c1)
{
	Money tmp;
	int k = B;

	if (A > c1.A)
	{
		tmp.A = (A - c1.A);
	}
	else
	{
		tmp.A = (A - c1.A);

	}
	if (B > c1.B)
	{
		tmp.B = B - c1.B;
	}
	else
	{
		while (B < c1.B)
		{
			tmp.A = tmp.A - 1;
			B = tmp.B + 100;
			tmp.B = tmp.B + 100;

		}
		tmp.B = tmp.B - c1.B;
	}
	B = k;
	return tmp;

}

Money Money::operator*(double t)
{
	Money tmp;

	tmp.A = A * t;
	tmp.B = B * t;
	while (tmp.B >= 100)
	{
		tmp.B = tmp.B - 100;
		tmp.A = tmp.A + 1;
	}
	while (tmp.B <= -100)
	{
		tmp.B = tmp.B + 100;
		tmp.A = tmp.A + 1;
	}
	return tmp;
}
Money Money::operator/(double t)
{
	Money tmp;

	tmp.A = A / t;
	tmp.B = B / t;
	while (tmp.B >= 100)
	{
		tmp.B = tmp.B - 100;
		tmp.A = tmp.A + 1;
	}
	while (tmp.B <= -100)
	{
		tmp.B = tmp.B + 100;
		tmp.A = tmp.A + 1;
	}


	return tmp;
}

bool Money::operator==(const Money& c)
{

	bool res;

	res = ((A == c.A) && (B == c.B));

	return res;
}
bool Money::operator!=(const Money& c)
{

	bool res;

	res = ((A != c.A) && (B != c.B));

	return res;
}
bool Money::operator>(const Money& c)
{

	bool res;
	if (A > c.A) { return res = 1; }
	else
	{
		return res = 0;
	}
}
bool Money::operator<(const Money& c)
{

	bool res;
	if (A < c.A) { return res = 1; }
	else
	{
		return res = 0;
	}
}
ostream& operator<<(ostream& stream, const Money& c) {

	stream << c.A << " " << c.B << endl;

	return stream;

}

istream& operator>>(istream& stream, Money& c) {

	stream >> c.A >> c.B;

	return stream;

}

