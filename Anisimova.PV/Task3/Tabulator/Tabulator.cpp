#include <iostream>
#include <cmath>
#include <algorithm>
#include "pch.h"
#include<clocale>
#include "Tabulator.h"
using namespace std;

//Konstryktor
Tabulator::Tabulator()
{
	a =b=0.0;
	n = 0;
	x = NULL;
	y = NULL;
}
Tabulator::Tabulator(double _a, double _b, int _n)
{
	a = _a;
	b = _b;
	n = _n;
	x = new double[n+2];
	y = new double[n+2];

	for (int i = 0; i < n+2; i++)
	{
		x[i] = 0.0;
		y[i] = 0.0;
	}
	
}
Tabulator::Tabulator(const Tabulator& t)
{
	a = t.a;
	b = t.b;
	n = t.n;
	x = new double[n+2];
	y = new double[n+2];

	for (int i = 0; i <n+2; i++)
	{
		x[i] = t.x[i];	
		y[i] = t.y[i];
	}
}
//Destryktor
Tabulator::~Tabulator()
{
	a =b = 0.0;
	n = 0;

		delete[] x;
		x = NULL;
		
		delete[] y;
		y = NULL;
	
}
//Vozvrat
double Tabulator::SetA()
{
	return a;
}
double Tabulator::SetB()
{
	return b;
}
int Tabulator::SetN()
{
	return n;
}
void Tabulator::ABN(double _a, double _b, int _n)
{
	a = _a;
	b = _b;
	n = _n;
}
//function
double f_sin(double x)
{
	return sin(x);
}
double f_cos(double x)
{
	return cos(x);
}
double f_exp(double x)
{
	return exp(x);
}
//vvod
ostream & operator << (ostream & stream, const Tabulator &at)
{
	stream << at.a << " " << at.b << " " << at.n << " "<<endl;
	for (int i = 0; i < at.n+2; i++)
	{
		stream << at.x[i] << "  " ;
	}	
	for (int i = 0; i < at.n + 2; i++)
	{
		stream << at.y[i] << "  " ;
	}
	return stream;
}

 istream & operator >> (istream & stream, Tabulator &at)
 {
	 double a1, b1;
	 int n1;
	 stream >> a1>>b1>>n1;
	 at.a = a1;
	 at.b = b1;
	 at.n = n1;

		at.x = new double[at.n+2];
		at.y = new double[at.n+2];
		
	for (int i = 0; i < at.n+2; i++)
	{
		stream >> at.x[i];
	}
	for (int i = 0; i < at.n+2; i++)
	{
		stream >> at.y[i];
	}
	return stream;
}

void Tabulator::Tabulyatsiya(Tfun _fun)
{
	f = _fun;
	double interval = (b - a) / (n + 1);

		for (int i = 0; i < n+2; i++)
		{
			x[i] = a;
			y[i] = f(x[i]);
			a += interval;
		}	
}
void Tabulator::Screen()
{
	cout << "f(x) = y" << "\n";

	for (int i = 0; i < n+2; i++)
	cout << x[i] << " = " << y[i] << endl;
}