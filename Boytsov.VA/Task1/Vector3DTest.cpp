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
	cout << "Координаты вектора 1: \n" << Vector1 << "\n" << "Координаты вектора 2: \n" << Vector2 << "\n" << "Координаты вектора 3: \n" << Vector3 << endl;
	Vector3 = 3.2 * Vector2;
	cout << "_______________________________________________" << endl;
	cout << "Вектор 3 умноженный на скаляр: \n" << Vector3 << endl;
	cout << "_______________________________________________" << endl;
	if (Vector1 > Vector2)
		cout << "Вектор1 длинее Вектора2" << endl;
	else if (Vector1 < Vector2)
		cout << "Вектор2 длинее Вектора1" << endl;
	else
		cout << "Длина Вектора1 равна длине Вектора2" << endl;
	Vector3D summa = Vector1 + Vector2;
	Vector3D raznost = Vector1 - Vector2;
	double op = Vector1 * Vector2;
	cout << "_______________________________________________" << endl;
	cout << "\n Сумма векторов 1 и 2 = " << summa << endl;
	cout << "\n Разность векторов 1 и 2 = " << raznost << endl;
	cout << "Произведение векторов 1 и 2 = " << op << endl << endl;
	system("pause");
	return 0;
}

