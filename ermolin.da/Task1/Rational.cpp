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

Rational::Rational(Rational & c)
{
	c.m = m; c.n = n;
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
	return Rational(m=b.m,n=b.n);
}

Rational Rational::operator=(int b)
{
	return Rational(m=b,1);
}

bool Rational::operator==(const Rational & b)
{
	if (m == b.m && n == b.n) { return true; }
	return false;
}

bool Rational::operator==(int b)
{
	if (m == b) { return true; }
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

istream & operator>>(istream & stream, Rational & b)
{
	cout << "Числитель: ";
	stream >> b.m;
	cout << "Знаменатель: ";
	stream >>b.n;
	b.Canc();
	return stream;
}


void Rational::Canc()
{
	if (n == 0) {
	cout << "Ошибка, знаменатель равен 0\n";
	abort(); 
	}
	if (m == 0) { n = 1; }
	for (int i = 2; i <= m&&i <= n; i++) {
		Canc(i);
	}
}

void Rational::Canc(int d)
{
	while (!(abs(m) % d) && !(abs(n) % d) && m >= d && n >= d)
	{
		m = m / d; n = n / d;
	}
}