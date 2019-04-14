#include <iostream>
#include <locale.h>
#include "Triangle.h"

using namespace std;

double Num()//������������ ����� ������
{
	double k;
	while (1) {
		cin >> k;
		if (k <= 0) { cout << "����� ������� �������\n"; }
		else return k;
		getchar();
	}
}

void TriangleTest(double a, double b, double c) //����������� �������
{
	Triangle ABC(a, b, c);
	if (ABC.TriangleCorrect()) { cout << "����������� �� ����������"; }
	else {
		cout << "����������� ";
		switch (ABC.Equiteral())
		{
		case (1): {
			cout << "��������������, ";
			break;
		}
		case (2): {
			cout << "��������������, ";
			break;
		}
		case (0): {
			cout << "��������������, ";
			break;
		}
		}
		switch (ABC.Type())
		{
		case (1): {
			cout << "������������\n";
			break;
		}
		case (2): {
			cout << "�������������\n";
			break;
		}
		case (3): {
			cout << "�������������\n";
			break;
		}
		}
		cout << "������� ����� - " << ABC.Square() << " �������� ����� - " << ABC.Perimetr();
	}
}

int main()
{
	double a, b, c;//���������� ��� ������
	setlocale(LC_CTYPE, "Russian");//����������� ������� ��������
	cout << "������� ����� ������� � (������ 0) - ";//�������������� ������
	a = Num();
	cout << "������� ����� ������� B (������ 0) - ";
	b = Num();
	cout << "������� ����� ������� C (������ 0) - ";
	c = Num();
	TriangleTest(a,b,c);
	getchar();
	getchar();
	return(0);
}