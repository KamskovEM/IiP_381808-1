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

void Triangle::TestT()			//Тип треугольника
{
	double a = A, b = B, c = C;

	
		if (c*c > a*a + b * b || b * b > a*a + c * c || a * a > b*b + c * c)	//Тупоугольный
		{ cout << "Treugolnik tupougolniy\n"; }					
		else
		{
			if (c*c == a * a + b * b || b * b == a * a + c * c || a * a == b * b + c * c) {			//Прямоугольный
				cout << "Treugolnik pryamougolniy\n";
			}
			else { cout << "Treugolnik ostrougolniy\n"; }			//Остроугольный
		}
	
};

double Triangle::Perm() {
	return A + B + C;  //Периметр
};

double Triangle::Area() {
	double p = (A + B + C) / 2;
	return sqrt(p*(p - A)*(p - B)*(p - C));  //Площадь
};

void Triangle::Sides(double a, double b, double c) {
	A = a; B = b; C = c;    //Присвоение сторон

};

void InputSides(double *a, double *b, double *c) {  //Ввод сторон
	
	cin >> *a;
	cin >> *b;
	cin >> *c;

}

