#include "Polinom.h"
#include<fstream>
#include<iostream>
#include<string>
#include<locale>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "russian");
    // Тест инициализатора
	double mas[13];
	for (int i = 0; i < 13; i++)
		mas[i] = i;
	Polinom a(12, mas);
	cout << "Инициализация- ";
	a.out();
	cout<< endl;


	// Тест вывода степени и значений
	int testdeg;
	int testvalue;
	testdeg = a.showdeg();
	testvalue = a.showvalue(5);
	a.out();
	cout << "Степень а = " << testdeg << endl;
	cout << "Значение монома 5 степени = " << testvalue << endl;
	 
	// Тест нахождения функции
	int t = a.getfun(1);
	cout << "Значение функции= " << t << endl;


	Polinom c;

	// Тест производной
	c = a.derivative();
	cout << "Производная= ";  c.out();
	cout << endl;

	// Тест оператора присваивания
	Polinom f;
	f = a;
	cout << "Оператор = ";
	f.out();
	cout<< endl;


	// Тест оператора сложения
	Polinom test_1(10,mas), test_2(12,mas);
	Polinom res;
	res = test_1 + test_2;
	cout << "Оператор + ";
	res.out();
	cout << endl;

	// Тест вывода в файл
	ofstream fo;
	fo.open("test.txt");
	fo << c;
	fo.close();

	// Тест ввода из файла
	ifstream fi;
	fi.open("test.txt");
		Polinom d(12,mas);
		fi >> d;
		fi.close();
		
	system("pause");
	return 0;
	
}