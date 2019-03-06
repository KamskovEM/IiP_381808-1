#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

class Polynomial
{
public:
	int n;            //степень полинома
	int *coefficient; //указатель на массив коэффициентов мономов полинома 

	// Конструкторы--------------------------
	Polynomial();                   //По умолчанию
	Polynomial(int);                //Инициаализатор
	Polynomial(const Polynomial &); //Копирования
	//Деструктор---------------------------
	~Polynomial();

	// Metody -----------------------------
	int Setn();                              //Задать/узнать степень полинома
	int SetCoeff(int);                       //Узнать значение коэффициента по его номеру
	int Ans(int x);                          //Значение полинома в заданной точке х
	Polynomial Deriv();                      //производная полинома
	Polynomial operator=(const Polynomial&); //оператор присваивания
	
	//Функции ввода/вывода
	friend ostream & operator << (ostream & stream, const Polynomial &a);
	friend istream & operator >> (istream & stream, Polynomial &a);
};
ostream& operator<<(ostream & stream, const Polynomial &a);//Перегрузка вывода
istream& operator >> (istream & stream, Polynomial &a);    //Перегрузка ввода
