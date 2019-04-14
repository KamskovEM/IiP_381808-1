#pragma once
#include <iostream>

// Класс вектор
// Был создан для удобной работы с динамическими массивами

template <typename T>
class MyVector
{
private:
	T *mas;		// Массив элементов вектора
	int cur_Length;	// Текущая длина массива
	int max_Length;	// Максимальная длина массива
	const int INCR_BASE = 8;	// Константа, на которую увеличивается массив при нехватке места
public:
	MyVector(void);		// Конструктор по умолчанию
	MyVector(int size);		// Конструктор задающий длину вектора
	MyVector(int size, T base);		// Конструктор задающий длину вектора и инициализирующий его элементами base
	MyVector(const MyVector& vec);	// Копирующий конструктор
	T & operator[](int index);		// Оператор индексации массива
	const T & operator[](int index) const;		// Константный ператор индексации массива
	void push_back(T element);		// Метод добавления нового элемента в конец вектора
	void resize(int size);		// Метод изменения размера массива
	unsigned int size();	// Функция возвращающая текущий размер вектора
	const unsigned int size() const;
	MyVector<T>& operator=(const MyVector<T>& v);	// Перегрузка присваивания вектора
	~MyVector();	// Деструктор
};
