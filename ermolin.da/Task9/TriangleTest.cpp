#include <iostream>
#include <locale.h>
#include "Triangle.h"

using namespace std;

double Num()//Корректность ввода сторон
{
	double k;
	while (1) {
		cin >> k;
		if (k <= 0) { cout << "Число введено неверно\n"; }
		else return k;
		getchar();
	}
}

void TriangleTest(double a, double b, double c) //Тестирующая функция
{
	Triangle ABC(a, b, c);
	if (ABC.TriangleCorrect()) { cout << "Треугольник не существует"; }
	else {
		cout << "Треугольник ";
		switch (ABC.Equiteral())
		{
		case (1): {
			cout << "равносторонний, ";
			break;
		}
		case (2): {
			cout << "равнобедренный, ";
			break;
		}
		case (0): {
			cout << "разносторонний, ";
			break;
		}
		}
		switch (ABC.Type())
		{
		case (1): {
			cout << "тупоугольный\n";
			break;
		}
		case (2): {
			cout << "прямоугольный\n";
			break;
		}
		case (3): {
			cout << "остроугольный\n";
			break;
		}
		}
		cout << "Площадь равна - " << ABC.Square() << " Периметр равен - " << ABC.Perimetr();
	}
}

int main()
{
	double a, b, c;//Переменные для сторон
	setlocale(LC_CTYPE, "Russian");//Подключение русских символов
	cout << "Введите длину стороны А (больше 0) - ";//Иннициализация сторон
	a = Num();
	cout << "Введите длину стороны B (больше 0) - ";
	b = Num();
	cout << "Введите длину стороны C (больше 0) - ";
	c = Num();
	TriangleTest(a,b,c);
	getchar();
	getchar();
	return(0);
}