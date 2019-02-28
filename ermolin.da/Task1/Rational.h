#pragma once
#include <iostream>

using namespace std;

class Rational
{
private:
	int m, n;//числитель и знаменатель
public:
	//Конструкторы-------------------------
	Rational();//стандартный
	Rational(int m);//преобразователь типа
	Rational(Rational&c);//копирования
	Rational(int m, int n);//инициализаци
	//Деструктор-------------------------
	~Rational();
	//Перегрузки---------------------------
	Rational operator + (const Rational & b);//сложение дробей
	Rational operator + (int b);//сложение с целым числом
	Rational operator- (const Rational & b);//разность дробей
	Rational operator- (int b);//вычитание целого
	Rational operator* (const Rational & b);//произведение дробей
	Rational operator* (int b);//умножение на целое
	Rational operator/ (const Rational & b);//деление дробей
	Rational operator/ (int b);//деление на число
	Rational operator= (const Rational & b);//присвоение дроби
	Rational operator= (int b);//присвоение целого
	bool operator== (const Rational & b);//равенство дробей
	bool operator== (int b);//равенство с целым
	bool operator< (const Rational & b);//сравнение дробей, а<b
	bool operator< (int b);//сравнение дробей, а<b
	bool operator> (const Rational & b);//сравнение дробей, а>b
	bool operator> (int b);//сравнение дробей, а>b
	bool operator<= (const Rational & b);//сравнение дробей, а<=b
	bool operator<= (int b);//сравнение дробей, а<=b
	bool operator>= (const Rational & b);//сравнение дробей, а>=b
	bool operator>=(int b);//сравнение дробей, а>=b
	friend ostream& operator<< (ostream& stream, const Rational & b);//перегрузка вывода
	friend istream& operator>> (istream& stream, Rational & b);//перегрузка ввода
	//Методы------------------------------
public:
	void SetM(int M) { m = M; }//изменение числителя
	void SetN(int N) { n = N; }//изменение знаменателя
	int GetM() { return m; }//вывод числителя
	int GetN() { return n; }//вывод знаменателя
private:
	void Canc();//сокращение дроби
	void Canc(int d);//деленить на d пока делится
};

