#include "Dictionary.h"


Dictionary::Dictionary()
{
	length = buf = bufl = 0;
	base = NULL;
}

Dictionary::Dictionary(int _length, int _buf)
{
	length = _length + _buf;
	bufl = 0;
	base = new WordCombination[length];
}

Dictionary::Dictionary(std::string& path, int buf)
{
	std::ifstream is(path, std::ifstream::in);
	if (!is.fail()) {
		is >> length;
		base = new WordCombination[length + buf];
		for (int i = 1; i <= length; i++)
		{
			is >> base[i - 1];
		}
		this->buf = buf;
		bufl = buf;
	}
	else
	{
		throw Exception(FileNotFound);
	}
		
}

Dictionary::Dictionary(const Dictionary& _c)
{
	if (this != &_c)
	{
		if (length != _c.length)
		{
			length = length;			
			delete[] base;
			base = new WordCombination[length];
		}
		buf = buf;
		bufl = bufl;
		for (int i = 0; i < length; i++)
		{
			base[i] = _c.base[i];
		}
	}
}

//Функция поиска перевода 
std::string Dictionary::FindTranslation(std::string& str)
{
	for (int i = 0; i < length; i++)
	{
		if (!base[i].GetEngWord().compare(str))
		{
			return base[i].GetRusWord(); //Возвращаем перевод
		}
	}
	//std::string rez = std::string();
	return std::string(); //Возвращаем пустую строку 
}

void Dictionary::ChangeTranslation(std::string& EngWord, std::string& RusWord)
{
	for (int i = 0; i < length; i++)
	{
		if (!base[i].GetEngWord().compare(EngWord)) //Возвращает 0, если слово совпало
		{
			base[i].SetPair(EngWord, RusWord); 
		}
	}

}

//Функция добавления нового перевода
void Dictionary::Add(std::string& EngWord, std::string& RusWord)
{
	if (bufl > 0)
	{
		base[length - bufl + 1].SetPair(EngWord, RusWord);
		length++;
		bufl--;
	} else
	{
		Dictionary tmp(length + buf);
		for (int i = 0; i < length; i++)
		{
			tmp.base[i] = this->base[i];
		}
		*this = tmp;		
	}
}

Dictionary & Dictionary::operator=(const Dictionary& _c)
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
		bufl = _c.bufl;
		for (int i = 0; i < length; i++)
		{
			base[i] = _c.base[i];
		}
	}
	return *this;
}


Dictionary::~Dictionary()
{
	length = 0;
	delete[] base;
	base = NULL;
}

std::ostream& operator<<(std::ostream& stream, const Dictionary& _c)
{
	stream << _c.length - _c.bufl << "\n";
	for (int i = 0; i < _c.length - _c.bufl; i++)
	{
		stream << _c.base[i];
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, Dictionary& _c)
{
	stream >> _c.length;
	_c.buf = 10;
	_c.length += _c.buf;
	_c.bufl = _c.buf;
	for (int i = 0; i < _c.length - _c.buf; i++)
	{
		stream >> _c.base[0];
	}
	return stream;
	
}
