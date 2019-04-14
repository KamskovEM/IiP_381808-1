#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Polinom
{
private:
	
	// Поля класса
	int deg; // Степень полинома
	double* value; // Хранение коэффициентов полинома

public:
	// Конструкторы и деструктор
	Polinom(); // По умолчанию
	Polinom(int n); // Инициализатор
	Polinom(int deg, double value[]); // Инициализатор
	Polinom(const Polinom& p); // Копирование
	~Polinom(); // Деструктор

	// Методы класса
	void out(); // Вывод на консоль
	int showdeg() { return deg; }; // Показать максимальную степень полинома
	double showvalue(int n) { return value[n]; }; //Показать коэффициент выбранной степени
	double getfun(double x); // Найти значение полинома в точке
	Polinom derivative(); // Найти производную полинома

	// Перегрузка операторов
	Polinom operator+(const Polinom& p);
	Polinom & operator=(const Polinom & p);
	double& Polinom::operator[](int n);
	const double& Polinom::operator[](int n) const;

	// Перегрузка операторов ввода/вывода
	friend ostream& operator<<(ostream& stream, const Polinom& p);
	friend istream& operator>>(istream& stream, Polinom& p);
	
};
enum PolEx
{
	IndexOutOfRange
};
ostream& operator<<(ostream& stream, const Polinom& p);
istream& operator>>(istream& stream, Polinom& p);
// Описание исключений
struct PolExeption {
	PolEx type;
	string reason;
	PolExeption(PolEx t, string r) :
		type(t), reason(r)
	{}
};