#include "WordCombination.h"



WordCombination::WordCombination()
{
	EngWord = std::string(); //Присваиваем пустую строку 
	RusWord = std::string(); 
}

WordCombination::WordCombination(std::string eng, std::string rus)
{	
	EngWord = eng;
	RusWord = rus;
}

WordCombination::WordCombination(const WordCombination& _c)
{
	EngWord = _c.EngWord;
	RusWord = _c.RusWord;
}


WordCombination::~WordCombination() {}

WordCombination& WordCombination::operator=(const WordCombination& _c)
{
	if (this != &_c)
	{
		EngWord = _c.EngWord;
		RusWord = _c.RusWord;
	}
	return *this;
}

bool WordCombination::operator==(const WordCombination& _c) const
{
	if (EngWord == _c.EngWord && RusWord == _c.RusWord) return true;
	return false;
}

void WordCombination::SetPair(const std::string& eng, const std::string& rus)
{
	EngWord = eng;
	RusWord = rus;
}

std::istream & operator>>(std::istream& stream, WordCombination & _c)
{
	stream >> _c.EngWord;
	stream >> _c.RusWord;
	return stream;	
}

std::ostream & operator<<(std::ostream& stream, const WordCombination & _c)
{
	stream << _c.EngWord << " " << _c.RusWord << "\n";
	return stream;
}
