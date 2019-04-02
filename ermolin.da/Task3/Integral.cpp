#include "Integral.h"

using namespace std;

Integral::Integral(double(*inFunc)(double), Interval A)
{
	a = A.a;
	b = A.b;
	koef = (A.b - A.a) / A.k;
	Func = inFunc;//ссылка на функцию
}

Integral::~Integral()
{
	a = b = koef = 0;
	Func = NULL;
}

double Integral::LeftValue()//Интеграл методом прямоугольника слева
{
	S = 0;
	for (int i = 0; a + i * koef < b; i++)
	{
		S += Func(a + i * koef)*koef;
	}
	return S;
}

double Integral::MidValue()//Интеграл методом прямоугольника средний
{
	S = 0;
	for (int i = 0; a + i * koef < b; i++)
	{
		S += Func(a + i * koef + koef / 2)*koef;
	}
	return S;
}

double Integral::RitghtValue()//Интеграл методом прямоугольника справа
{
	S = 0;
	for (int i = 0; a + i * koef < b; i++)
	{
		S += Func(a + i * koef + koef)*koef;
	}
	return S;
}

Interval Integral::GetInterval()//Возвращает интервал
{ 
	Interval A;
	A.a = a;
	A.b = b;
	A.k = (b - a) / koef;
	return A;
}
