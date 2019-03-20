#include <iostream>
#include <cmath>
#include <algorithm>
#include "pch.h"
#include<clocale>
#include "Polynomial.h"
using namespace std;

//Konstryktor
Polynomial::Polynomial() { n = 0; coefficient = NULL; }
Polynomial::Polynomial(int _n)
{
	n = _n;
	coefficient = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		coefficient[i] = 0;
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
//Destryktor
Polynomial::~Polynomial() { n = 0;	 coefficient=NULL; }

//Stepen' polinoma
int Polynomial::Setn()
{
	return n;
}

//Koifficient po indeksy
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

//Polinom pri x
int Polynomial::Ans(int x)
{
	int Ans = 0;
	for (int i = 1; i <= n+1; i++)
	{
		Ans = Ans + (coefficient[i] * pow(x, i));
	}
	return Ans;
}

//Proizvodnaya
Polynomial Polynomial::Deriv()
{
	Polynomial p(n);
	for (int i = 1; i <= n; i++)
	{
		p.coefficient[i] = i *coefficient[i + 1];
	}
	return p;
}
//Operatsia index
int& Polynomial::operator[](int index)
{
	if (index < 0 || index > n + 1)
	{
		throw Exception(NotCorrectValue, index);
	}
	else
		return  coefficient[index];

}

//Operator prisvaivaniya
Polynomial& Polynomial::operator = (const Polynomial &a)
{
	if (this != &a)
	{
		if (n == a.n) 
		{
			coefficient[0] = n;
		   for (int i = 1; i <= n+1; i++)
		   {
			   coefficient[i] = a.coefficient[i];
		   }
		
		}
		else 
		{
		  n = a.n;
		  delete[] coefficient;
		  coefficient = new int[n];		
		}		
	}
	return *this;
}

//vyvod
ostream &operator<<(ostream &stream, const Polynomial &a)
{
	
	/*a.coefficient[0] = a.n;
	stream << a.coefficient[0] << " ";
		for (int i = 1; i <= a.n + 1; i++)
		{
			stream << a.coefficient[i] << " ";
		}
	
	return stream;*/
	int  n = 0;
		for (int i = 0; i <= a.n; i++)
		{
			if (a.coefficient[i] != 0)
				n++;
		}
	if (n != 0)
	{
		a.coefficient[0] = a.n;
		stream << a.coefficient[0] << " ";
			for (int i = 1; i <= a.n+1; i++)
			{				
				stream << a.coefficient[i] << " ";
			}
		
	}
	return stream;
}

istream &operator>>(istream &stream, Polynomial &a)// перегруженный оператор ввода 
{
	for (int i = 0; i <= a.n+1; i++)
	{
		stream >> a.coefficient[i];
	}
	return stream;
	
}