#include <clocale>
#include <iostream>
#include <fstream>
#include "Money.h"
using namespace std;

Money::Money()

{
	A = 0; B = 0;
}
Money::Money(const Money &t)
{
	A = t.A;
	B = t.B;
}
Money::Money(int _A)
{
	A = 1;
}
Money::~Money()
{
	A = 0;
	B = 0;
}


Money Money ::operator+(const Money& c)
{
	Money h;
	h.A = A + c.A;
	h.B = B + c.B;
	while (h.B >= 100)
	{
		h.B = h.B - 100;
		h.A = h.A + 1;
	}
	return h;
}

Money& Money::operator=(const Money& c)
{
	(*this).A = c.A;
	B = c.B;
	return *this;
}
Money Money ::operator-(const Money& c1)
{
	Money h;
	int k = B;
	if (A > c1.A)
	{h.A = (A - c1.A);}
	else
	{h.A = (A - c1.A);}
	if (B > c1.B)
	{h.B = B - c1.B;}
	else
	{
		while (B < c1.B)
		{
			h.A = h.A - 1;
			B = h.B + 100;
			h.B = h.B + 100;
		}
		h.B = h.B - c1.B;
	}
	B = k;
	return h;
}

Money Money::operator*(double t)
{
	Money h;

	h.A = A * t;
	h.B = B * t;
	while (h.B >= 100)
	{
		h.B = h.B - 100;
		h.A = h.A + 1;
	}
	while (h.B <= -100)
	{
		h.B = h.B + 100;
		h.A = h.A + 1;
	}
	return h;
}
Money Money::operator/(double t)
{
	Money h;
	h.A = A / t;
	h.B = B / t;
	while (h.B >= 100)
	{
		h.B = h.B - 100;
		h.A = h.A + 1;
	}
	while (h.B <= -100)
	{
		h.B = h.B + 100;
		h.A = h.A + 1;
	}
	return h;
}

bool Money::operator==(const Money& c)
{
	bool m;
	m = ((A == c.A) && (B == c.B));
	return m;
}
bool Money::operator!=(const Money& c)
{
	bool m;
	m = ((A != c.A) && (B != c.B));
	return m;
}
bool Money::operator>(const Money& c)
{
	bool m;
	if (A > c.A) { return m = 1; }
	else
	{
		return m = 0;
	}
}
bool Money::operator<(const Money& c)
{
	bool m;
	if (A < c.A) { return m = 1; }
	else
	{
		return m = 0;
	}
}
ostream& operator<<(ostream& stream, const Money& c) 
{
	stream << c.A << " " << c.B << endl;
	return stream;
}

istream& operator>>(istream& stream, Money& c)
{
	stream >> c.A >> c.B;
	return stream;
}