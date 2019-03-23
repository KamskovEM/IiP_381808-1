#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Tabulator.h"
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int count = 5;
	double a1 = -5.0;
	double b1 = -10.0;
	Tabulator A(count, a1, b1);
	Tfun ff;
	try
	{
	Tabulator A(count, a1, b1);
	int menu;
	cout << "выберите функцию для табуляции" << endl;
	cout << "1 cos" << endl;
	cout << "2 sin" << endl;
	cout << "3 возведение в квадрат" << endl;
	cout << "4 извлечение корня" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
	{
		ff = ff1;
		A.Tabulirovanie(ff);
		A.show("X", "Y");
		break;
	}
	case 2:
	{
		ff = ff2;
		A.Tabulirovanie(ff);
		A.show("X", "Y");
		break;
	}
	case 3:
	{
		ff = ff3;
		A.Tabulirovanie(ff);
		A.show("X", "Y");
		break;
	}
	case 4:
	{
		ff = ff4;
		A.Tabulirovanie(ff);
		A.show("X", "Y");
		break;
	}
	}
	A.INTERVAL(a1, b1);
	A.Tochki(count);
	cout << "\nинтервал от " << A.INTER1() << " до " << A.INTER2() << endl;
	cout << "количество точек " << A.Tochki1() << endl;
	// Запись в поток
	cout << "\nos A << endl;-------- " << endl;
	A.show("X", "Y");
	ofstream os; // поток для записи
	os.open("Tabulator.txt"); // файл для записи
	os << A << endl;
	os.close();
	// Чтение из потока
	cout << "\nis >> A; --------------------------" << endl;
	ifstream is; // поток для чтения
	is.open("Tabulator.txt"); // файл для чтения
	is >> A;
	A.show("X", "Y");
	is.close();
}
	catch (Tabulator::Range)
	{
		cout << "Функция не определена на таком интервале" << endl;
	}
	return 0;
}