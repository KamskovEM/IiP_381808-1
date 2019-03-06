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

	//Степень полинома в диапозоне от [0,12]
	 do
   	{
	 cout << "Введите степень полинома P в диапозоне [0,12] " << '\n';
     cin >> n;
	 } 
	 while (n<0 || n>12);
	
	
	 Polynomial P(n);
	cout << "Введите коэффициенты мономов полинома: " << '\n';
	cin >> P;

	cout << "Полином P:  " <<  P << '\n';

	cout << "Степень полинома =  "  << P.Setn() << '\n';

	cout << "Введите номер элемента, коэффициент которого нужно узнать" << '\n';
	int i;
	cin >> i;
	cout << "Коэффициент = " << P.SetCoeff(i - 1) << '\n';

	cout << "Введите значение х = " << '\n';
	int x;
	cin >> x;
	cout << "Значение полинома при введённом х = " << P.Ans(x) << '\n';

	cout << "Производная полинома= :" << P.Deriv() << '\n';




	//zapis' v fail
	ofstream os("Polynomial.txt");
	os << P;
	os.close();

	//chtenie  faila
	ifstream is("Polynomial.txt");
	is >>P;
	cout << "Данные из файла : " << P <<endl;	
	
	return 0;
}