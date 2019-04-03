#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "windows.h"
#include <fstream>

using namespace std;

class Dictionary
{
public:
	Dictionary();//Конструктор по умолчанию
	Dictionary(Dictionary &v);//Конструктор копирования
	Dictionary(istream& filename);//Контруктор инициализации
	~Dictionary();//Деструктор
	Dictionary& operator=(const Dictionary& v);//Перегрузка операции присваивания
	Dictionary& operator+=(const Dictionary& v);//Перегрузка операции присваивания друх словарей
	void AddWords(string s1, string s2);//Фукция добавления слов в словарь
	void EditTranslation(string s1, string s2);//Функция изменения перевода указанного слова
	void LearnTranslation(string s1);//Функция получения перевода выбранного слова
	void CheckWord(string s1);//Функция проверки наличия слова в словаре
	void NumberWords();//Функция вывода количества слов в словаре
	void FilePreparation(const char* name);//Функция подготовки файла к записи
	void SaveDictionary(ostream& filename);//Функция записи в файл
	friend ostream& operator<<(ostream& stream, const Dictionary& v);//Перегрузка операции вывода на консоль
private:
	int length;//Длина словаря
	string *RusWords;//Русские слова словаря
	string *EngWords;//Английские слова словаря
};
ostream& operator<<(ostream& stream, const Dictionary& v);
