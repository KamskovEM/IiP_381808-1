#include <iostream>
#include <string.h>
#include <locale.h>
#include "Vector3D.h"
//Version 1
using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	Vector3D Vector1(1.3, 2.4, 1.1), Vector2(1, 3, 0), Vector3;
	Vector3 = Vector2;
	cout << "���������� ������� 1: \n" << Vector1 << "\n" << "���������� ������� 2: \n" << Vector2 << "\n" << "���������� ������� 3: \n" << Vector3 << endl;
	Vector3 = 3.2 * Vector2;
	cout << "_______________________________________________" << endl;
	cout << "������ 3 ���������� �� ������: \n" << Vector3 << endl;
	cout << "_______________________________________________" << endl;
	if (Vector1 > Vector2)
		cout << "������1 ������ �������2" << endl;
	else if (Vector1 < Vector2)
		cout << "������2 ������ �������1" << endl;
	else
		cout << "����� �������1 ����� ����� �������2" << endl;
	Vector3D summa = Vector1 + Vector2;
	Vector3D raznost = Vector1 - Vector2;
	double op = Vector1 * Vector2;
	cout << "_______________________________________________" << endl;
	cout << "\n ����� �������� 1 � 2 = " << summa << endl;
	cout << "\n �������� �������� 1 � 2 = " << raznost << endl;
	cout << "������������ �������� 1 � 2 = " << op << endl << endl;
	system("pause");
	return 0;
}

