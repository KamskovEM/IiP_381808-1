#pragma once
#include <string>
#include <iostream>
/*
 * большое (32+32 бит) беззнаковое число
 * выводит/вводит числа в системе счисления основания 16 или 2
 */
enum PrintType
{
	Binar,
	Hex
};
class BigNumber
{
private:
	int m_upper_part;  // старшая часть числа (32 бит)
	int m_lower_part;  // младшая часть числа (32 бит)
	PrintType pt;      // каким образом выводить на экран (с оснвание 2 или 16)

public:
	// нумерация позиций начинается с 0 (от 0 до 63)
    // возвращает бит в posotion позиции 
	bool GetBit(int position) const;
	// устанавливает значение b в указанной позиции
	void SetBit(int position, bool b);
	// устанавливает тип вывода
	void SetPrintType(PrintType _pt) { pt = _pt; }
private:
	// полусумматор
	void HalfAdder(
		bool inA,       // вход А
		bool inB,       // вход B
		bool& outSum,   // выход суммы
		bool& outC      // выход перенос разряда
	);   
	// полный сумматор
	void Adder(
		bool inC,      // вход переноса разряда
		bool inA,
		bool inB,
		bool& outSum,
		bool& outC
	);
	// нахождение обратного числа (-num)
	BigNumber Invert() const;
	// перегруженные операции
public:
	// операции сравнения
	friend bool operator==(const BigNumber numL, const BigNumber numR);
	friend bool operator!=(const BigNumber numL, const BigNumber numR);
	BigNumber operator+(const BigNumber& num);
	BigNumber operator-(const BigNumber& num);
	bool operator<(const BigNumber num);
	bool operator>(const BigNumber num);
	bool operator<=(const BigNumber num) { return !(*this > num); }
	bool operator>=(const BigNumber num) { return !(*this < num); }

	// реализация умножения путём сложения
	BigNumber operator*(const BigNumber& num);
	// реализация деления вычитанием
	BigNumber operator/(const BigNumber& num);
	BigNumber& operator=(const BigNumber& num);
	friend std::ostream& operator<< (std::ostream& out, const BigNumber& num);

public:
	//конструкторы
	BigNumber();
	// конструирует из строкового представления числа в 16-ой системе
	// невмещающуюся слева часть отбрасывает
	BigNumber(std::string HexNum); 
	~BigNumber();
};

std::ostream& operator<< (std::ostream& out, const BigNumber& num);
bool operator==(const BigNumber numL, const BigNumber numR);
bool operator!=(const BigNumber numL, const BigNumber numR);
