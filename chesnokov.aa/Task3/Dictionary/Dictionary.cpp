#include "Dictionary.h"

void Dictionary::AddWord(const char* eng, const char* ru)
{
	// если недостаточно места в буффере увеличить его
	if (ExtCheck()) ResizeBuffer(bufferSize + 10);
	dict[curSize].first.ChangeWord(eng);
	dict[curSize].second.ChangeWord(ru);
	curSize++;
}

void Dictionary::AddWord(const PairWord& pairword)
{
	// если недостаточно места в буффере увеличить его
	if (ExtCheck()) ResizeBuffer(bufferSize + 10);
	dict[curSize].first.ChangeWord(pairword.first);
	dict[curSize].second.ChangeWord(pairword.second);
	curSize++;
}

void Dictionary::AddWord(const Word& eng, const Word& ru)
{
	// если недостаточно места в буффере увеличить его на 10
	if (ExtCheck()) ResizeBuffer(10);
	dict[curSize].first.ChangeWord(eng);
	dict[curSize].second.ChangeWord(ru);
	curSize++;
}

Word Dictionary::GetTranslation(const Word & word)
{
	int ind = FindEngWord(word);
	Word res(dict[ind].second);
	return res;
}

void Dictionary::Print()
{
	for (int i = 0; i < curSize; i++)
	{
		std::cout << dict[i].first.ToCStr() << "<->" << dict[i].second.ToCStr() << std::endl;
	}
}

Dictionary & Dictionary::operator=(const Dictionary & d)
{
	curSize = d.curSize;
	bufferSize = curSize + 5;  // резервируем больше места
	dict = new PairWord[bufferSize]();
	for (int i = 0; i < curSize; i++)
	{
		// копируем слова
		dict[i].first.ChangeWord(d.dict[i].first);
		dict[i].second.ChangeWord(d.dict[i].second);
	}
	return *this;
}

Dictionary & Dictionary::operator+=(const Dictionary & right)
{
	for (int i = 0; i < right.curSize; i++)
	{
		if (FindEngWord(right.dict[i].first) == -1)
		{
			AddWord(right.dict[i]);
		}
	}
	return *this;
}


void Dictionary::Release()
{
	delete[] dict;
}

void Dictionary::ResizeBuffer(int incrementSize)
{
	bufferSize += incrementSize;
	// временный массив содержащий копию словаря
	PairWord* temp = new PairWord[bufferSize]();
	for (int i = 0; i < curSize; i++)
	{
		temp[i].first.ChangeWord(dict[i].first);
		temp[i].second.ChangeWord(dict[i].second);
	}
	// удаляем словарь, так как он скопирован во временный
	Release();
	// изменяем указатель на нововыделенную память
	dict = temp;
}

bool Dictionary::ExtCheck()
{
	return (curSize >= bufferSize);
}

int Dictionary::FindEngWord(const Word& word)
{
	for (int i = 0; i < curSize; i++)
	{
		if (dict[i].first == word) return i;
	}
	return -1;
}

void Dictionary::ChangeTranslation(const Word& word, const Word& transl)
{
	int index = FindEngWord(word);
	if (index == -1) AddWord(word, transl);
	else dict[index].second.ChangeWord(transl);
}

void Dictionary::ChangeTranslation(const Word & word, const char * transl)
{
	int index = FindEngWord(word);
	if (index == -1) AddWord(word, transl);
	else dict[index].second.ChangeWord(transl);
	
}

Dictionary::Dictionary()
{
	// не резервируется никакой памяти
	dict = nullptr;
	bufferSize = 0;
	curSize = 0;
}

Dictionary::Dictionary(const Dictionary & d)
{
	curSize = d.curSize;
	bufferSize = curSize + 5;  // резервируем больше места
	dict = new PairWord[bufferSize]();
	for (int i = 0; i < curSize; i++)
	{
		// копируем слова
		dict[i].first.ChangeWord(d.dict[i].first);
		dict[i].second.ChangeWord(d.dict[i].second);
	}
}

Dictionary::~Dictionary()
{
	Release();
	dict = nullptr;
	curSize = bufferSize = 0;
}

Dictionary operator+(const Dictionary & left, const Dictionary & right)
{
	Dictionary res;
	res.curSize = 0;
	res.bufferSize = left.curSize + right.curSize + 5;
	res.dict = new PairWord[left.bufferSize]();
	int j = 0;
	// копируем первый словарь
	for (int i = 0; i < left.curSize; i++, j++)
	{
		if (res.FindEngWord(left.dict[i].first) == -1)      // если такого слова еще нету в словаре
		{
			res.dict[j].first.ChangeWord(left.dict[i].first);
			res.dict[j].second.ChangeWord(left.dict[i].second);
			res.curSize++;
		}
	}
	for (int i = 0; i < right.curSize; i++, j++)
	{
		if (res.FindEngWord(right.dict[i].first) == -1)
		{
			res.dict[j].first.ChangeWord(right.dict[i].first);
			res.dict[j].second.ChangeWord(right.dict[i].second);
			res.curSize++;
		}
	}
	return res;
}

std::ostream & operator<<(std::ostream & out,const Dictionary& d)
{
	out << d.curSize << std::endl;  // записываем размер словаря
	for (int i = 0; i < d.curSize; i++)
	{
		// выводим слово - перевод через пробел в строчку
		out << d.dict[i].first.ToCStr() << " " << d.dict[i].second.ToCStr() << std::endl;
	}
	return out;
}

std::istream & operator>>(std::istream & in, Dictionary & d)
{
	d.Release();       // удаляем предыдущий словарь
	d.curSize = 0;
	int size;
	in >> size;
	d.bufferSize = size;
	d.ResizeBuffer(5);
	// считываем и добавляем слова в словарь
	for (int i = 0; i < size; i++)
	{
		char f[50], s[50];
		in >> f >> s;
		d.AddWord(f, s);
	}
	return in;
}

