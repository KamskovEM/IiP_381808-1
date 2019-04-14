#pragma once
#include <string>
#include <iostream>
#include <locale>
#include "Octal.h"

enum ExceptionType { NotCorrectValue };

struct Exception
{
	ExceptionType ExeptionCode;
	int ErrorPosition;
	Exception(ExceptionType _ExceptionType, int _ErrorPosition)
	{
		ExeptionCode = _ExceptionType;
		ErrorPosition = _ErrorPosition;
	}
};

Octal::Octal()
{
	length = 0;
	number = NULL;
}

Octal::Octal(unsigned int length)
{
	this->length = length;
	number = new unsigned char[length];
}

Octal::Octal(const Octal &_c)
{
	length = _c.length;
	number = new unsigned char[length];
	for (int i = 0; i < length; i++)
	{
		number[i] = _c.number[i];
	}
}

Octal::Octal(const std::string str)
{
	length = str.length();
	number = new unsigned char[length];
	for (int i = 0; i < length; i++)
	{
		if (str[length - 1 - i] - '0' < 8 && str[length - 1 - i] - '0' >= 0) number[i] = str[length - 1 - i] - '0';
		else
			throw Exception(NotCorrectValue, i);
	}
}

Octal Octal::operator+(const Octal& _c)
{	
	int max, min;
	if (_c.length > length)
	{
		max = _c.length;
		min = length;
	}
	else
	{
		max = length;
		min = _c.length;
		
	}
	Octal tmp(max); //Выбирам наибольшую длину
	tmp.ToZero();
	int t = 0; //Переход в следующий разряд
	for (int i = 0; i < min; i++) //Складываем "общую часть"
	{
		tmp.number[i] = (number[i] + _c.number[i] + t) % 8;
		t = (number[i] + _c.number[i] + t) / 8;
	}
	if (_c.length != length) {
		for (int i = min; i < max; i++) //Сносим остальную часть
		{
			if (length > _c.length)
			{
				tmp.number[i] = (number[i] + t) % 8;
				t = (number[i] + t) / 8;
			}
			else
			{
				tmp.number[i] = (_c.number[i] + t) % 8;
				t = (_c.number[i] + t) / 8;
			}
		}
	}
	return tmp;
}

Octal Octal::operator-(const Octal& _c)
{
	int max, min;
	if (_c.length > length)
	{
		max = _c.length;
		min = length;
	}
	else
	{
		max = length;
		min = _c.length;
	}
	Octal tmp(max); //Выбирам наибольшую длину
	tmp.ToZero();
	int t = 0;
	for (int i = 0; i < min; i++) //Вычитаем "общую часть"
	{
		if (number[i] + t < _c.number[i])
		{
			tmp.number[i] = number[i] - _c.number[i] + 8 + t;
			t = -1;
		}
		else
		{
			tmp.number[i] = number[i] - _c.number[i] + t;
			t = 0;
		}
	}
	if (_c.length != length) 
	{
		if (length > _c.length) //Сносим оставшиеся разряды
		{
			for (int i = min; i < max; i++) 
			{
				if (number[i] + t < 0) //Если продолжаем занимать (например, число 10000 - 1)
				{
					tmp.number[i] = number[i] + t + 8;
					t = -1;
				}
				else //Просто сносим
				{
					tmp.number[i] = number[i] + t;
					t = 0;
				}
			}
		}
		else
		{
			for (int i = min; i < max; i++) //Вычитаем из 0
			{
				if (_c.number[i] - t > 0) //Если продолжаем занимать (-t т.к. оно отрицательное)
				{
					tmp.number[i] = -_c.number[i] + t + 8;
					t = -1;
				}
				else //Простно сносим
				{
					tmp.number[i] = _c.number[i] + t;
					t = 0;
				}				
			}
		}		
	}
	return tmp;
}

Octal Octal::operator*(const Octal& _c) const
{	
	int max, min;
	if (_c.length > length)
	{
		max = _c.length;
		min = length;
	}
	else
	{
		max = length;
		min = _c.length;		
	}
	Octal tmp(max), rez(max); //Выбирам наибольшую длину
	tmp.ToZero(); 
	rez.ToZero();//Обнуляем временную переменую 
	int t = 0; //Переходит в другой разряд
	for (int j = 0; j < min; j++) //Движимся по разрядам меньшего числа
	{
		for (int i = 0; i < max; i++) //Движимся по разрядам большего числа
		{
			if (length > _c.length) //Умножаем большее число по отдельности на каждый разряд в зависимости какое число больше 
			{
				tmp.number[i] = (number[i] * _c.number[j] + t) % 8;
				t = (number[i] * _c.number[j] + t) / 8;
			}
			else
			{
				tmp.number[i] = (_c.number[i] * number[j] + t) % 8;
				t = (_c.number[i] * number[j] + t) / 8;
			}
		}
		tmp.Shift(j); //Сдвигаем результат (если необходимо)
		rez = rez + tmp; 
		t = 0;
		tmp.ToZero(); 
	}
	return rez;
}

Octal& Octal::operator=(const Octal& _c)
{
	if (this != &_c)
	{
		if (_c.length != length)
		{
			length = _c.length;
			delete[] number;
			number = new unsigned char[length];
		}
		for (int i = 0; i < length; i++) number[i] = _c.number[i];
	}
	return *this;
}

bool Octal::operator>(const Octal& _c)
{
	if (length > _c.length) return true;
	if (length < _c.length) return false;
	for (int i = length - 1; i >= 0; i--)
	{
		if (number[i] <= _c.number[i]) return false;
	}
	return true;
}

bool Octal::operator<(const Octal& _c)
{
	if (length < _c.length) return true;
	if (length > _c.length) return false;
	for (int i = length - 1; i >= 0; i--)
	{
		if (number[i] >= _c.number[i]) return false;
	}
	return true;
}

bool Octal::operator==(const Octal& _c)
{
	if (length != _c.length) return false;
	
	for (int i = 0; i < length; i++)
	{
		if (number[i] != _c.number[i]) return false;
	}
	return true;
}

Octal::~Octal()
{
	length = 0;
	delete[] number;
}

void Octal::Shift(int s)
{
	for (int i = length - 1; i >= s; i--) number[i] = number[i - s];
	for (int i = 0; i < s; i++) number[i] = 0;
}

void Octal::ToZero()
{
	for (int i = 0; i < length; i++) number[i] = 0;
}

std::ostream& operator<<(std::ostream& stream, const Octal& _c)
{
	for (int i = 0; i < _c.length; i++)
	{
		stream << (int)(_c.number[_c.length - i - 1]);
	}	
	return stream;
}

std::istream& operator>>(std::istream& stream, Octal& _c)
{
	try
	{
		std::string str;
		stream >> str;
		_c = str;
	}
	catch (Exception& e) //Если произошла ошибка чтения из потока, сообщение об этом выведится в консоль
	{
		setlocale(0, "");
		std::cout << "Неверный символ в " << e.ErrorPosition << " позиции";
	}
	return stream;
}


