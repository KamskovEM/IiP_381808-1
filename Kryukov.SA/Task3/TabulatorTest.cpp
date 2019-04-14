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
	cout << "�������� ������� ��� ���������" << endl;
	cout << "1 cos" << endl;
	cout << "2 sin" << endl;
	cout << "3 ���������� � �������" << endl;
	cout << "4 ���������� �����" << endl;
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
	cout << "\n�������� �� " << A.INTER1() << " �� " << A.INTER2() << endl;
	cout << "���������� ����� " << A.Tochki1() << endl;
	// ������ � �����
	cout << "\nos A << endl;-------- " << endl;
	A.show("X", "Y");
	ofstream os; // ����� ��� ������
	os.open("Tabulator.txt"); // ���� ��� ������
	os << A << endl;
	os.close();
	// ������ �� ������
	cout << "\nis >> A; --------------------------" << endl;
	ifstream is; // ����� ��� ������
	is.open("Tabulator.txt"); // ���� ��� ������
	is >> A;
	A.show("X", "Y");
	is.close();
}
	catch (Tabulator::Range)
	{
		cout << "������� �� ���������� �� ����� ���������" << endl;
	}
	return 0;
}