#pragma once
#include <string>

class WordCombination
{
private:
	std::string EngWord;
	std::string RusWord;

public:
	WordCombination();
	WordCombination(std::string, std::string);

	~WordCombination();

	std::string& GetEngWord() { return EngWord; };
	std::string& GetRusWord() { return RusWord; };
	void SetPair(std::string&, std::string&);
	
	friend std::istream& operator>>(std::istream& stream, WordCombination& _c);
	friend std::ostream& operator<<(std::ostream& stream, const WordCombination& _c);
};

std::istream& operator>>(std::istream& stream, WordCombination& _c);
std::ostream& operator<<(std::ostream& stream, const WordCombination& _c);

