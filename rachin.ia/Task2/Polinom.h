#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
#include <cmath>
#include <locale.h>
using namespace std;



class Polinom
{
public:
	//Конструкторы
	Polinom();  //По умолчанию
	Polinom(const Polinom& i);  //Копирования
	Polinom(int _k);	//Инициализации
	//Деструктор
	~Polinom();
	Polinom operator+(const Polinom& i);   //Перегрузка сложения
	Polinom& operator=(const Polinom& i);   //Перегрузка присваивания
	double& operator[](int j);		//Индексация
	int Checkn()	//Вернуть степень полинома 
	{
		return k;
	};
	double CheckCoef(int i)		//Вернуть коэффициент данного члена полинома
	{
		if (i <= k) 
		{
			return coef[i];
		}
		else { return 0; }
	};
	void Output();	//Вывод полинома в консоль
	friend ostream& operator<<(ostream& stream, const Polinom& c);	//Перегрузка Вывода
	friend istream& operator>>(istream& stream, Polinom& c);		//Перегрузка Ввода
	double FuncVal(double x);		//Значение полинома в заданной точке
	Polinom devar();		//Производная
	
private:
	int k;  //Степень полинома
	double *coef;	//Указатель на коэф. члена полинома определённой степени

};

ostream& operator<<(ostream& stream, const Polinom& c);		//Вывод
istream& operator>>(istream& stream, Polinom& c);	//Ввод
//Исключение
enum Exc 
{ WrongValue };
struct Excep
{
	Exc overflow;
	int d;
	Excep(Exc _overflow, int _d)
	{
		overflow = _overflow;
		d = _d;
	}

};

