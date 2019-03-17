#include <iostream>
#include <cstring>
#include <locale>
#include <fstream>
#include "Octal.h"

using namespace std;

void main()
{
	setlocale(0, "");
	Octal a, b, e, d;
	// vvod chisel
	cout << "Vvedite 2 chisla v 8 sisteme schisleniya" << endl;
	cin >> a >> b;
	// proverka operacii sravneniya
	if (a == b) cout << a << " = " << b << endl;
	else
		if (a > b) cout << a << " > " << b << endl;
		else
			cout << a << " < " << b << endl;
	string str;
	cout << "Vvedite chislo(proverka konstruktora pr. tipa iz stroki)" << endl;
	cin >> str;
	Octal c(str); // proverka operatora pr. tipa iz stroki
	cout << "Vi vveli - " << c << endl;
	// proverka operatorov
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	// proverka vvoda/vivoda v fail:
	ofstream in("file.txt");
	cout <<"Vvedite 2 chisla na vvod v fail"<<endl;
	cin >> e >> d;
	in << e << " " << d;
	in.close();
	ifstream out("file.txt"); //Чтение из файла
	out >> b >> a;
	cout << "Chtenie iz faila: " << e << " " << d << endl;
	getchar();
	getchar();
}

