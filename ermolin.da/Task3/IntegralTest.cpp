#include<iostream>
#include "Integral.h"

using namespace std;

Interval InNum()//функция ввода границ интервала 
{
	Interval a1;
	try {
		cout << "Введите левую границу интервала" << endl;
		cin >> a1.a;
		cout << "Введите правую границу интервала" << endl;
		cin >> a1.b;
		cout << "Введите количество отрезков" << endl;
		cin >> a1.k;
		if (a1.a >= a1.b) {
			throw 1;
		}
		if (a1.k <= 0) {
			throw 2;
		}
		return a1;
	}
	catch (int a) {
		system("cls");
		cout << "Значение введено неверно" << endl;
		getchar();
		getchar();
		system("cls");
		InNum();
	}
}

double X(double x) { return x; }

int main()
{
	Interval A;//границы интеграла
	setlocale(LC_ALL, "Russian");//русский язык
	A = InNum();//ввод интервала
	Integral B(X, A);
	A = B.GetInterval();
	cout << "Интервал [" << A.a << ',' << A.b << "], количество отрезков " << A.k << endl;
	cout <<"Значение для метода левых прямоугольников "<< B.LeftValue() << endl;
	cout << "Значение для метода средних прямоугольников " << B.MidValue() << endl;
	cout << "Значение для метода правых прямоугольников " << B.RitghtValue() << endl;
}