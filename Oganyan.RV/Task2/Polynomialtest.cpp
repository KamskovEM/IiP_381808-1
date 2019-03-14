#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Polynomial.h"
#define MAX 13;
using namespace std;
void main() {
	setlocale(LC_ALL, "Rus");
	int n1;
	cout << "Введите степень полинома: " << endl;
	cin >> n1;
	Polynomial Poly(n1);
	cout << "Введите коэффиценты (от меньшего к большему): " << endl;
	cin >> Poly;
	cout << "Ваш полином: " << Poly << endl;
	cout << "Введите индекс коэффицента, значение которого хотите узнать: " << endl;
	int index2;
	cin >> index2;
	cout << "Значения коэффицента с индексом " << index2 << " равно: " << Poly[index2] << endl;
	cout << "Степень полинома: " << Poly.GetPolydegree() << endl;
	cout << "Введите точку, в которой хотите найти значение полинома" << endl;
	int x;
	cin >> x;
	cout << "Значение полинома в заданной точке x = " << x << " равно " << Poly.Polyfunvalue(x) << endl;
	cout << "Производная полинома " << Poly.Polydifferential() << endl;

	// Тест необязательных методов
	Polynomial test;
	cout << "Тест полинома, задающегося не через перегрузку ввода, а через методы " << endl;
	int tetetest;
	cout << "Введите степень нового полинома: " << endl;
	cin >> tetetest;
	test.SetPolydegree(tetetest);
	test.SetPolycoeffs();
	cout << "Ваш полином: " << test << endl;

	//Ввод в файл и вывод из файла
	//Вывод нашего полинома Poly в файл
	ofstream out;
	out.open("output.txt");
	out << Poly;
	out.close();
	// Ввод полинома из файла
	Polynomial text1file(2);
	ifstream in;
	in.open("input.txt");
	in >> text1file;
	in.close();
	cout << " Считано из файла 'input.txt': " << text1file << endl;
	/*
	Вывод программы выглядит следующим образом:
	Введите степень полинома
	4
	Введите коэффиценты (от меньшего к большему):
	5 4 3 0 2
	Ваш полином: 2*х^4+3*х^2+4*х^1+5
	Введите индекс коэффицента, значение которого хотите узнать
	2
	Значения коэффицента с индексом 2 равно: 3
	Степень попинона: 4
	Введите точку, в которой хотите найти значение полинома
	-1
	Значение попинона в заданной точке х = -1 равно 6
	Производная полинома 8*х^3+6*х^1+4
	Тест полинома, задающегося не через перегрузку ввода, а через методы
	Введите степень нового полинома
	3
	 Ввод козффицентов монома с помощью метода SetPolycoeffs
	 5 Ч 3 2
	 Ваш полином: 2*х^3+3*х^2+4*х^1+5
	Считано из файла 'test1.txt': 1*х^2+3*х^1+3
	Как выглядит input.txt : 3 3 1
	Как выглядит output.txt : 2*x^4+3*x^2+4*x^1+5
	*/

}