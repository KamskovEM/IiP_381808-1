#pragma once
#include <iostream>
#include <math.h>

class Integral
{
private:
	double a;//левая граница
	double b;//правая граница
	double koef;//длина стороны прямоугольника
	double S;//Площадь
	double(*Func)(double);//ссылка на функцию
public:

	Integral(double(*inFunc)(double), double, double, int);//Конструктор для метода прямоугольника
	Integral(double(*inFunc)(double), double, double);//Конструктор для определенного интеграла

	~Integral();//деструктор

	void TrygValue(int x);//Определенный интеграл для тригонометрических функций
	void RecValue();//Интеграл методом прямоугольника
	void ExpValue();//Определенный интеграл экспоненты
};

