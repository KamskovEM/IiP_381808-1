#include "Tabulating.h"

double F1(double x)
{
	return sin(x);
}

double F2(double x)
{
	return cos(x);
}

double F3(double x)
{
	return tan(x);
}

double F4(double x)
{
	return sin(x)*cos(x);
}

double F5(double x)
{
	return exp(x);
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	double a, b;		//Интервал
	int S;
	
	cout << "Введите интервал табуляции [ , ] - ";
	cin >> a >> b;
	cout << "Введите количество точек табулирования - ";
	cin >> S;
	Tabulating T(a,b,S);		//Переменная класса
	int count = -1;
	cout << "Табулирования промежутка [" << T.Checka() << "," << T.Checkb() << "] на " << T.Checkn() << " точек..." << endl;
	do {
		cout << "Выберите функцию для табуляции: " << endl;
		cout << "1) sin x " << endl;
		cout << "2) cos x " << endl;
		cout << "3) tan x " << endl;
		cout << "4) sin x * cos x " << endl;
		cout << "5) exp x " << endl;

		cin >> count;
	} while (count < 1 || count > 5);
	FTab* F;
	switch (count)
	{
	case 1:
		F = F1;
		T.Tabul(F);
		T.ResultTabul();
		break;
	
	case 2:
		F = F2;
		T.Tabul(F);
		T.ResultTabul();
		break;

	case 3:
	F = F3;
	T.Tabul(F);
	T.ResultTabul();
	break;
	
	case 4:
		F = F4;
		T.Tabul(F);
		T.ResultTabul();
		break;
	
	case 5:
		F = F5;
		T.Tabul(F);
		T.ResultTabul();
		break;
	
	}

	Tabulating T1(-10, 10, 15);
	T1.Tabul(F3);
	ofstream output;
	output.open("output1.txt");
	output << T1;
	output.close();

	
	ifstream input;
	Tabulating T2;

	input.open("input.txt");
	input >> T2;
	T2.ResultTabul();
	input.close();

	system("pause");
	return 0;
}