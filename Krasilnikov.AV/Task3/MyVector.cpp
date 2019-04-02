#include "MyVector.h"


template<typename T>
MyVector<T>::MyVector(void)
{
	cur_Length = 0;
	max_Length = INCR_BASE;
	mas = new T[INCR_BASE];
}

template<typename T>
MyVector<T>::MyVector(unsigned int size)
{
	max_Length = size;
	cur_Length = size;
	mas = new T[size];
}

template<typename T>
MyVector<T>::MyVector(unsigned int size, T base)
{
	max_Length = size;
	cur_Length = size;
	mas = new T[size];
	for (int i = 0; i < size; i++) {
		mas[i] = base;
	}
}

template<typename T>
MyVector<T>::MyVector(const MyVector & vec)
{
	max_Length = vec.max_Length;
	cur_Length = vec.cur_Length;
	T *mas = new T[cur_Length];
	for (int i = 0; i < max_Length; i++) {
		mas[i] = vec.mas[i];
	}
}

template<typename T>
T & MyVector<T>::operator[](unsigned int index)
{
	if (index >= cur_Length) {
		throw "array out of bounds";
	}
	return mas[index];
}

template<typename T>
const T & MyVector<T>::operator[](unsigned int index) const
{
	if (index >= cur_Length) {
		throw "array out of bounds";
	}
	return mas[index];
}

template<typename T>
void MyVector<T>::push_back(T element)
{
	if (cur_Length < max_Length) {
		mas[cur_Length] = element;
		cur_Length++;
	}
	else {
		max_Length += INCR_BASE;
		T* cop = new T[max_Length];
		for (int i = 0; i < cur_Length; i++) {
			cop[i] = mas[i];
		}
		cop[cur_Length] = element;
		delete[] mas;
		mas = new T[max_Length];
		cur_Length++;
		for (int i = 0; i < cur_Length; i++) {
			mas[i] = cop[i];
		}
		delete[] cop;
	}
}

template<typename T>
void MyVector<T>::pop_back()
{
	if (cur_Length == 0) {
		throw "vector is empty";
	}
	cur_Length--;
	max_Length = cur_Length;
	T* cop = new T[cur_Length];
	for (int i = 0; i < cur_Length; i++) {
		cop[i] = mas[i];
	}
	delete[] mas;
	mas = new T[max_Length];
	for (int i = 0; i < cur_Length; i++) {
		mas[i] = cop[i];
	}
	delete[] cop;
}

template<typename T>
void MyVector<T>::resize(unsigned int _size)
{
	T* cop = new T[_size];
	int m;
	if (cur_Length < _size) {
		m = cur_Length;
	}
	else {
		m = _size;
	}
	for (int i = 0; i < m; i++) {
		cop[i] = mas[i];
	}
	cur_Length = _size;
	max_Length = _size;
	delete[] mas;
	mas = new T[max_Length];
	for (int i = 0; i < m; i++) {
		mas[i] = cop[i];
	}
	delete[] cop;
}

template<typename T>
unsigned int MyVector<T>::size()
{
	return cur_Length;
}

template <typename T>
MyVector<T>::~MyVector()
{
	delete[] mas;
}
