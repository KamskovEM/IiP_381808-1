#include "Event.h"


// Конструктор по умолчанию
Event::Event()
{
	day = 0;
	month = 0;
	year = 0;
}

// Конструктор инициализатор, задаёт событие взвешивания
Event::Event(int _day, int _month, int _year, double _weight)
{
	day = _day;
	month = _month;
	year = _year;
	weight = _weight;
}

// Конструктор копирования
Event::Event(const Event & e)
{
	day = e.day;
	month = e.month;
	year = e.year;
	weight = e.weight;
}

// Функция возвращает вес
double Event::get_weight()
{
	return weight;
}

// Функция возвращает дату в формате строки
string Event::get_date()
{
	string s = "";
	if (day <= 9) {
		s += '0';
	}
	s += day;
	s += '.';
	if (month <= 9) {
		s += '0';
	}
	s += month;
	s += '.';
	s += year;
	return s;
}

// Функция переопределяет вес
void Event::set_weight(double _weight)
{
	weight = _weight;
}

// Функция сравнивает дату события с поступившей от пользователя
bool Event::check_time(int _day, int _month, int _year)
{
	if (day == _day && month == _month && year == _year) {
		return true;
	}
	else {
		return false;
	}
}

// Функция проверяет принадлежность события к заданому месяцу (т.е. было ли это в взвешивание в заданном месяце)
bool Event::check_month(int _month, int _year)
{
	if (month == _month && year == _year) {
		return true;
	}
	else {
		return false;
	}
}

// Деструктор
Event::~Event()
{
	day = NULL;
	month = NULL;
	year = NULL;
	weight = NULL;
}

ostream & operator<<(ostream & stream, const Event & e)
{
	stream << e.day << ' ' << e.month << ' ' << e.year << ' ' << e.weight;
	return stream;
}

istream & operator>>(istream & stream, Event & e)
{
	stream >> e.day >> e.month >> e.year >> e.weight;
	return stream;
}
