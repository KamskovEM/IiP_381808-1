#pragma once
#include <iostream>
#include <math.h>

struct Interval//интервал
{
public:
	double a;//левая граница
	double b;//правая граница
	int k;//число отрезков

};

class Integral
{
private:
	double a;//левая граница
	double b;//правая граница
	double koef;//длина стороны прямоугольника
	double S;//Площадь
	double(*Func)(double);//ссылка на функцию
public: 
	Integral(double(*inFunc)(double), Interval);//Конструктор

	~Integral();//деструктор

	double LeftValue();//Интеграл методом прямоугольника слева
	double MidValue();//Интеграл методом прямоугольника средний
	double RitghtValue();//Интеграл методом прямоугольника справа
	Interval GetInterval();//Возвращает интервал
};

