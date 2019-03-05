#include "Dictionary.h"



Dictionary::Dictionary()
{
	length = 0;
	base = NULL;
}

Dictionary::Dictionary(std::string path)
{
	std::ifstream is(path.c_str);
	is >> 

}


Dictionary::~Dictionary()
{
}
