#include "Menu.h"


// Конструкторы
Menu::Menu()
{
	count = 0;
	selected = -1;
}

Menu::Menu(int s)
{
	count = s;
	elements.resize(s);
	selected = -1;
}

Menu::Menu(const Menu & m)
{
	count = m.count;
	selected = m.selected;
	elements.resize(count);
	for (int i = 0; i < count; i++) {
		elements[i] = m.elements[i];
	}
}

// Функция задаёт количество пунктов меню
void Menu::set_size(unsigned int c)
{
	count = c;
	elements.resize(c);
}

// Функция возвращает количество пунктов меню
unsigned int Menu::size()
{
	return count;
}

// Функция задаёт имя для пункта меню
void Menu::set_line(int number, string line)
{
	if (number >= count || number < 0) {
		throw exception("array out of bounds");
	}
	elements[number] = line;
}

// Функция задаёт и выводит выбраный пункт меню
string Menu::select(unsigned int i)
{
	if (i <= count) {
		selected = i - 1;
		return elements[i - 1];
	}
	else {
		throw exception("array out of bounds");
	}
}

// Функция выводит выбраный пункт меню
string Menu::show_select()
{
	if (selected == -1) {
		return string(nullptr);
	}
	else {
		return elements[selected];
	}
}

// Функция выводит меню на экран
void Menu::show(unsigned int x, unsigned int y)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = x; scrn.Y = y;
	SetConsoleCursorPosition(hOuput, scrn);
	for (int i = 0; i < count; i++) {
		SetConsoleCursorPosition(hOuput, scrn);
		cout << i + 1 << ") " << elements[i] << endl;
		scrn.Y++;
	}
	cout << endl;
}


Menu::~Menu()
{
}

istream & operator>>(istream & in, Menu & m)
{
	in >> m.count;
	for (int i = 0; i < m.count; i++) {
		in >> m.elements[i];
	}
	return in;
}

ostream & operator<<(ostream & out, const Menu & m)
{
	out << m.count;
	for (int i = 0; i < m.count; i++) {
		out << endl;
		out << m.elements[i];
	}
	return out;
}
