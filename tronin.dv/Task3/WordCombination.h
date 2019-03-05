#pragma once
#include <string>

class WordCombination
{
private:
	std::string EngWord;
	std::string RusWord;

public:
	WordCombination(std::string, std::string);
	~WordCombination();

	std::string& EngWord() { return EngWord; };
	std::string& RusWord() { return RusWord; };
	
	friend std::istream& operator>>(std::istream stream, WordCombination& _c);
	friend std::ostream& operator<<(std::ostream stream, WordCombination& _c);
};

std::istream& operator>>(std::istream stream, WordCombination& _c);
std::ostream& operator<<(std::ostream stream, WordCombination& _c);

