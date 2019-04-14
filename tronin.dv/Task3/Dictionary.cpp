﻿#include "Dictionary.h"


Dictionary::Dictionary()
{
	length = buf = rlength = 0;
	base = nullptr;
}

Dictionary::Dictionary(int _length, int _buf)
{
	rlength = 0;
	buf = _buf;
	length = _length;	
	base = new WordCombination[length];
}

Dictionary::Dictionary(std::string& path, int buf)
{
	std::ifstream is(path, std::ifstream::in);
	if (!is.fail()) {
		is >> rlength;
		length = rlength + buf;
		base = new WordCombination[length];
		for (int i = 1; i <= rlength; i++)
		{
			is >> base[i - 1];
		}
		this->buf = buf;
	}
	else
	{
		throw FileNotFound;
	}		
}

Dictionary::Dictionary(const Dictionary& _c)
{
	length = _c.length;
	buf = _c.buf;
	rlength = _c.rlength;
	base = new WordCombination[length];
	for (int i = 0; i < rlength; i++) 
	{
		base[i] = _c.base[i];
	}
}

std::string Dictionary::FindTranslation(const std::string& str, int t) const
{	
	for (int i = 0; i < rlength; i++)
	{
		if (t == EnglishToRussian)
		{
			if (!base[i].GetEngWord().compare(str))
			{
				return base[i].GetRusWord(); //Возвращаем перевод
			}
		}
		else
		{
			if (!base[i].GetRusWord().compare(str))
			{
				return base[i].GetEngWord(); //Возвращаем перевод
			}
		}
	}
	return std::string(); //Возвращаем пустую строку 
}


void Dictionary::ChangeTranslation(const std::string& EngWord, const std::string& RusWord)
{
	for (int i = 0; i < rlength; i++)
	{
		if (!base[i].GetEngWord().compare(EngWord)) //Возвращает 0, если слово совпало
		{
			base[i].SetPair(EngWord, RusWord);
			return;
		}
	}
}

void Dictionary::Add(const std::string& EngWord, const std::string& RusWord)
{
	if (length - rlength > 0) //Если осталось место 
	{
		base[rlength].SetPair(EngWord, RusWord);
		rlength++;
	} else
	{
		Dictionary tmp(length + buf, buf);
		tmp.rlength = length;
		for (int i = 0; i < length; i++)
		{
			tmp.base[i] = this->base[i];
		}
		tmp.base[tmp.rlength].SetPair(EngWord, RusWord);
		tmp.rlength++;		
		*this = tmp;		
	}
}

Dictionary Dictionary::operator+(const Dictionary& _c) const
{
	Dictionary tmp(rlength);
	tmp = *this;
	for (int i = 0; i < _c.rlength; i++)
	{
		bool f = false; //Флаг нахождения копии
		for (int j = 0; j < tmp.rlength; j++)
		{
			if (_c.base[i] == tmp.base[j]) //Если нашли 
			{
				f = true;
				break;
			}			
		}
		if (!f) tmp.Add(_c.base[i].GetEngWord(), _c.base[i].GetRusWord()); 
	}
	return tmp;
}

Dictionary& Dictionary::operator=(const Dictionary& _c)
{
	if (this != &_c)
	{
		if (length != _c.length)
		{
			length = _c.length;
			delete[] base;
			base = new WordCombination[length];
		}
		buf = _c.buf;
		rlength = _c.rlength;
		for (int i = 0; i < length; i++) //Продолжаем дальше реальной длины, так как там может остаться "мусор" 
		{
			base[i] = _c.base[i];
		}
	}
	return *this;
}


Dictionary::~Dictionary()
{
	length = rlength = buf = 0;
	delete[] base;
	base = NULL;
}

std::ostream& operator<<(std::ostream& stream, const Dictionary& _c)
{
	stream << _c.rlength << std::endl;
	for (int i = 0; i < _c.rlength; i++)
	{
		stream << _c.base[i];
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, Dictionary& _c)
{
	stream >> _c.rlength;
	_c.buf = 10;
	_c.length += _c.rlength + _c.buf;
	for (int i = 0; i < _c.rlength; i++)
	{
		stream >> _c.base[0];
	}
	return stream;
	
}
