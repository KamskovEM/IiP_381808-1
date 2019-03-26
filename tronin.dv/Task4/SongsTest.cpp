#include <string>
#include <iostream>

void main()
{
	std::string s("\n");
	if (s.empty())
		std::cout << "Empty"; else
		std::cout << "Not empty";
}