#include <iostream>
#include <string.h>
#include <locale.h>
#include "Vector3D.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Vector3D Vector1(7.3, 1.9, 2.1), Vector2(6, 0, 2), Vector3;
	Vector3 = Vector2;
	cout << "���������� ������� 1: \n" << Vector1 << "\n" << "���������� ������� 2: \n" << Vector2 << "\n" << "���������� ������� 3: \n" << Vector3 << endl;
	cout << "_______________________________________________" << endl;
	Vector3D summa = Vector1 + Vector2;
	Vector3D raznost = Vector1 - Vector2;
	double pr = Vector1 * Vector2;
	cout << "\n ����� �������� 1 � 2 = " << summa << endl;
	cout << "\n �������� �������� 1 � 2 = " << raznost << endl;
	cout << "������������ �������� 1 � 2 = " << pr << endl << endl;
	cout << "_______________________________________________" << endl;
	Vector3 = 3.2 * Vector2;
	cout << "������ 3 ���������� �� ������: \n" << Vector3 << endl;
	cout << "_______________________________________________" << endl;
	if (Vector1 > Vector2)
		cout << "������1 ������� �������2" << endl;
	else if (Vector1 < Vector2)
		cout << "������2 ������� �������1" << endl;
	else
		cout << "����� �������1 ����� ����� �������2" << endl;

	system("pause");
	return 0;
}