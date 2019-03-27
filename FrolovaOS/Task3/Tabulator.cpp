#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Tabulator.h"

using namespace std;

Tabulator::Tabulator()
{
	resX = NULL;
	resY = NULL;
	n = 0;
	a = 0;
	b = 0;

}
//инициализатор
Tabulator::Tabulator(int _n, int _a, int _b)
{
	int i;
	n = _n;
	a = _a;
	b = _b;
	resX = new double[n + 1];
	resY = new double[n + 1];
}

Tabulator::Tabulator(const Tabulator &f)
{
	n = f.n;
	a = f.a;
	b = f.b;
	resX = new double[n + 1];
	resY = new double[n + 1];
	for (int i = 0; i <= n + 1; i++)
	{
		resX[i] = f.resX[i];
		resY[i] = f.resY[i];
	}
}
Tabulator::~Tabulator()
{
	if (resX != NULL) {
		delete[] resX;
		resX = NULL;
	}
	if (resY != NULL) {
		delete[] resY;
		resY = NULL;
	}

	n = 0;
	a = 0;
	b = 0;


}


Tabulator::Tabulator(Tfun * _fun)
{
	fun = _fun;
}

void Tabulator::Setn(int _n)
{
	n = _n;
}
void Tabulator::Seta(int _a)
{
	a = _a;
}
void Tabulator::Setb(int _b)
{
	b = _b;
}
void Tabulator::Tabulirovanie(Tfun * fun, double tab)
{
	resY = new double[n + 1];
	resX = new double[n + 1];
	int k = a;
	for (int i = 0; i <= n; i++)
	{
		resY[i] = ans(fun, k);
		resX[i] = k;
		k += tab;
	}
	resY[n + 1] = ans(fun, b);
	resX[n + 1] = b;

}
double Tabulator::ans(Tfun* fun, double k)
{
	double a = fun(k);
	return a;
}
void Tabulator::Show()
{
	cout << "tabulation points : " << n << endl;;
	cout << "Border of interval [ " << a << "," << b << " ]" << '\n';
	cout << "X:";
	for (int i = 0; i <= n + 1; i++)
	{
		cout << setw(10) << resX[i] << " ";
	}
	cout << "\n";
	cout << "Y:";
	for (int i = 0; i <= n + 1; i++)
	{
		cout << setw(10) << resY[i] << " ";
	}
	cout << "\n";
}
int Tabulator::Getn()
{
	return n;
}

int Tabulator::Geta()
{
	return a;
}
int Tabulator::Getb()
{
	return b;
}
double Tabulator::tab(double n, int a, int b)
{
	double tab = (b - a) / (n + 1);
	return tab;

}
ostream& operator<<(ostream& stream, const Tabulator& c) {



	stream << "\n" << c.n << " " << c.a << " " << c.b << " ";
	for (int i = 0; i <= c.n + 1; i++)
	{
		stream << c.resX[i] << " ";
	}

	for (int i = 0; i <= c.n + 1; i++)
	{
		stream << c.resY[i] << " ";
	}
	return stream;

}

istream& operator>>(istream& stream, Tabulator& c)
{
	/*int q;
	stream >> q;
	c.n = q;
	stream >> q;
	c.a = q;
	stream >> q;
	c.b = q;*/


	stream >>c.n>> c.a >> c.b;
	c.resX = new double[c.n + 1];
	c.resY = new double[c.n + 1];
	for (int i = 0; i <= c.n + 1; i++)
	{
		stream >> c.resX[i];
	}
	for (int i = 0; i <= c.n + 1; i++)
	{
		stream >> c.resY[i];
	}
	return stream;

}


