#include<iostream>
#include<locale.h>
#include <fstream>

#include "MyTime.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	MyTime* a1,*a2,*a3;

	string inString;
	int inInt;

	cout << "������� ����� � ��������: ";
	cin >> inInt;
	a1 = new MyTime(inInt);
	cout << "��������� �����: " << a1->GetStr() << endl;
	
	cout << "������� ����� � ������� '��:��:��': ";
	cin >> inString;
	a2 = new MyTime(inString);
	cout << "��������� ����� � ��������: " << a2->GetInt() << endl << endl;



	a3 = new MyTime(*a2);
	cout << "�����������: " << a3->GetStr() << endl;


	MyTime a4,a5,a6,a7,a8,a9;

	a4 = *a1;
	a5 = *a2;
	cout << "������������: " << a5.GetStr() << endl;
	a6 = a4 + a5;
	cout << "�����: " << a6.GetStr() << endl;
	a7 = a4 - a5;
	cout << "��������: " << a7.GetStr() << endl;

	if(a4==a5)
		cout << "����� ����� ���� �����" << endl;
	else
		cout << "����� �� ����� ���� �����" << endl;


	cout << "������ � ����..." << endl;
	ofstream os;
	os.open("Times.txt");
	os << a4 << a5 << endl;
	os.close();
	
	cout << "������ �� �����..." << endl;
	ifstream is;
	is.open("Times.txt");
	is >> a8;
	is >> a9;
	is.close();

	cout << "���������:\n    1�� = " << a8.GetStr() << "\n    2�� = " << a9.GetStr() << endl;

}