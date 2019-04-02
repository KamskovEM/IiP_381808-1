#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <locale>
int main()
{
	setlocale(LC_CTYPE, "ru");
	Dictionary myDict;
	// тестирование перегрузки с 2-умя строковыми константами
	myDict.AddWord("girl", "двушка");
	PairWord mypair1;
	mypair1.first.ChangeWord("lesson");
	mypair1.second.ChangeWord("урок");
	// тестрирование перегрузки с парой слов
	myDict.AddWord(mypair1);
	Word eng1("sun"), ru1("солнце");
	// тестирование перегрузки с двумя Word
	myDict.AddWord(eng1, ru1);
	myDict.AddWord("green", "зеленый");
	myDict.AddWord("red", "красный");
	myDict.AddWord("blue", "иний");
	myDict.Print();
	std::cout << "-------------------------------" << std::endl;

	myDict.ChangeTranslation("green", "зелёный");
	myDict.ChangeTranslation("girl", "девушка");
	myDict.ChangeTranslation("blu", "синий");
	myDict.Print();

	std::cout << "В словаре " << myDict.GetSize() << " пар слов" << std::endl;

	std::cout << "Перевод слова RED  --- " << myDict.GetTranslation("red").ToCStr() << std::endl;
	std::cout << "Перевод слова GIRL --- " << myDict.GetTranslation("girl").ToCStr() << std::endl;

	std::cout << "-------------------------------" << std::endl;

	if (myDict.FindEngWord("green") != -1) std::cout << "Cлово green есть в словаре" << std::endl;
	if (myDict.FindEngWord("yellow") == -1) std::cout << "Cлова yellow нету в словаре" << std::endl;

	std::cout << "-------------------------------" << std::endl;
	// тестирование присваения словарей
	Dictionary digits;
	digits.AddWord("one", "один");
	digits.AddWord("two", "два");
	digits.AddWord("three", "три");
	digits.AddWord("four", "четыре");
	digits.AddWord("five", "пять");
	digits.AddWord("six", "шесть");
	digits.AddWord("seven", "семь");
	digits.AddWord("eight", "восемь");
	digits.AddWord("nine", "девять");

	Dictionary numbers;
	numbers = digits;      // цифры тоже являются числами
	numbers.AddWord("ten", "десять");
	numbers.AddWord("eleven", "одиннадцать");
	// ............
	numbers.Print();

	std::cout << "-------------------------------" << std::endl;
	// тестирование объединения словарей
	Dictionary Tricolor;
	Tricolor.AddWord("red", "красный");
	Tricolor.AddWord("green", "зеленый");
	Tricolor.AddWord("blue", "синий");
	//Tricolor.AddWord("white", "белый");  // проверка на общие слова

	Dictionary BlackAndWhite;
	BlackAndWhite.AddWord("black", "чёрный");
	BlackAndWhite.AddWord("white", "белый");

	Dictionary FiveColors = { Tricolor + BlackAndWhite };
	FiveColors.Print();

	std::cout << "-------------------------------" << std::endl;
	// проверка +=
	Dictionary ExtraColors;
	ExtraColors.AddWord("yellow", "желтый");
	ExtraColors.AddWord("orange", "оранжевый");

	(FiveColors += ExtraColors).Print();

	// проверка на считывание с файла
	Dictionary filetest;
	std::ifstream fin("myDict.txt");
	fin >> filetest;
	fin.close();
	std::cout << filetest << std::endl;

	char c;
	std::cin >> c;
}