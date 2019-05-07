#include <iostream>
#include <clocale>
#include "Menu.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Menu m(3);
	m.set_line(0, "Старт");
	m.set_line(1, "Настройки");
	m.set_line(2, "Выход");
	m.show(0, 0);
	getchar();
	system("cls");
	m.set_size(4);
	m.set_line(2, "Моды");
	m.set_line(3, "Выход");
	m.show(0, 0);
	cout << "Веберите пункт меню: ";
	int a;
	cin >> a;
	cout << "Выбран пункт: " << m.select(a) << endl;
	cout << m.show_select();
	getchar();
	getchar();
	return 0;
}