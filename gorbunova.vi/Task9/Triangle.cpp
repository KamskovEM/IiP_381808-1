#include<iostream>
#include <stdio.h>
#include<conio.h>
#include<math.h>
#include"Triangle.h"

using namespace std;



class Triangle
{

public:
	Triangle() { a = b = c = p = s = 0; };
	void Set();
	bool triangle();
	void P();
	void S();
	void Show();

private:
	int a, b, c;
	int p, s;
};

int main()
{
	setlocale(LC_ALL,"rus");
	Triangle Obj;

	Obj.Set();
	if (Obj.triangle() == false) {
		cout << "Треугольник не существует!";
		system("pause>0");
		exit(1);
	}
	Obj.P();
	Obj.S();
	Obj.Show();
	system("pause>0");
	return 0;
}

void Triangle::Show() {
	cout << "Стороны Треугольника:" << endl << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl;
	cout << "Периметр = " << p << endl;
	cout << "Площадь = " << s;
}
void Triangle::P() {
	p = a + b + c;
}
void Triangle::S() {
	s = sqrt(p*(p - a)*(p - b)*(p - c));
}
bool Triangle::triangle() {
	if ((a + b) <= c || (a + c) <= b || (b + c) <= a)return false;
	return true;
}

void Triangle::Set() {
	cout << "Введите стороны треугольника a b c:\n";
	cin >> a >> b >> c;
}