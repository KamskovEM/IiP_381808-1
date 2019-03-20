#include <iostream>
#include<locale.h>

#include "MyOctal.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	MyOctal a1,a2,a3;
	cout << "все восмеричные чила вводятся и выводятся по типу \"длина-пробел-число\"" << endl;
	cout << "Введите восмеричное число 'a1'(сначала его длину, затем само число) : ";
	cin >> a1;
	cout << "Введите восмеричное число 'a2'(сначала его длину, затем само число) : ";
	cin >> a2;
	a3 = a1;
	cout << "присваивание 'a3=a1'. a3 = " << a3<<endl;
	cout << "их сумма равна:";
	cout << a1+a2<<endl;
	cout << "их разность равна:";
	cout << a1-a2<<endl;
	cout << "a1 "<<(a1==a2?"=":"!")<<"= a2"<<endl;

	cout << "Запись в файл..." << endl;
	ofstream os;
	os.open("Octal.txt");
	os << a1 << a2 << endl;
	os.close();

	MyOctal a4, a5;
	cout << "Чтение из файла..." << endl;
	ifstream is;
	is.open("Octal.txt");
	is >> a4;
	is >> a5;
	is.close();

	cout <<"a1: "<<a4<<endl;
	cout <<"a2: "<<a5<<endl;
}