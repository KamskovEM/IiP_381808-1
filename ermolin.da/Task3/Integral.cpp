#include "Integral.h"

using namespace std;

Integral::Integral(double(*inFunc)(double), double A, double B, int n)
{
	a = A;
	b = B;
	koef = (B - A) / n;
	Func = inFunc;
}

Integral::Integral(double(*inFunc)(double), double A, double B)
{
	a = A;
	b = B;
	Func = inFunc;
}

Integral::~Integral()
{
	a = b = koef = 0;
	Func = NULL;
}

void Integral::TrygValue(int x)
{ 
	int i;
	double a1 = a;
	S = 0;
	const double PI = 3.14159265;
	for (i = 0; a >= PI*i + PI/2 * x; i++);
	for (i; a1 < b&&PI*i + PI / 2 * x <= b; i++)
	{
		S = abs(Func(PI*i + PI / 2 * x) - Func(a1));
		cout << "Площадь функции на интервале [" << a1 << ';' << PI * i + PI / 2 * x << "] равна "
			<< abs(S) << endl;
		a1 = PI * i + PI / 2 * x;
	}
	if (PI*i + PI / 2 * x != b) {
		S = abs(Func(b) - Func(a1));
		cout << "Площадь функции на интервале [" << a1 << ';' << b << "] равна "
			<< abs(S) << endl;
	}
}

void Integral::RecValue()
{
	int i;
	S = 0;
	double a1 = a;
	for (i = 0; a1 + i * koef < b; i++) 
	{
		if (abs(S + Func(a1 + i * koef)) < abs(S))
		{
			cout << "Площадь функции на интервале [" << a1 << ';' << a1 + i * koef << "] равна " 
				<< abs(S) <<" , число отрезков равно "<<i<< endl;
			a1 = a1 + i * koef;
			i = 0;
			S = 0;
		}
		else
		{
			S += Func(a1 + i * koef)*koef;
		}
	}
	if (a1 <= b) 
	{
		cout << "Площадь функции на интервале [" << a1 << ';' << a1 + i * koef << "] равна "
			<< abs(S) << " , число отрезков равно " << i << endl;
	}
}

void Integral::ExpValue() 
{
	cout << "Площадь функции на интервале [" << a << ';' << b << "] равна "
		<< abs(Func(b) - Func(a));
}

