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
	cout << "Введите степень полинома A" << '\n';
	cin >> n;
	cout << "Введите степень полинома B" << '\n';
	cin >> m;
	Polynom A(n), B(m), D, K, Y;
	cout << "Введите коэфициенты полинома A:" << '\n';
	cin >> A;
	cout << "Введите коэфициенты полинома B:" << '\n';
	cin >> B;
	cout << "Многочлен А:" << A << '\n';
	cout <<	"Многочлен B:" << B << '\n';
	cout <<	"Многочлен D=A+B:" << (D = A + B) << '\n';
	cout <<	"Многочлен K=A-B:" << (K = A - B) << '\n';
	cout <<	"Производная от A:" << A.derivative() << '\n';
	cout <<	"Многочлен Y=A*B:" << (Y = A * B) << '\n';
	return 0;
}