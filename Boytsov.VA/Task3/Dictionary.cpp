#include "Dictionary.h"
#include <math.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Dictionary::Dictionary()
{
	RusWords = new string[100];
	EngWords = new string[100];
	length = 0;
}

Dictionary::Dictionary(Dictionary &v)
{
	RusWords = new string[100];
	EngWords = new string[100];
	length = v.length;
	RusWords->swap(*(v.RusWords));
	EngWords->swap(*(v.EngWords));
}

Dictionary::Dictionary(istream& filename)
{
	RusWords = new string[100];
	EngWords = new string[100];
	length = 0;
	string en;
	string ru;
	while (!filename.eof())
	{
			getline(filename, en, ' ');
			if (en == "\0")
				break;
			EngWords[length]=en;
			getline(filename, ru, '\n');
			if (ru == "\0")
				break;
			RusWords[length] = ru;
			length++;
	}
}

Dictionary::~Dictionary()
{
	delete[] EngWords;
	delete[] RusWords;
}

Dictionary & Dictionary::operator=(const Dictionary & v)
{
	(*this).length = v.length;
	(*this).EngWords = v.EngWords;
	(*this).RusWords = v.RusWords;
	(*this).FilePreparation("output.txt");
	return *this;
}

Dictionary& Dictionary::operator+=(const Dictionary & v)
{
	for (int i = 0; i < v.length; i++)
	{
		(*this).AddWords(v.EngWords[i], v.RusWords[i]);
	}
	(*this).FilePreparation("Words1.txt");
	return (*this);
}


void Dictionary::AddWords(string s1, string s2)
{
	EngWords[length] = s1;
	RusWords[length] = s2;
	length++;
}

void Dictionary::EditTranslation(string s1, string s2)
{
	for (int i = 0; i < length; i++)
	{
		if (EngWords[i].compare(s1) == 0)
		{
			RusWords[i] = s2;
			cout << "Перевод изменен" << endl << endl;
			return;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (RusWords[i].compare(s1) == 0)
		{
			EngWords[i] = s2;
			cout << "Перевод изменен" << endl << endl;
			return;
		}
	}
	cout << "Данного слова нет в словаре" << endl << endl;
}

void Dictionary::LearnTranslation(string s1)
{
	for (int i = 0; i < length; i++)
	{
		if (EngWords[i].compare(s1) == 0)
		{
			cout <<" Перевод данного слова : "<< RusWords[i] << endl << endl;
			return;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (RusWords[i].compare(s1) == 0)
		{
			cout << "Перевод данного слова : " << EngWords[i] << endl << endl;
			return;
		}
	}
	cout << "Данного слова нет в словаре" << endl << endl;
}

void Dictionary::CheckWord(string s1)
{
	bool flag = 0;
	for (int i = 0; i < length; i++)
	{
		if (EngWords[i].compare(s1) == 0)
		{
			flag = true;
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (RusWords[i].compare(s1) == 0)
		{
			flag = true;
		}
	}
	if (flag == true)
		cout << "Слово есть в словаре" << endl << endl;
	else
		cout << "Слова нет в словаре" << endl << endl;
}

void Dictionary::NumberWords()
{

	cout << "Количество слов в словаре = " << length << endl << endl;
}

void Dictionary::FilePreparation(const char* name)
{
	ofstream os;
	os.open(name); // файл для записи
	SaveDictionary(os);
	os.close();
}

void Dictionary::SaveDictionary(ostream & filename)
{
	for (int i = 0; i < length; i++)
	{
		filename << EngWords[i] << ' ' << RusWords[i] << endl;
	}
}

ostream & operator<<(ostream & stream, const Dictionary & v)
{
	for (int i = 0; i < v.length; i++)
	{
		stream << v.EngWords[i] << ' ' << v.RusWords[i] << endl;
	}
	return stream;
}
