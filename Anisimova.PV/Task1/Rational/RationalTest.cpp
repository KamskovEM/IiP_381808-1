#include "pch.h"
#include <iostream>
#include "Rational.h"
#include <cmath>
#include <algorithm>
#include <clocale>
#include<string>

using namespace std;


int main()
{
	setlocale(LC_CTYPE, "rus");
	int n1, m1, n2, m2;

	//Vvedenie drobey 
	cout << "Vvedite drob' 1  ";
	cin >> n1 >> m1;
	Rational r1(n1, m1);
	cout << "r1 = " << r1;

	cout << "Vvedite drob' 2  ";
	cin >> n2 >> m2;
	Rational r2(n2, m2);
	cout << "r2 = " << r2;

    //zapis' v fail
	ofstream os;
	os.open("Rational.txt");
	os << r1 << r2 << endl;
	os.close();
	Rational r3, r4;
	ifstream is;

	//chtenie  faila
	is.open("Rational.txt");
	is >> r3;
	is >> r4;
	is.close();
	cout << "Dannyye faila:  " << endl<< r3 << r4 << endl;

	//Sravnenye
	if (r1 == r2)
	{ cout << "Droby ravny" << endl; }
	else
	{
		cout << "Droby ne ravny" << endl;
	}
	//arifmetich operatsii
	Rational sum, razn, pr, chast;
	sum = r1 + r2;
	cout << "r1+r2= " << sum << endl;
	razn = r1 - r2;
	cout << "r1-r2= " << razn << endl;
	pr = r1 * r2;
	cout << "r1*r2= " << pr << endl;
	chast = r1 / r2;
	cout << "r1/r2= " << chast << endl;
	   
	return 0;
}