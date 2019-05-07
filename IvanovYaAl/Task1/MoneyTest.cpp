#include <clocale>
#include <iostream>
#include <fstream>
#include "Money.h"

int main() {
	Money x, y;
	int x1, x2, x3, x4;
	int del, umn;
	cout << "Enter x1 (rub1) " << endl;
	cin >> x1;
	x.getX(x1);
	cout << "Enter x2 (kop1) " << endl;
	cin >> x2;
	x.getY(x2);
	cout << "Enter x3 (rub2) " << endl;
	cin >> x3;
	y.getX(x3);
	cout << "Enter x4 (kop2)  " << endl;
	cin >> x4;
	y.getY(x4);
	cout << "Enter the number of divide " << endl;
	cin >> del;
	cout << "Enter the number of multiplication " << endl;
	cin >> umn;

	cout << "x + y = " << x + y << endl;
	cout << "y + x = " << y + x << endl;
	cout << "x - y = " << x - y << endl;
	cout << "y - x = " << y - x << endl;
	cout << "x * " << umn << " = " << x * umn << endl;
	cout << "x / " << del << " = " << x / del << endl;
	cout << "y * " << umn << " = " << y * umn << endl;
	cout << "y / " << del << " = " << y / del << endl;

	if (x == y) {
		cout << "Summi odinakovie" << endl;
	}
	else if (x > y) {
		cout << "Pervaya summa bol'she " << endl;
	}
	else if (x < y) {
		cout << "Vtoraya summa bol'she" << endl;
	}
	system("pause");
	return 0;
}