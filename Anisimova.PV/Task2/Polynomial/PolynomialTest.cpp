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

	//Diapozon [0,12]
	 do
   	{
	 cout << "Vvedite stepen' polinoma P v diapozone [0,12] " << '\n';
     cin >> n;
	 } 
	 while (n<0 || n>12);
	
	
	 Polynomial P(n);
	cout << "Vvedite koefficienty monomov polinoma: " << '\n';
	cin >> P;

	cout << "Polinom P:  " <<  P << '\n';

	cout << "Stepn' polinoma =  "  << P.Setn() << '\n';

	cout << "Vvedite number element, koefficient kotorogo hotite yznat'" << '\n';
	int i;
	cin >> i;
	cout << "Koefficient = " << P.SetCoeff(i - 1) << '\n';

	cout << "Vvedite õ = " << '\n';
	int x;
	cin >> x;
	cout << "Polinom pri õ = " << P.Ans(x) << '\n';

	cout << "Proizvodnaya polinoma= :" << P.Deriv() << '\n';




	//zapis' v fail
	ofstream os("Polynomial.txt");
	os << P;
	os.close();

	//chtenie  faila
	ifstream is("Polynomial.txt");
	is >>P;
	cout << "Dannye iz faila : " << P <<endl;	
	
	return 0;
}