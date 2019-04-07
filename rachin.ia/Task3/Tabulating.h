#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
typedef double FTab(double);		//Указатель на функцию


class Tabulating
{
private:
	double a, b;		//Интервал
	int n;		//Количество точек табулирования
	double *AX, *FY;		//Массив значений аргумента и функции 
	FTab* F;		
public:
	Tabulating();		//Конструктор по умолчанию
	Tabulating(double _a, double _b, int _n);		//Конструктор инициализации
	Tabulating(const Tabulating &);		//Конструктор копирования
	~Tabulating();		//Деструктор
	int Checkn();		//Узнать число точек табулирования
	double Checka();		//Узнать начало интервала
	double Checkb();		//Узнать конец интервала
	void Tabul(FTab* F);			//Табулирование
	void ResultTabul();		//Вывод результатов табулирования
	friend ostream& operator<<(ostream& stream, const Tabulating& c);	//Перегрузка Вывода
	friend istream& operator>>(istream& stream, Tabulating& c);		//Перегрузка Ввода

};

ostream& operator<<(ostream& stream, const Tabulating& c);
istream& operator>>(istream& stream, Tabulating& c);		



