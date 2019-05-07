#pragma once
#include "MyVector.h"
#include "Event.h"
#include <iostream>
#include <string>

using namespace std;

class FloorScales
{
private:
	string start;	// Начальная дата, задаётся при создании объекта
	int count_people;	// Количетсво человек, которые хранят весы
	MyVector<MyVector<Event>> people;	// Вектор векторов взвешиваний для каждого человека
	MyVector<string> name;	// Вектор имён пользователей
public:
	FloorScales(string _start);		// Конструктор
	FloorScales(const FloorScales& fs);		// Конструктор копирования
	void add_person(string _name);	// Метод добавляющий человека
	string get_start();		// Функция возвращает начальную дату
	void add_event(string _name, int day, int month, int year, int weight);		// Функция задаёт взвешивание по имени и дате
	double get_event(string _name, int day, int month, int year);	// Функция возвращает вес по дате
	double average_weight(string _name, int month, int year);	// Функция возвращает средний вес для определённого человека за указынй месяц и год
	double average_weight(string _name);	// Функция возвращает средний вес для определённого человека за всё время
	pair<double, string> max_weight(string _name, int month, int year);		// Функция возвращает максимальный вес для определённого человека за указынй месяц и год и дату
	pair<double, string> max_weight(string _name);	// Функция возвращает максимальный вес для определённого человека за всё время и дату
	pair<double, string> min_weight(string _name, int month, int year);	// Функция возвращает минимальный вес для определённого человека за указынй месяц и год и дату
	pair<double, string> min_weight(string _name);	// Функция возвращает минимальный вес для определённого человека за всё время и дату
	friend ostream& operator<<(ostream& stream, const FloorScales& fs);	// Вывод в поток
	friend istream& operator>>(istream& stream, FloorScales& fs);	// Ввод в поток
	~FloorScales();		// Деструктор
};
