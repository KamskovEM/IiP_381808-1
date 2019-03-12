#include "pch.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <clocale>
#include<fstream>
#include<string>
#include "Polynomial.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;


	cout << "Vvedite stepen' polinoma P v diapozone  " << '\n';
	cin >> n;

	Polynomial P(n);


	cout << "Vvedite koefficienty monomov polinoma: " << '\n';
	for (int i = 0; i <= n; i++)
	{
		cin >> P[i];

	}

	cout << "Polinom P:  " << P << '\n';

	cout << "Stepn' polinoma =  " << P.Setn() << '\n';


	cout << "Vvedite õ = " << '\n';
	int x;
	cin >> x;
	cout << "Polinom pri õ = " << P.Ans(x) << '\n';

	cout << "Proizvodnaya polinoma= :" << P.Deriv() << '\n';


	int ind;
met:
	try {
		cout << "Vvedite number element, koefficient kotorogo hotite yznat'" << '\n';

		cin >> ind;
		P[ind - 1];
	}
	catch (Exception& except) {
		cout << "Element number " << except.ind
			<< " is not exist" << endl;
		goto met;
	}
	cout << P[ind - 1] << '\n';

	//zapis' v fail
	ofstream os("Polynomial.txt");
	os << P;
	os.close();

	//chtenie  faila
	ifstream is("Polynomial.txt");
	is >> P;
	cout << "Dannye iz faila : " << P << endl;

	return 0;
}