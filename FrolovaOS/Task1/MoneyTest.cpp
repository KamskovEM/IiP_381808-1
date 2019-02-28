#include <clocale>

#include <iostream>

#include <fstream>
#include "Money.h"
using namespace std;




int main()
{
	Money a, b, c;
	int a1, a2, a3, a4;
	cout << "Enter the number of rubles(a) ";
	cin >> a1;
	cout << endl << "Enter the number of kopecks(a) ";
	cin >> a2;
	cout << endl << "Enter the number of rubles(b) ";
	cin >> a3;
	cout << endl << "Enter the number of kopecks(b)  ";
	cin >> a4;
	a.setA(a1);
	a.setB(a2);
	b.setA(a3);
	b.setB(a4);

	c = a + b;
	cout << endl << "a+b = ";
	cout << c << endl;
	c = a - b;

	cout << "a-b = ";
	cout << c << endl;
	c = a * 2;
	cout << "a*2 = ";
	cout << c << endl;
	c = a / 2;
	cout << "a/2 = ";
	cout << c << endl;
	if (a == b) { cout << "the amount of money is the same"; }

	else if (a > b) { cout << "The first has more money than the second"; }
	else if (a < b) { cout << "The second has more money than the first"; }


	getchar();
	getchar();
	return 0;





}