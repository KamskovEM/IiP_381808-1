#include<iostream>
#include<fstream>
#include <cstring>
#include <string.h>
#include"Polynom.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int n, m;
	cout << "������� ������� �������� A" << '\n';
	cin >> n;
	cout << "������� ������� �������� B" << '\n';
	cin >> m;
	Polynom A(n), B(m), D, K, Y;
	cout << "������� ����������� �������� A:" << '\n';
	cin >> A;
	cout << "������� ����������� �������� B:" << '\n';
	cin >> B;
	cout << "��������� �:" << A << '\n';
	cout <<	"��������� B:" << B << '\n';
	cout <<	"��������� D=A+B:" << (D = A + B) << '\n';
	cout <<	"��������� K=A-B:" << (K = A - B) << '\n';
	cout <<	"����������� �� A:" << A.derivative() << '\n';
	cout <<	"��������� Y=A*B:" << (Y = A * B) << '\n';
	return 0;
}