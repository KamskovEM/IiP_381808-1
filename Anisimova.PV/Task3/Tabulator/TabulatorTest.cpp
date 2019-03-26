#include "pch.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <clocale>
#include<fstream>
#include<string>
#include "Tabulator.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double a, b;
	int n;

		cout << "Vvedite interval [a,b]   " << '\n';
		cin >> a >> b;
		cout << "Vvedite kolichestvo tochek   " << '\n';
		cin >> n;

		Tabulator T(a, b, n);

		T.ABN(a, b, n);
		cout << "Interval [" << T.SetA() << "; " << T.SetB() << "] " << '\n';
		cout << "Chislo tochek n= " << T.SetN() << '\n';
		//Menu
		cout << "Choice function for tabulirovanya:" << '\n' <<
			"1. sin(x)" << '\n' <<
			"2. cos(x)" << '\n' <<
			"3. exp(x)" << '\n';

		Tfun* ff;

        int fvar;
		cin >> fvar;

		switch (fvar)
		{
		case 1:
		{
			ff = f_sin;
			T.Tabulyatsiya(ff);
			break;
		}
		case 2:
		{
			ff = f_cos;
			T.Tabulyatsiya(ff);
			break;
		}
		case 3:
		{
			ff = f_exp;
			T.Tabulyatsiya(ff);
			break;
		}		
		}

		T.Screen();

    //zapis' v fail
	ofstream os("Tabulator.txt");
	os << T ;
	os.close();

	//chtenie  faila
	ifstream is("Tabulator.txt");
	is >> T;
	is.close();
	

	return 0;
}
