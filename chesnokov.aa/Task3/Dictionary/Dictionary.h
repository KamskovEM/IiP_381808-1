#pragma once
#include <iostream>
#include "Words.h"
// класс англо-русского словаря, интерфейс:
// добавить слово и его перевод
// изменить перевод указанного слова
// узнать перевод указанного слова
// проверить наличие слова
// узнать число слов 
// сохранить в файл / считать с файла
// присвоение одного словаря другому, объединение словарей
class Dictionary
{
private: //-----------внутренне представление--------------
	PairWord * dict;    // динамический массив пары слов (первое слово - анг)
	int curSize,        // текущий размер словаря
		bufferSize;     // зарезервированный размер словаря

public:  //--------------открытый интерфейс-----------------
	// различные перегрузки добавления нового слова 
	void AddWord(const char* eng, const char* ru);
	void AddWord(const PairWord& word);
	void AddWord(const Word& eng, const Word& ru);

	// изменяет перевод указанного слова, если слово небыло найдено, то добавит его в словарь
	void ChangeTranslation(const Word& word, const Word& transl);
	void ChangeTranslation(const Word& word, const char* transl);

	// узнать перевод указанного слова
	Word GetTranslation(const Word& word);

	// узнать количество слов в словаре
	int GetSize() { return curSize; }

	// ищет указанное английское слово, возвращая его индекс
	// если слово отсутствует то возвращает -1
	int FindEngWord(const Word& word);

	void Print();
public:  // -------------перегрузка операторов--------------
	Dictionary & operator=(const Dictionary& d);
	friend Dictionary operator+(const Dictionary& left, const Dictionary& right);
	Dictionary& operator+=(const Dictionary& right);
	friend std::ostream& operator<<(std::ostream& out, const Dictionary& d);
	friend std::istream& operator>>(std::istream& in, Dictionary& d);

private: //--------------закрытые методы--------------------
	// освобождение занимаемой памяти
	void Release();
	// изменение буфера под текущий необходимый размер
	void ResizeBuffer(int incrementSize);
	// проверка необходимо ли расширять буфер? если да
	bool ExtCheck();
	
	
public:
	// конструткор по умолчанию (создает пустой словарь)
	Dictionary();
	Dictionary(const Dictionary& dict);  // конструктор копирования
	~Dictionary();
};

Dictionary operator+(const Dictionary& left, const Dictionary& right);
std::ostream& operator<<(std::ostream& out,const Dictionary& d);
std::istream& operator>>(std::istream& in, Dictionary& d);
