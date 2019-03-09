#include "Ratio.h"
#include "functions.h"
#include <iostream>
#include <cmath>
using namespace std;

Ratio::Ratio() //basic constructor
{
	int tmp;
	cin >> n;
	cin >> m;
	tmp = NOD(n, m);
	if (tmp > 1)
	{
		n = n / tmp;
		m = m / tmp;
	}

};
Ratio::Ratio(int v, unsigned int u) // constructor w_given_parameters
{
	int tmp;
	n = v;
	m = u;
	tmp = NOD(n, m);
	if (tmp > 1)
	{
		n = n / tmp;
		m = m / tmp;
	}
};

//Overloading operators
Ratio Ratio :: operator=(Ratio op)
{
	n = op.n;
	m = op.m;
	return *this;
};
Ratio Ratio :: operator+(Ratio op)
{
	int k = 0;
	Ratio tmp(0, 0);
	tmp.n = n * op.m + op.n*m;
	tmp.m = m * op.m;
	k = NOD(tmp.n, tmp.m);
	if (k > 1)
	{
		tmp.n = tmp.n / k;
		tmp.m = tmp.m / k;
	}
	return tmp;
};
Ratio Ratio :: operator*(Ratio op)
{
	int k = 0;
	Ratio tmp(0, 0);
	tmp.n = n * op.n;
	tmp.m = m * op.m;
	k = NOD(tmp.n, tmp.m);
	if (k > 1)
	{
		tmp.n = tmp.n / k;
		tmp.m = tmp.m / k;
	}
	return tmp;
};
Ratio Ratio :: operator/(Ratio op)
{
	int k = 0;
	Ratio tmp(0, 0);
	tmp.n = n * op.m;
	tmp.m = m * op.n;
	k = NOD(tmp.n, tmp.m);
	if (k > 1)
	{
		tmp.n = tmp.n / k;
		tmp.m = tmp.m / k;
	}
	return tmp;
};
Ratio Ratio :: operator-(Ratio op)
{
	int k = 0;
	Ratio tmp(0, 0);
	tmp.n = n * op.m - op.n*m;
	tmp.m = m * op.m;
	k = NOD(tmp.n, tmp.m);
	if (k > 1)
	{
		tmp.n = tmp.n / k;
		tmp.m = tmp.m / k;
	}
	return tmp;
};
bool Ratio :: operator==(Ratio op)
{
	if (n == op.n && m == op.m)
		return true;
	else
		return false;
};
bool Ratio :: operator!=(Ratio op)
{
	if (n != op.n || m != op.m)
		return true;
	else
		return false;
};
bool Ratio :: operator<(Ratio op)
{
	n = n * op.m;
	op.n *= m;
	m *= op.m;
	op.m = m;

	if (n < op.n)
		return true;
	else
		return false;
};
bool Ratio :: operator>(Ratio op)
{
	n = n * op.m;
	op.n *= m;
	m *= op.m;
	op.m = m;

	if (n > op.n)
		return true;
	else
		return false;
};
bool Ratio :: operator>=(Ratio op)
{
	n = n * op.m;
	op.n *= m;
	m *= op.m;
	op.m = m;

	if (n >= op.n)
		return true;
	else
		return false;
};
bool Ratio :: operator<=(Ratio op)
{
	n = n * op.m;
	op.n *= m;
	m *= op.m;
	op.m = m;

	if (n <= op.n)
		return true;
	else
		return false;
};
// 
std::ostream &operator<<(std::ostream &stream, Ratio obj)
{
	stream << obj.n << " / ";
	stream << obj.m << "\n";
	return stream;
}

std::istream &operator>>(std::istream &stream, Ratio obj)
{
	stream >> obj.n;
	stream >> obj.m;
	return stream;
}
Ratio :: ~Ratio() {};
