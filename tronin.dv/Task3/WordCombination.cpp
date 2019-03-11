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


WordCombination::~WordCombination() {}

void WordCombination::SetPair(std::string& eng, std::string& rus)
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
