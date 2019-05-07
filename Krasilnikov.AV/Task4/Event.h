#pragma once
#include <iostream>
#include <string>

using namespace std;

// Класс Event (слежебный)
// Создан для хранения событий взвешивания
// Хранит дату взвешивания и вес, который наблюдался в эту дату

class Event
{
private:
	unsigned int day;	// День взвешивания
	unsigned int month;		// Месяц взвешивания
	unsigned int year;		// Год взвешивания
	double weight;		// Вес
public:
	Event(void);	// Конструктор по умолчанию
	Event(int _day, int _month, int _year, double _weight);		// Конструктор инициализатор, задаёт событие взвешивания
	Event(const Event& e);	// Конструктор копирования
	double get_weight();	// Функция возвращает вес
	string get_date();	// Функция возвращает дату в формате строки
	void set_weight(double _weight);	// Функция переопределяет вес
	bool check_time(int _day, int _month, int _year);	// Функция сравнивает дату события с поступившей от пользователя
	bool check_month(int _month, int _year);	// Функция проверяет принадлежность события к заданому месяцу (т.е. было ли это в взвешивание в заданном месяце)
	friend ostream& operator<<(ostream& stream, const Event& e);
	friend istream& operator>>(istream& stream, Event& e);
	~Event();	// Деструктор
};
