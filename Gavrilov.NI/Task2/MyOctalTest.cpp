#include <iostream>
#include<locale.h>

#include "MyOctal.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	MyOctal a1,a2,a3;
	cout << "��� ����������� ���� �������� � ��������� �� ���� \"�����-������-�����\"" << endl;
	cout << "������� ����������� ����� 'a1'(������� ��� �����, ����� ���� �����) : ";
	cin >> a1;
	cout << "������� ����������� ����� 'a2'(������� ��� �����, ����� ���� �����) : ";
	cin >> a2;
	a3 = a1;
	cout << "������������ 'a3=a1'. a3 = " << a3<<endl;
	cout << "�� ����� �����:";
	cout << a1+a2<<endl;
	cout << "�� �������� �����:";
	cout << a1-a2<<endl;
	cout << "a1 "<<(a1==a2?"=":"!")<<"= a2"<<endl;

	cout << "������ � ����..." << endl;
	ofstream os;
	os.open("Octal.txt");
	os << a1 << a2 << endl;
	os.close();

	MyOctal a4, a5;
	cout << "������ �� �����..." << endl;
	ifstream is;
	is.open("Octal.txt");
	is >> a4;
	is >> a5;
	is.close();

	cout <<"a1: "<<a4<<endl;
	cout <<"a2: "<<a5<<endl;
}