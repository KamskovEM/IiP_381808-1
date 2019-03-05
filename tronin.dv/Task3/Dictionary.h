#pragma once
#include <iostream>
#include <fstream>
#include "WordCombination.h"

class Dictionary
{
private:
	int length;
	int buf; //Буфер для добавления новых элементов
	WordCombination *base;
	


public:
	Dictionary(); //Констурктор по умолчанию
	Dictionary(std::string ); //Конструктор инициализации (открытие базы из файла)
	Dictionary(const Dictionary&); //Констурктор копирования

	std::string& FindTranslation(std::string);
	void ChangeTranslatoin(std::string, std::string);
	void Add(std::string, std::string);


	~Dictionary();
};

enum ExceptoinType

struct Exception
{
	int ExceptionType;

};

