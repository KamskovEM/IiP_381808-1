#include "MyVector.h"



// Конструктор по умолчанию
template<typename T>
MyVector<T>::MyVector(void)
{
	cur_Length = 0;
	max_Length = INCR_BASE;
	mas = new T[INCR_BASE];
}

// Конструктор задающий длину вектора
template<typename T>
MyVector<T>::MyVector(int size)
{
	if (size < 0) {
		throw "not correct data";
	}
	max_Length = size + INCR_BASE;
	cur_Length = size;
	mas = new T[size + INCR_BASE];
}

// Конструктор задающий длину вектора и инициализирующий его элементами base
template<typename T>
MyVector<T>::MyVector(int size, T base)
{
	if (size < 0) {
		throw "not correct data";
	}
	max_Length = size + INCR_BASE;
	cur_Length = size;
	mas = new T[size + INCR_BASE];
	for (int i = 0; i < size; i++) {
		mas[i] = base;
	}
}

// Копирующий конструктор
template<typename T>
MyVector<T>::MyVector(const MyVector & vec)
{
	max_Length = vec.max_Length;
	cur_Length = vec.cur_Length;
	T *mas = new T[max_Length];
	for (int i = 0; i < max_Length; i++) {
		mas[i] = vec.mas[i];
	}
}

// Оператор индексации массива
template<typename T>
T & MyVector<T>::operator[](int index)
{
	if (index >= cur_Length || index < 0) {
		throw "not correct data";
	}
	return mas[index];
}

// Константный ператор индексации массива
template<typename T>
const T & MyVector<T>::operator[](int index) const
{
	if (index >= cur_Length || index < 0) {
		throw "array out of bounds";
	}
	return mas[index];
}

// Метод добавления нового элемента в конец вектора
template<typename T>
void MyVector<T>::push_back(T element)
{
	if (cur_Length < max_Length) {		// Если место осталось - просто добавим
		mas[cur_Length] = element;
		cur_Length++;
	}
	else {		// Иначе расширим массив на INCR_BASE и добавим элемент
		max_Length += INCR_BASE;
		T* cop = new T[max_Length];
		for (int i = 0; i < cur_Length; i++) {
			cop[i] = mas[i];
		}
		cop[cur_Length] = element;
		mas = NULL;
		mas = new T[max_Length];
		cur_Length++;
		for (int i = 0; i < cur_Length; i++) {
			mas[i] = cop[i];
		}
		cop = NULL;
	}
}

// Метод изменения размера массива
template<typename T>
void MyVector<T>::resize(int size)
{
	T* cop = new T[size + INCR_BASE];	// Создаём новый массив
	int s;		// Копируем в него элементы (сколько сможем)
	if (max_Length < size) {
		s = max_Length;
	}
	else {
		s = size;
	}
	for (int i = 0; i < s; i++) {
		cop[i] = mas[i];
	}
	cur_Length = size;		// Пересоздаём массив с заданой длиной и возвращаем элементы на место
	max_Length = size + INCR_BASE;
	mas = NULL;
	mas = new T[max_Length];
	for (int i = 0; i < s; i++) {
		mas[i] = cop[i];
	}
	cop = NULL;		// Чистим память
}

// Функция возвращающая текущий размер вектора
template<typename T>
unsigned int MyVector<T>::size()
{
	return cur_Length;
}

template<typename T>
const unsigned int MyVector<T>::size() const
{
	return cur_Length;
}

// Перегрузка присваивания вектора
template<typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> & v)
{
	max_Length = v.max_Length;
	cur_Length = v.cur_Length;
	mas = NULL;
	mas = new T[max_Length];
	for (int i = 0; i < cur_Length; i++) {
		mas[i] = v.mas[i];
	}
	return (*this);
}

// Деструктор
template <typename T>
MyVector<T>::~MyVector()
{
	mas = NULL;
	cur_Length = NULL;
	max_Length = NULL;
}
