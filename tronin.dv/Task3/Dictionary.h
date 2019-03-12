#pragma once
#include <iostream>
#include <fstream>

#include "WordCombination.h"


class Dictionary
{
private:
	int length;	//Длина базы
	int rlength; //Настоящая длина массива
	int buf;	//Буфер для добавления новых элементов 
	WordCombination *base;	

	//переписать под реальную длину 
	
public:
	Dictionary(); //Констурктор по умолчанию
	Dictionary(int, int = 10); //Конструктор инициализации 
	Dictionary(std::string&, int = 10); //Конструктор инициализации (открытие базы из файла) + размер буфера
	Dictionary(const Dictionary&); //Констурктор копирования
	~Dictionary();

	int GetRLength() { return rlength; }; //Возрат количества слов в словаре 

	std::string FindTranslation(std::string&); //Возвращает перевод слова, если оно есть в словаре, и пустую строку, если оно отсутствует 
	void ChangeTranslation(std::string&, std::string&); //Меняет перевод слова
	void Add(std::string&, std::string&); //Добавление слова в словарь

	Dictionary& operator=(const Dictionary&);

	friend std::istream& operator>> (std::istream&, Dictionary&);
	friend std::ostream& operator<< (std::ostream&, const Dictionary&);
};

std::ostream& operator<< (std::ostream&, const Dictionary&);
std::istream& operator>> (std::istream&, Dictionary&);

enum ExceptionType {FileNotFound};



