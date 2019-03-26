#include<iostream>
#include "Integral.h"

using namespace std;

int main()
{
	double a, b;//границы интеграла
	int k;
	setlocale(LC_ALL, "Russian");//русский язык
	while (1)//меню выбора
	{
		system("cls");
		cout << "1.Интеграл синуса\n2.Интеграл косинуса\n3.Интеграл экспоненты\n0.Выход\n\n\n\n\n";
		std::cin >> k;
		switch (k)
		{
		case(1)://интеграл синуса
		{
			system("cls");
			cout << "Выберите метод вычисления интеграла\n1.Интеграл методом прямоугольника\n2.Определенный интеграл\n\n\n\n";
			std::cin >> k;
			if (k == 1) {
				system("cls");
				cout << "Введите левую грануцу интервала ";
				std::cin >> a;
				cout << "Введите правую грануцу интервала ";
				std::cin >> b;
				if (a > b) {
					cout << "Границы введены неверно";
					getchar();
					getchar();
					break;
				}
				cout << "Введите количество отрезков ";
				std::cin >> k;
				system("cls");
				Integral c(sin, a, b, k);
				c.RecValue();
				getchar();
				getchar();
			}
			if (k == 2) {
				system("cls");
				cout << "Введите левую грануцу интервала ";
				std::cin >> a;
				cout << "Введите правую грануцу интервала ";
				std::cin >> b;
				if (a > b) {
					cout << "Границы введены неверно";
					getchar();
					getchar();
					break;
				}
				system("cls");
				Integral c(cos, a, b);
				c.TrygValue(0);
				getchar();
				getchar();
			}
			break;
		}

		case(2)://интеграл косинуса
		{
			system("cls");
			cout << "Выберите метод вычисления интеграла\n1.Интеграл методом прямоугольника\n2.Определенный интеграл\n\n\n\n";
			std::cin >> k;
			if (k == 1) {
				system("cls");
				cout << "Введите левую грануцу интервала ";
				std::cin >> a;
				cout << "Введите правую грануцу интервала ";
				std::cin >> b;
				if (a > b) {
					cout << "Границы введены неверно";
					getchar();
					getchar();
					break;
				}
				cout << "Введите количество отрезков ";
				std::cin >> k;
				system("cls");
				Integral c(cos, a, b, k);
				c.RecValue();
				getchar();
				getchar();
			}
			if (k == 2) {
				system("cls");
				cout << "Введите левую грануцу интервала ";
				std::cin >> a;
				cout << "Введите правую грануцу интервала ";
				std::cin >> b;
				if (a > b) {
					cout << "Границы введены неверно";
					getchar();
					break;
				}
				system("cls");
				Integral c(sin, a, b, k);
				c.TrygValue(-1);
				getchar();
				getchar();
			}
			break;
		}
		case(3)://интеграл экспоненты
		{
			system("cls");
			cout << "Выберите метод вычисления интеграла\n1.Интеграл методом прямоугольника\n2.Определенный интеграл\n\n\n\n";
			std::cin >> k;
			if (k == 1) {
				system("cls");
				cout << "Введите левую грануцу интервала ";
				std::cin >> a;
				cout << "Введите правую грануцу интервала ";
				std::cin >> b;
				if (a > b) {
					cout << "Границы введены неверно";
					getchar();
					getchar();
					break;
				}
				cout << "Введите количество отрезков ";
				std::cin >> k;
				system("cls");
				Integral c(exp, a, b, k);
				c.RecValue();
				getchar(); 
				getchar();
			}
			if (k == 2) {
				cout << "Введите левую грануцу интервала ";
				std::cin >> a;
				cout << "Введите правую грануцу интервала ";
				std::cin >> b;
				if (a > b) {
					cout << "Границы введены неверно";
					getchar();
					getchar();
					break;
				}
				system("cls");
				Integral c(exp, a, b);
				c.ExpValue();
				getchar();
				getchar();
			}
			break;
		}
		case (0): return 0;
		default:
			break;
		}
	}
}