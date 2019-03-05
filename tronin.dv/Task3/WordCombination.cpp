#include "WordCombination.h"



WordCombination::WordCombination(std::string eng, std::string rus)
{
	EngWord = eng;
	RusWord = rus;
}


WordCombination::~WordCombination()
{
}

std::istream & operator>>(std::istream stream, WordCombination & _c)
{	
	stream >> _c.EngWord;
	stream >> _c.RusWord;
	return stream;	
}

std::ostream & operator<<(std::ostream stream, WordCombination & _c)
{
	stream << _c.EngWord << " " << _c.RusWord;
	return stream;
}
