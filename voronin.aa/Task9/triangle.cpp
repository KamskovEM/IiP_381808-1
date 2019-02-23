#include <iostream>
#include<locale.h>
#include"triangle.h"

using namespace std;
triangle::triangle() {
	a = 0.0;
	b = 0.0;
	c = 0.0;
}
triangle::triangle(double x, double y, double z) {
	a = x;
	b = y;
	c = z;
};
triangle:: triangle(const triangle& A) {
	triangle B;
	B.a = A.a;
	B.b = A.b;
	B.c = A.c;
	
}
triangle::~triangle() {
	a = 0;
	b = 0;
	c = 0;
}
char max(double a, double b, double c) {
	if (a >= b && a >= c) return 'a';
	if (b >= a && b >= c) return 'b';
	if (c >= a && c >= b) return 'c';
}

	bool triangle::ifexist(double a, double b, double c) {
		if (a + b <= c) return 0;
		if (b + c <= a) return 0;
		if (a + c <= b) return 0;
		else return 1;
	}

	int triangle::type(double a, double b, double c) {
		if (max(a, b, c) == 'c') {
			if (pow(c, 2) > pow(a, 2) + pow(b, 2))
				return 1;
			if (pow(c, 2) == pow(a, 2) + pow(b, 2))
				return 2;
			if (pow(c, 2) < pow(a, 2) + pow(b, 2))
				return 3;
		}
		if (max(a, b, c) == 'a') {
			if (pow(a, 2) > pow(c, 2) + pow(b, 2))
				return 1;
			if (pow(a, 2) == pow(c, 2) + pow(b, 2))
				return 2;
			if (pow(a, 2) < pow(c, 2) + pow(b, 2))
				return 3;
		}
		if (max(a, b, c) == 'b') {
			if (pow(b, 2) > pow(c, 2) + pow(a, 2))
				return 1;
			if (pow(b, 2) == pow(c, 2) + pow(a, 2))
				return 2;
			if (pow(b, 2) < pow(c, 2) + pow(a, 2))
				return 3;
		}
	}
	double triangle::p(double a, double b, double c) {
		return a + b + c;
	}
	double triangle::s(double a, double b, double c) {
		return sqrt(p(a, b, c) / 2 * (p(a, b, c) / 2 - a)*(p(a, b, c) / 2 - b)*(p(a, b, c) / 2 - c));
	}

int main() {
	setlocale(LC_CTYPE, "Russian");
	bool ex;
	triangle A;
	cout << "Введите стороны треугольника" << endl;
	cin >> A.a >> A.b >> A.c;
	ex = A.ifexist(A.a, A.b, A.c);
	cout << "Cуществует ли треугольник? - ";
	if (ex == 1)
		cout << "Да";
	else cout << "Нет";
	cout << endl;
	if (A.type(A.a, A.b, A.c) == 1) cout << "Вид треугольника - тупоугольный" << endl;
	if (A.type(A.a, A.b, A.c) == 2) cout << "Вид треугольника - прямоугольный" << endl;
	if (A.type(A.a, A.b, A.c) == 3) cout << "Вид треугольника - остроугольный" << endl;
	cout << "Периметр- ";
	cout << A.p(A.a, A.b, A.c);
	cout << endl;
	cout << "Площадь- ";
	cout << A.s(A.a, A.b, A.c);
	system("pause");
	return 0;
}