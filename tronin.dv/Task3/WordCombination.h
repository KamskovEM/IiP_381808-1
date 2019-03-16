#pragma once
#include <string>

class WordCombination
{
private:
	std::string EngWord;
	std::string RusWord;

public:
	WordCombination(); //Конструктор по умолчанию
	WordCombination(std::string, std::string); //Конструктор инициализатор
	WordCombination(const WordCombination&);
	~WordCombination();

	WordCombination& operator=(const WordCombination&);
	bool operator==(const WordCombination&) const;

	const std::string& GetEngWord() const { return EngWord; }; //Получение английского слова
	const std::string& GetRusWord() const { return RusWord; }; //Получение русского слова

	void SetPair(const std::string&, const std::string&); //Установление пары 
	
	friend std::istream& operator>>(std::istream& stream, WordCombination& _c);
	friend std::ostream& operator<<(std::ostream& stream, const WordCombination& _c);
};

std::istream& operator>>(std::istream& stream, WordCombination& _c);
std::ostream& operator<<(std::ostream& stream, const WordCombination& _c);

