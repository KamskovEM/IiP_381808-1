#include <iostream>
#include <locale>
#include <string>
#include "Triangle.h"

using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	Triangle t = Triangle(5, 3, 4);
	cout << "����������? " << t.isExists() << endl;
	cout << "���: " << t.type() << endl;
	cout << "�������: " << t.S() << endl;
	cout << "��������: " << t.P() << endl;
	system("pause");
}

