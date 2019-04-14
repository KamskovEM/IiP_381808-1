#include <iostream>
#include <cstdlib>
#include "FloorScales.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	FloorScales scale("07.04.2019");
	string name;
	int day, month, year, weight;
	char q = 1;
	while (q != '0') {
		system("cls");
		cout << "Выберите действие:" << endl;
		cout << "1 - Узнать начальную дату наблюдений" << endl;
		cout << "2 - Добавить человека" << endl;
		cout << "3 - Добавить наблюдение" << endl;
		cout << "4 - Узнать вес по дате" << endl;
		cout << "5 - Узнать максимальный вес" << endl;
		cout << "6 - Узнать средний вес" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "Выберите нужный пункт и нажмите Enter: " << endl;
		cin >> q;
		switch (q)
		{
		case '0':
			break;
		case '1':
			system("cls");
			cout << "Начальная дата наблюдений: " << scale.get_start() << endl;
			system("pause");
			break;
		case '2':
			system("cls");
			cout << "Введите имя человека: " << endl;
			cin >> name;
			try
			{
				scale.add_person(name);
			}
			catch (const exception& ex)
			{
				cout << ex.what() << endl;
				system("pause");
				break;
			}
			cout << "Человек " << name << " добавлен!" << endl;
			system("pause");
			break;
		case '3':
			system("cls");
			cout << "Введите имя человека: " << endl;
			cin >> name;
			cout << "Введите день: " << endl;
			cin >> day;
			cout << "Введите месяц: " << endl;
			cin >> month;
			cout << "Введите год: " << endl;
			cin >> year;
			cout << "Введите вес: " << endl;
			cin >> weight;
			try
			{
				scale.add_event(name, day, month, year, weight);
			}
			catch (const exception & ex)
			{
				cout << ex.what() << endl;
				system("pause");
				break;
			}
			cout << "Взвешивание добавленно!" << endl;
			system("pause");
			break;
		case '4':
			system("cls");
			cout << "Введите имя человека: " << endl;
			cin >> name;
			cout << "Введите день: " << endl;
			cin >> day;
			cout << "Введите месяц: " << endl;
			cin >> month;
			cout << "Введите год: " << endl;
			cin >> year;
			try
			{
				cout << scale.get_event(name, day, month, year);
			}
			catch (const exception& ex)
			{
				cout << ex.what() << endl;
				system("pause");
				break;
			}
			system("pause");
			break;
		case '5':
			system("cls");
			cout << "Введите имя человека: " << endl;
			cin >> name;
			try
			{
				cout << scale.max_weight(name).first << endl;
			}
			catch (const exception& ex)
			{
				cout << ex.what() << endl;
				system("pause");
				break;
			}
			system("pause");
			break;
		case '6':
			system("cls");
			cout << "Введите имя человека: " << endl;
			cin >> name;
			try
			{
				cout << scale.average_weight(name) << endl;
			}
			catch (const exception& ex)
			{
				cout << ex.what() << endl;
				system("pause");
				break;
			}
			system("pause");
			break;
		default:
			cout << "Вы ввели некорректное значение" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}
