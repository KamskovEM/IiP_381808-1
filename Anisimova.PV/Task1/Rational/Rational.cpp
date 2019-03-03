#include <iostream>
#include <cmath>
#include <algorithm>
#include "pch.h"
#include "Rational.h"
#include<clocale>
using namespace std;

//Konstryktor
Rational::Rational() { n = 0; 	m = 1; }
Rational::Rational(int _n, int _m) { n = _n; m = _m; }
//Destryktor
Rational::~Rational() { n = 0; 	m = 1; }

//Prisvaivanie 
Rational Rational::operator=(const Rational& a)
{
	n = a.n;
	m = a.m;
	return *this;
}
// Operatsii

Rational Rational::operator + (const Rational& a)
{
	Rational res;
	if (m == a.m)
	{
		res.n = n + a.n;
		res.m = m;
		return res;
	}
	else
	{
		res.n = n * a.m + a.n * m;
		res.m = m * a.m;
		return res;
	}
}
Rational Rational::operator - (const Rational& a)
{
	Rational res;
	if (m == a.m)
	{
		res.n = n - a.n;
		res.m = m;
		return res;
	}
	else
	{
		res.n = n * a.m - a.n * m;
		res.m = m * a.m;
		return res;
	}
}
Rational Rational::operator * (const Rational& a)
{
	Rational res;
	res.n = n * a.n;
	res.m = m * a.m;

	return res;
}
Rational Rational::operator / (const Rational& a)
{
	Rational res;
	res.n = n * a.m;
	res.m = m * a.n;

	return res;
}

// Sravnenye
bool Rational::operator ==(const Rational& a)
{
	if (n * a.m != m * a.n)
		return false;
	return true;
}
// Vvod/vyvod fraction
ostream & operator << (ostream & stream, const Rational & c)//Vivod v potok
{
	stream << c.n << " " << c.m << endl;
	return stream;
}
istream& operator>>(istream & stream, Rational & c)//Vvod v potok
{
	stream >> c.n >> c.m;
	return stream;
}


