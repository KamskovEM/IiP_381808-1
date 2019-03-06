#include <iostream>
#include <cmath>
#include <algorithm>
#include "pch.h"
#include<clocale>
#include "Polynomial.h"
using namespace std;

//Конструктор
Polynomial::Polynomial() { n = 0; coefficient = 0; }
Polynomial::Polynomial(int _n)
{
	n = _n;
	coefficient = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		coefficient[i] = {};
	}
}
Polynomial::Polynomial(const Polynomial& a)
{
	n = a.n;
	coefficient = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		coefficient[i] = a.coefficient[i];
	}
}
//Деструктор
Polynomial::~Polynomial() {	n = 0;	delete [] coefficient; }

//Степень полинома
int Polynomial::Setn()
{ 
	return n;
}

//Коэффициент по индексу
int Polynomial::SetCoeff(int i)
{
	if (i <= n)
	{
		return coefficient[i];
	}
	else
	{
		return 0;
	}
}

//Полином при заданном х
int Polynomial::Ans(int x)
{
	int Ans = 0;
	for (int i = 0; i <= n ; i++)
	{
		Ans = Ans + (coefficient[i] * pow(x, i));
	}
	return Ans;
}

//Производная
Polynomial Polynomial::Deriv()
{
	Polynomial p(n - 1);
	for (int i = 0; i < n ; i++)
	{
		p.coefficient[i] = (i + 1)*coefficient[i + 1];
	}
	return p;
}

//Оператор присваивания 
Polynomial Polynomial::operator = (const Polynomial &a)
{
	if (this != &a)
	{
		n = a.n;
		coefficient = new int[n + 1];
		for (int i = 0; i <= n; i++)
		{
			coefficient[i] = a.coefficient[i];
		}
	}
	return *this;
}

//Перегруженный оператор вывода 
ostream& operator<<(ostream & stream, const Polynomial & a)
{
	int  n = 0;
	for (int i = 0; i <= a.n; i++) // цикл проверки, если коэффициент 0
	{
		if (a.coefficient[i] != 0)
			n++;
	}
	if (n != 0)
	{
		if (a.coefficient[0] != 0) 
		{
			stream << a.coefficient[0];
		}
		for (int i = 1; i <= a.n; i++)
		{
			if (a.coefficient[i] < 0)
			{
					stream << a.coefficient[i] << "*x^" << i;
			}
			else
			{
				if (a.coefficient[i] > 0)
				{
					stream << "+" << a.coefficient[i] << "*x^" << i;
				}
				else stream << "+" << "0*x^" << i;
			}
		}
		stream << '\n';
	}
	else
	{
		stream << 0;
	}
	return stream;
}

// перегруженный оператор ввода
istream& operator>>(istream & stream, Polynomial & a)
{
	
	for (int i = 0; i <= a.n; i++)
	{
		stream >> a.coefficient[i];
	}
	return stream;
}