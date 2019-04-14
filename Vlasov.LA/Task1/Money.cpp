#include <iostream>
#include <locale.h>
#include <cmath>
#include "Money.h"

using namespace std;



Money::Money() 
{
	valueR = 0;
	valueR = 0;
}

Money::Money(int _valueR, unsigned char _valueK)
{
	valueR = _valueR;
	valueK = _valueK;
}

Money::Money(const Money& M)
{
	valueR = M.valueR;
	valueK = M.valueK;
}

Money::~Money()
{
	valueR = 0;
	valueR = 0;
}


Money& Money::operator= (const Money& a)
{
	valueR = a.valueR;
	valueK = a.valueK;
	return *this;
}


Money Money::operator+(const Money& a) 
{
	Money res;
	res.valueR = valueR + a.valueR;
	res.valueK = valueK + a.valueK;
	res.valueR += res.valueK / 100;
	res.valueK = res.valueK / 100;
	return res;
}


Money Money::operator- (const Money& a)
{
	return Money(0, 0);
}


Money operator* (const Money& a, double d)
{
	return Money(0, 0);
}


Money operator/ (const Money& a, double d)
{
	return Money(0, 0);
}


bool Money::operator> (const Money& a)
{
	return ((this->valueR > a.valueR) || ((this->valueK > a.valueK) && (this->valueR == a.valueR)));

}


bool Money::operator< (const Money& a)
{
	return ((this->valueR < a.valueR) || ((this->valueK < a.valueK) && (this->valueR == a.valueR)));
}


bool Money::operator== (const Money& a)
{
	return ((this->valueK == a.valueK) && (this->valueR == a.valueR));
}


bool Money::operator>= (const Money& a)
{
	return ((this->valueR > a.valueR) || ((this->valueK >= a.valueK) && (this->valueR == a.valueR)));
}


bool Money::operator<= (const Money& a)
{
	return ((this->valueR < a.valueR) || ((this->valueK <= a.valueK) && (this->valueR == a.valueR)));
}



istream& operator>> (istream &in, Money &a)
{
	in >> a.valueR;
	in >> a.valueK;

	return in;
}


ostream& operator<< (ostream &out, const Money &a)
{
	out << a.valueR << " " << a.valueK << endl;
	return out;
}