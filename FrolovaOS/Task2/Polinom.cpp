#include <clocale>
#include <iostream>
#include <fstream>
#include "Polinom.h"

using namespace std;

Polinom::Polinom()
{
	Coef = NULL;
	n = 0;
}

Polinom::Polinom(int an)
{
	int i;
	n = an;
	Coef = new double[n + 1];
	for (i = 0; i <= n; i++)
	{
		Coef[i] = 0;
	}
}

Polinom::Polinom(const Polinom &f)
{
	n = f.n;
	Coef = new double[n + 1];
	for (int i = 0; i <= n+1; i++)
		Coef[i] = f.Coef[i];
}

void Polinom::OutputPolinom()
{
	cout << Coef[0]<<" ";
	if (Coef[1] != 0)
	{
		cout << Coef[1];
	}
	for (int i = 2; i <= n + 1; i++)
	{
		if (Coef[i] == 0)
		{
			continue;

		}
		else if (Coef[i] > 0)
		{
			cout << " + " << Coef[i] << "X^" << i-1;
		}
		else if (Coef[i] < 0)
		{
			cout << " - " << Coef[i] << "X^" << i-1;
		}

	}
	cout << "\n";

}

Polinom::~Polinom()
{
	Coef = NULL;
	n = 0;
}


int Polinom::Getn()
{
	return n;
}


double& Polinom::operator [] (int ind)
{
	if ((ind >= 0) && (ind <= n + 1))
	{
		return Coef[ind];
	}
	else throw Exception(NotCorrectValue, ind);
}

Polinom Polinom::derivative()
{
	int i;
	Polinom Z(n-1 );
	for (i = 1; i <= n ; i++)
	{
		Z.Coef[i] = (i )*Coef[i +1];
	}
	return Z;
}

Polinom& Polinom::operator = (const Polinom &t)
{
	if (this != &t)
	{


		if (n != t.n)
		{
			n = t.n;
			delete[] Coef;
			Coef = new double[n];

		}
		for (int i = 0; i <= t.n; i++)
			Coef[i] = t.Coef[i];


	}
	return *this;
}

double Polinom::answer(double x)
{
	double ans = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		ans = ans + (Coef[i] * pow(x, i));
	}
	return ans;
}


istream &operator>>(istream &s, Polinom &c)
{
	int i;
	int k;
	s >> k;
	if (k != 0)
	{
		c.Coef[0] = k;
		for (i = 1; i <= k+1; i++)
			//for (i = 1; i < k + 1; i++)-------------- if we need number of coefficients
		{
			s >> c.Coef[i];
		}
	}
	
	else 
	{
		for (i = 0; i <= c.n + 1; i++)
		{
			s >> c.Coef[i];
		}
	}
	return s;
}

ostream &operator<<(ostream &s, const Polinom &c)
{
	int i, n = 0;
	if (c.Coef[0] == 0)
	{
		c.Coef[0] = c.n ;
		//c.Coef[0] = c.n + 1; ---------- if we need number of coefficients

		for (i = 0; i <= c.n + 1; i++)
		{
			s << c.Coef[i] << " ";
		}
	}
	else 
	{
		for (i = 0; i <= c.n + 1; i++)
		{
			s << c.Coef[i] << " ";
		}
	}
	return s;
}
