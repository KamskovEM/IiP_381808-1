#include "Poly.h"
#include <cmath>



Poly::Poly()  // basic cunstructor
{
	st = 0;
	znach = new double[st + 1];
	znach[0] = 0;
}
unsigned int Poly::degree(Poly &op)  // returns polynomial degree
{
	st = op.st;
	return st;
};
unsigned int Poly::polysize(Poly &op)  // returns the size of the polynomial
{
	unsigned int i = op.st;
	while (i == 0)
	{
		i--;
	}
	return i;
};
double Poly::koeff(Poly &op, int i) // returns the koefficient 
{
	double val;
	val = op.znach[i];
	return val;
}
double Poly::polyval(Poly &op, double x) // returns the value of the polynomial in x
{
	int tmp = 0;
	for (int i = 0; i <= op.st; i++)
		tmp += znach[i] * pow(x, i);
	return tmp;

}
Poly  Poly::deriv(Poly &op) // returns the derivative
{
	int i = 0, j = 0;
	Poly tmp(op.st - 1);
	for (i, j = i + 1; j <= op.st; i++, j++)
		tmp.znach[i] = op.znach[j] * j;
	return tmp;
};

Poly::Poly(unsigned int tmp)  // constructor w_given_parameters
{
	st = tmp;
	znach = new double[st + 1];
	for (int i = 0; i <= st; i++)
		znach[i] = 0.0;
}


Poly& Poly :: operator=(Poly op)
{
	for (int i = 0; i <= st; i++)
		znach[i] = 0.0;
	delete[] znach;
	st = op.st;
	znach = new double[st + 1];
	for (int i = 0; i <= st; i++)
		znach[i] = op.znach[i];

	return *this;
};


std::ostream &operator<<(std::ostream &stream, Poly obj)
{

	for (int i = obj.st; i >= 1; i--)
	{
		if (obj.znach[i] != 0)
		{

			stream << obj.znach[i];
			stream << " * " << " x ^ " << i << " + ";
		}
	}
	stream << obj.znach[0];

	return stream;
}

std::istream &operator>>(std::istream &stream, Poly obj)
{

	for (int i = obj.st; i >= 1; i--)
	{
		stream >> obj.znach[i];
	}
	stream >> obj.znach[0];

	return stream;
}
Poly::~Poly()
{
	//	delete[] znach;
}
