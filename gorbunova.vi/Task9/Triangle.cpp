#include<iostream>
#include <stdio.h>
#include<conio.h>
#include<math.h>
#include"Triangle.h"

using namespace std;



class Triangle
{
	double a, b, c;
	double p, s;
public:
	Triangle() { a = b = c = p = s = 0; };
	void Set();
	bool triangle();
	double P();
	double S();
	void Show();

};

int main(void)
{
	setlocale(LC_ALL,"rus");
	Triangle Obj;

	Obj.Set();
	if (Obj.triangle() == false) {
		cout << "����������� �� ����������!";
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
	cout << "������� ������������:" << endl << "a = " << a << endl << "b = " << b << endl << "c = " << c << endl;
	cout << "�������� = " << P() << endl;
	cout << "������� = " << S();
}
double Triangle::P() 
{
	return a + b + c;
}
double Triangle::S() 
{
	double p;
	p = P()/2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}
bool Triangle::triangle() {
	if ((a + b) <= c || (a + c) <= b || (b + c) <= a)return false;
	return true;
}

void Triangle::Set() {
	cout << "������� ������� ������������  a b c:\n";
	cin >> a >> b >> c;
}