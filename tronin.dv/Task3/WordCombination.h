#pragma once
#include <string>

class WordCombination
{
private:
	std::string EngWord;
	std::string RusWord;

public:
	WordCombination(); //Конструктор по умолчанию
	WordCombination(std::string, std::string); //Констурктор инициализатор
	WordCombination(const WordCombination&);
	~WordCombination();

	WordCombination& operator=(const WordCombination&);

	std::string& GetEngWord() { return EngWord; }; //Получение английского слова
	std::string& GetRusWord() { return RusWord; }; //Получение русского слова

	void SetPair(std::string&, std::string&); //Установление пары 
	
	friend std::istream& operator>>(std::istream& stream, WordCombination& _c);
	friend std::ostream& operator<<(std::ostream& stream, const WordCombination& _c);
};

std::istream& operator>>(std::istream& stream, WordCombination& _c);
std::ostream& operator<<(std::ostream& stream, const WordCombination& _c);

