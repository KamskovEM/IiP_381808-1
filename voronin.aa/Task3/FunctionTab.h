#pragma once
#include<iostream>
#include<fstream>
#include<cmath>
class FunctionTab
{
private:

	// Поля класса
	double interval_a; // Начало интервала
	double interval_b; // Конец интервала
	int count; // Количество точек табулирования
	double* points; // Хранение точек табулирования
	double* value; // Хранение значений функции в точках табулирования

public:
	// Конструкторы и деструктор
	FunctionTab(); // По умолчанию
	FunctionTab(double _i1, double _i2,int _n); // Инициализатор
	FunctionTab(const FunctionTab& _f); // Копирование
	~FunctionTab(); // Деструктор

	// Методы класса
	void setinterval(double _a, double _b);  //Установить интервал
	void setcount(int _n); // Установить количество точек
	double showinterval_a() { return interval_a ; }; // Показать начало интервала
	double showinterval_b() { return interval_b; };  // Показать конец интервала
	int showcount() { return count; }; //Показать количество точек
	void do_tab(double(*function)(double)); // Выполнить табулирование функции
	void get_tab(); // Вывести результат вычисления


	// Перегрузка операторов ввода/вывода
	friend std::ostream& operator<<(std::ostream& stream, const FunctionTab& _f);
	friend std::istream& operator>>(std::istream& stream, FunctionTab& _f);

};
double function1(double _x); 
double function2(double _x); 
double function3(double _x); 
double function4(double _x);
double function5(double _x);
double function6(double _x);
double function7(double _x);
