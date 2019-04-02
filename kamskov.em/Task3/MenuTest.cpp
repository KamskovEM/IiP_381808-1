#include <iostream>
#include <string>
#include <fstream>

#include "Menu.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream is;
	is.open("test.txt");


	Menu menu(is);
	menu.Show(0,0);
	int i = menu.Input();
	cout << "Вы выбрали пункт меню:" << i << endl;
	cout << menu.GetCount() << endl;
	cout << menu.GetLast() << endl;
	while (true) //Ввод пользователем названий пунктов меню
	{
		cout << "Какой пункт меню вы бы хотели ввести? Введите '-1', чтобы выйти" << endl;
		int c;
		cin >> c;
		if (c == -1) break;
		cout << "Как бы вы хотели назвать выбранный пункт меню?" << endl;
		string tmp;
		cin >> tmp;
		menu.SetItem(c, tmp);
	}
	menu.Show();
	menu.Input();
	try // Проверка исключений
	{
		menu.SetItem(4, "Пункт 4");
	}
	catch (Exeption i)
	{
		if (i == OutOfRange) cout << "\nВы вышли за пределы меню" << endl;
	}
}