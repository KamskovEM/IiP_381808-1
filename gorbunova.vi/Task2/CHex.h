#pragma once
#include <iostream>

class Hex
{
public:
	Hex(int _size); // конструктор класса
	Hex(const Hex &obj); // конструктор копирования
	~Hex(); // декструктор
	Hex& operator=(const Hex &obj); // оператор присваивания

	Hex operator+(const Hex &obj); // оператор сложения
	Hex operator-(const Hex &obj); // оператор вычитания
	Hex operator*(const Hex &obj); // оператор умножения

	bool operator==(const Hex &obj); // оператор сравнения: переводит числа в десятичную систему счисления и сравнивает их между собой
	bool operator!=(const Hex &obj); // отрицание оператора ==
	bool operator>=(const Hex &obj); // оператор сравнения: переводит числа в десятичную систему счисления и сравнивает их между собой
	bool operator<=(const Hex &obj); // оператор сравнения: переводит числа в десятичную систему счисления и сравнивает их между собой
	bool operator>(const Hex &obj); // отрицание оператора <=
	bool operator<(const Hex &obj); //  отрицание оператора >=

	friend std::ostream& operator<<(std::ostream &stream, const Hex &obj); 
	friend std::istream& operator>>(std::istream &stream, Hex &obj); 
	
	unsigned char *pmem;
	int size;
};
