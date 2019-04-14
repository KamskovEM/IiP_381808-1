#include "Ratio.h"
#include "functions.h"
#include <iostream>
#include <cmath>
using namespace std;

Ratio::Ratio() //basic constructor
{

};
Ratio::Ratio(int v,  int u) // constructor w_given_parameters
{
	int tmp;
	n = v;
	m = u;
	tmp = NOD(abs(n), m);
	if (tmp > 1)
	{
		n = n / tmp;
		m = m / tmp;
	}	
	if (m < 0 && n >= 0)
	{
		n = n * (-1);
		m = m * (-1);
	}
	
};
void Ratio::cut(Ratio& op, int t)
{
	op.n = op.n / t;
	op.m = op.m / t;

	
}
//Overloading operators
Ratio& Ratio :: operator=(Ratio op)
{
	n = op.n;
	m = op.m;
	return *this;
};
Ratio Ratio :: operator+(Ratio& op)
{
	int k = 0;
	Ratio tmp(n * op.m + op.n * m, m * op.m);
	k = NOD(abs(tmp.n), abs(tmp.m));
	if (k > 1)
	{
		cut(tmp, k);
	}
	return tmp;
};
Ratio Ratio :: operator*(Ratio& op)
{
	int k = 0;
	Ratio tmp(n * op.n, m * op.m);
	k = NOD(abs(tmp.n), abs(tmp.m));
	if (k > 1)
	{
		cut(tmp, k);
	}
	return tmp;
};
Ratio Ratio :: operator/(Ratio& op)
{
	int k = 0;
	Ratio tmp(n * op.m, m * op.n);
	k = NOD(abs(tmp.n), abs(tmp.m));
	if (k > 1)
	{
		cut(tmp, k);
	}	

	return tmp;
};
Ratio Ratio :: operator-(Ratio& op)
{
	int k = 0;
	Ratio tmp(n * op.m - op.n*m, m * op.m);
	k = NOD(abs(tmp.n), abs(tmp.m));
	if (k > 1)
	{
		cut(tmp, k);
	}
	return tmp;
};
bool Ratio :: operator==(Ratio& op)
{
	if (n == op.n && m == op.m)
		return true;
	else
		return false;
};
bool Ratio :: operator!=(Ratio& op)
{
	if (n != op.n || m != op.m)
		return true;
	else
		return false;
};
bool Ratio :: operator<(Ratio& op)
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
bool Ratio :: operator>(Ratio& op)
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
bool Ratio :: operator>=(Ratio& op)
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
bool Ratio :: operator<=(Ratio& op)
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
