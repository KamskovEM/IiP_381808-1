#include "Polinom.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <locale.h>

using namespace std;

void main()
{
	int N, M, L, x;
	do
	{
		cout << "Vvedite stepen' Polinoma1, Polinoma2 v intervale [0,12]" << endl;
		cin >> N;

	} while ((N < 0) || (N>12));
	Polinom Polinom1(N), Polinom2(3);
	Polinom2[0] = 1;
	Polinom2[1] = -0.35;
	Polinom2[2] = 3;
	cout << "Vvedite coefficienti polinoma Polinom1" << endl;
	cin >> Polinom1;
	cout << "Polinom1  =  " << Polinom1 << endl << "Polinom2  =  " << Polinom2 << endl;
	//Chtenie iz file
	ifstream is;
	is.open("infilePolinom.txt"); 
	is >> L;
	Polinom Polinom3(L);
	is >> Polinom3;
	is.close();
	/////////////////////////////////////////////////
	cout << "Polinom3  =  " << Polinom3 << endl;
	cout << "Stepen' Polinoma3 = " << Polinom3.GetPower() <<  endl;
	cout << "Coefficient pri 3 stepeni = " << Polinom3.GetCoefficient(3) << endl;
	cout << "Vvedite X = ";
	cin >> x;
	cout << "Polinom3 v tochke x = " << Polinom1.CountPolinom(x) << endl;
	cout << "Proizvodnaya Polinoma 3 = " << Polinom3.derivative() << endl << "___________________________" << endl << endl;
	////////////////////////////////////////////////
	Polinom Polinom4;
	Polinom4 = Polinom1 + Polinom3;
	cout << "Polinom1 + Polinom3  =  " << Polinom4 << endl;
	Polinom2 = Polinom1;
	cout << "Polinom2 = Polinom1  =  " << Polinom2 << endl;
	//Zapis' v file
	ofstream os;
	os.open("infilePolinom.txt");
	os << Polinom3;
	os.close();
	system("pause");
}
