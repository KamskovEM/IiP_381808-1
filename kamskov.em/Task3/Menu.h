#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

class Menu
{
private:
	unsigned int count; //Количество пунктов меню 
	string *arr; //Массив подписей пунктов
	unsigned int current; //Выбранный пункт
	COORD currentPosition; //Позиция отрисованного меню

public:
	Menu(); //Конструктор по умолчанию
	Menu(int); //Конструктор инициализатор
	Menu(const Menu&); //Конструктор копирования
	Menu(istream&); //Конструктор вывода меню из файла

	~Menu();

	int GetCount() const  { return count; } //Возврат количества элементов 
	int GetLast() const { return current; } //Возврат последнего выбранного элемента
	void SetItem(int n, const string&); //Задание названия пункта
	void Show(int x = -1, int y = -1); //Вывод меню на экран
	int Input(); //Выбор пункта меню каким-то образом
	

	friend std::ostream& operator<<(std::ostream& stream, const Menu&);
	friend std::istream& operator>>(std::istream& stream, Menu&);
};

enum Exeption {OutOfRange, InvalidStream};

