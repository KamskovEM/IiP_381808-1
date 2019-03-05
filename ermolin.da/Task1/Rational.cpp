#pragma once
#include <iostream>
#include <locale.h>
#include "Rational.h"

Rational::Rational()
{
	m = 1; n = 1;
}

Rational::Rational(int m)
{
	this->m = m; n = 1;
}

Rational::Rational(const Rational & c)
{
	m = c.m; n = c.n;
}

Rational::Rational(int m, int n)
{
	if (n < 0) { n *= -1; m *= -1; }
	this->m = m;
	this->n = n;
	this->Canc();
}


Rational::~Rational()
{
	m = 0; n = 0;
}

Rational Rational::operator+(const Rational & b)
{
	return Rational(this->m*b.n + b.m*this->n, this->n*b.n);
}

Rational Rational::operator+(int b)
{
	return Rational(this->m + b * n, n);
}

Rational Rational::operator-(const Rational & b)
{
	return Rational(this->m*b.n - b.m*this->n, this->n*b.n);
}

Rational Rational::operator-(int b)
{
	return Rational(this->m - b * n, n);
}

Rational Rational::operator*(const Rational & b)
{
	return Rational(m*b.m,n*b.n);
}

Rational Rational::operator*(int b)
{
	return Rational(m*b, n);
}

Rational Rational::operator/(const Rational & b)
{
	return Rational(m*b.n,n*b.m);
}

Rational Rational::operator/(int b)
{
	return Rational(m,n*b);
}

Rational Rational::operator=(const Rational & b)
{
	m = b.m;
	n = b.n;
	return *this;
}

Rational Rational::operator=(int b)
{
	m = b;
	n = 1;
	return *this;
}

bool Rational::operator==(const Rational & b)
{
	if (m == b.m && n == b.n) { return true; }
	return false;
}

bool Rational::operator==(int b)
{
	if (m == b && n == 1) { return true; }
	return false;
}

bool Rational::operator!=(const Rational & b)
{
	if (m != b.m || n != b.n) { return true; }
	return false;
}

bool Rational::operator!=(int b)
{
	if (m != b || n == 1) { return true; }
	return false;
}

bool Rational::operator<(const Rational & b)
{
	if (m*b.n < b.m*n) { return true; }
	return false;
}

bool Rational::operator<(int b)
{
	if (m < b*n) { return true; }
	return false;
}

bool Rational::operator>(const Rational & b)
{
	if (m*b.n > b.m*n) { return true; }
	return false;
}

bool Rational::operator>(int b)
{
	if (m > b*n) { return true; }
	return false;
}

bool Rational::operator<=(const Rational & b)
{
	if (m*b.n <= b.m*n) { return true; }
	return false;
}

bool Rational::operator<=(int b)
{
	if (m <= b*n) { return true; }
	return false;
}

bool Rational::operator>=(const Rational & b)
{
	if (m*b.n >= b.m*n) { return true; }
	return false;
}

bool Rational::operator>=(int b)
{
	if (m >= b * n) { return true; }
	return false;
}

ostream & operator<<(ostream & stream, const Rational & b)
{
	stream << b.m << "/" << b.n;
	return stream;
}

istream &operator>>(istream &stream_in, Rational &rvalue) 
{
	char s;
	stream_in >> rvalue.m; 
	if (cin.fail()) { cout << "¬ведено неверное значение"; abort(); }
	stream_in>>s; 
	if (s!='/')	{ cout << "¬ведено неверное значение"; abort(); }
	stream_in >> rvalue.n; cout << endl; 
	if (cin.fail()) { cout << "¬ведено неверное значение"; abort(); }
	rvalue.Canc();
	return stream_in; }


void Rational::Canc()
{
	if (n == 0) { cout << "«наменатель равен 0"; abort(); }
	if (m == 0) { n = 1; }
	for (int i = abs(m); i > 0; i--) {
		if (abs(m) % i == 0 && n % i == 0) {
			m = m / i; n = n / i;
			break;
		}
	}
}