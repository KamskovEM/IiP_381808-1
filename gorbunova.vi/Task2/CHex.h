#pragma once
#include <iostream>

class Hex
{
	unsigned char *pmem; 
	int size; 

	int hex2int(unsigned char c) const;
	unsigned char int2hex(int i) const;
public:
	Hex(int _size); // конструктор инициализации
	Hex(const Hex &obj); // конструктор копирования
	~Hex(); // декструктор
	Hex& operator=(const Hex &obj); // оператор присваивания

	Hex operator+(const Hex &obj); // сложение "столбиком"
	Hex operator-(const Hex &obj); // вычитание "столбиком"

	bool operator==(const Hex &obj); // покомпонентное сравнение
	bool operator!=(const Hex &obj); // отрицание оператора ==
	bool operator>=(const Hex &obj); // покомпонентное сравнение
	bool operator<=(const Hex &obj); // покомпонентное сравнение
	bool operator>(const Hex &obj); // отрицание оператора <=
	bool operator<(const Hex &obj); // отрицание оператора >=

	friend std::ostream& operator<<(std::ostream &stream, const Hex &obj); 
	friend std::istream& operator>>(std::istream &stream, Hex &obj);
};

