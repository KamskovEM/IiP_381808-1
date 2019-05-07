#include "Triangle.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <clocale>

using namespace std;

void outputMenu() {
	cout<<"Viberite deystvie:\n";
	cout<<"1 - Vivod tipa treugolnika\n";
	cout<<"2 - Vivod perimetra\n";
	cout<<"3 - Vivod ploshadi\n";
	cout<<"4 - Vivod obsh'ey informacii\n";
	cout<<"5 - <New task>\n";
	cout<<"0 - <Exit>\n";

}

void Triangle::TestT()			//��� ������������
{
	double a = A, b = B, c = C;

	
		if (c*c > a*a + b * b || b * b > a*a + c * c || a * a > b*b + c * c)	//������������
		{ cout << "Treugolnik tupougolniy\n"; }					
		else
		{
			if (c*c == a * a + b * b || b * b == a * a + c * c || a * a == b * b + c * c) {			//�������������
				cout << "Treugolnik pryamougolniy\n";
			}
			else { cout << "Treugolnik ostrougolniy\n"; }			//�������������
		}
	
};

double Triangle::Perm() {
	return A + B + C;  //��������
};

double Triangle::Area() {
	double p = (A + B + C) / 2;
	return sqrt(p*(p - A)*(p - B)*(p - C));  //�������
};

void Triangle::Sides(double a, double b, double c) {
	A = a; B = b; C = c;    //���������� ������

};

void InputSides(double *a, double *b, double *c) {  //���� ������
	
	cin >> *a;
	cin >> *b;
	cin >> *c;

}

