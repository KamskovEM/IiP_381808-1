#include<iostream>
#include<locale.h>
#include <fstream>

#include "MyTime.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	MyTime* a1,*a2,*a3;

	string inString;
	int inInt;

	cout << "Введите время в секундах: ";
	cin >> inInt;
	a1 = new MyTime(inInt);
	cout << "Введенное время: " << a1->GetStr() << endl;
	
	cout << "Введите время в формате 'чч:мм:сс': ";
	cin >> inString;
	a2 = new MyTime(inString);
	cout << "Введенное время в секундах: " << a2->GetInt() << endl << endl;



	a3 = new MyTime(*a2);
	cout << "Копирование: " << a3->GetStr() << endl;


	MyTime a4,a5,a6,a7,a8,a9;

	a4 = *a1;
	a5 = *a2;
	cout << "Присваивание: " << a5.GetStr() << endl;
	a6 = a4 + a5;
	cout << "Сумма: " << a6.GetStr() << endl;
	a7 = a4 - a5;
	cout << "Разность: " << a7.GetStr() << endl;

	if(a4==a5)
		cout << "Время равно друг другу" << endl;
	else
		cout << "Время НЕ равно друг другу" << endl;


	cout << "Запись в файл..." << endl;
	ofstream os;
	os.open("Times.txt");
	os << a4 << a5 << endl;
	os.close();
	
	cout << "Чтение из файла..." << endl;
	ifstream is;
	is.open("Times.txt");
	is >> a8;
	is >> a9;
	is.close();

	cout << "Прочитано:\n    1ое = " << a8.GetStr() << "\n    2ое = " << a9.GetStr() << endl;

}