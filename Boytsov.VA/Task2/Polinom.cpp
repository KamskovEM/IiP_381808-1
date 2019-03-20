#include "Polinom.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>

Polinom::Polinom()
{
	power = 0;
	coefficient = new double[power + 1];
	coefficient[0] = 0.0;
}

Polinom::Polinom(int _power)
{
	power = _power;
	coefficient = new double[power + 1];
	for (int i = 0; i <= power; i++)
		coefficient[i] = 0.0;
}

Polinom::Polinom(const Polinom &v)
{
	power = v.power;
	coefficient = new double[power + 1];
	for (int i = 0; i <= power; i++)
		coefficient[i] = v.coefficient[i];
}

Polinom::~Polinom()
{
	power = 0;
	delete[] coefficient;
}

int Polinom::GetPower()
{
	return power;
}

double Polinom::GetCoefficient(int i)
{
	if (i <= power)
		return coefficient[i];
	else
		return 0.0;
}

double Polinom::CountPolinom(double x)
{
	double result = 0.0;
	for (int i = 0; i <= power; i++)
	{
		result += coefficient[i] * pow(x, i);
	}
	return result;
}

Polinom Polinom::derivative()
{
	int i;
	Polinom Polinom_derivative(power - 1);
	for (i = 0; i <= power - 1; i++)
	{
		Polinom_derivative.coefficient[i] = (i + 1)*coefficient[i + 1];
	}
	return Polinom_derivative;
}

double & Polinom::operator[](int index)
{
	if (index>power || index <0)
	{
		MyPolinomExeption expt = OUTOFRANGE;
		throw expt;
	}
	return *(coefficient+index);
}

const double & Polinom::operator[](int index) const
{
	if (index>power || index <0)
	{
		MyPolinomExeption expt = OUTOFRANGE;
		throw expt;
	}
	return *(coefficient + index);
}

Polinom& Polinom::operator=(const Polinom& v)
{
		(*this).power = v.power;
		delete[](*this).coefficient;
		(*this).coefficient = new double[power + 1];
		for (int i = 0; i <= power; i++)
			(*this).coefficient[i] = v.coefficient[i];
		return *this;
}

Polinom Polinom::operator+(const Polinom& v)
{
	int i;
	if (power >= v.power)		
	{
		Polinom Polinom4(power);
		for (i = 0; i <= power; i++)
			Polinom4.coefficient[i] = coefficient[i] + v.coefficient[i];
		return Polinom4;
	}
	else		
	{
		Polinom Polinom4(v.power);
		for (i = 0; i <= v.power; i++)
			Polinom4.coefficient[i] = coefficient[i] + v.coefficient[i];
		return Polinom4;
	}
}

istream& operator>>(istream& stream, Polinom& v)
{
	for (int i = 0; i < v.power; i++)
	{
		stream >> v.coefficient[i];
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Polinom& v)
{
		int n = 0;
		if (v.coefficient[0] != 0)
			stream << v.coefficient[0];
		for (int i = 1; i <= v.power; i++)
		{
			if (v.coefficient[i] < 0)
			{
				if (v.coefficient[i] != -1)
					stream  << v.coefficient[i] << "*" << "X^" << i;
				else
					stream << "-" << "X^" << i;
			}
			else
			{
				if (v.coefficient[i] != 0)
				{
					if (v.coefficient[i] != 1)
						stream << "+" << v.coefficient[i] << "*" << "X^" << i;
					else
						stream << "+" << "X^" << i;
				}
			}
		}
		stream << endl;
	return stream;
}

istream& operator>>(ifstream& is, Polinom& v)
{
	for (int i = 0; i < v.power && !is.eof(); i++)
	{
		is >> v.coefficient[i];
	}
	return is;
}

ostream& operator<<(ofstream& os, const Polinom& v)
{
	os << "" << v.power << endl;
	for (int i = 0; i < v.power; i++)
	{
		os << "" << v.coefficient[i] << ' ';
	}
	return os;
}



