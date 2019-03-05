#include <clocale>
#include <iostream>
#include <fstream>
#include "Money.h"
using namespace std;

int main()
{
	Money a, b, c;
	int a1, a2, a3, a4;
	cout << "Vvedite summy 1 cherez probel: ";
	cin >> a1 >> a2;
	cout << endl << "Vvedite summy 2 cherez probel: ";
	cin >> a3 >> a4;
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
	if (a > b) { cout << "Summa 1 bolshe"; }
    if (a < b) { cout << "Summa 2 bolshe"; }
	if (a == b) { cout << "summa 1 = summa 2"; }
	
	getchar();
	getchar();
	return 0;
}