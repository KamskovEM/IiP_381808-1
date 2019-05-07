#include <iostream>

#include "MyTime.h"

void main() 
{
	MyTime f, s, tmp;;
	std::cout << "Vvedite pervy element (hh.mm.ss): ";
	std::cin >> f; //Proverka vvoda
	std::cout << "Vvedite vtoroy element (hh.mm.ss): ";
	std::cin >> s;
	std::cout << "Pervy: " << f << std::endl; //Proverka vyvoda
	std::cout << "Vtoroy: " << s << std::endl;
	std::cout << ((f > s) ? "Pervy bolshe" : "Vtoroy bolshe") << std::endl; //Proverka sravneniya
	std::cout << "Sum " << f + s << " Raz: " << f - s << " " << s - f << std::endl; //Proverka summy i raznosti
	tmp = f; f = s; s = tmp; //Proverka prisvaivaniya togo zhe tipa
	std::cout << "Elementy posle obmena" << std::endl;
	std::cout << "Pervy: " << f << std::endl;
	std::cout << "Vtoroy: " << s << std::endl;
	f = "00.00.00"; //Proverka prisvaivaniya cheres stroky
	std::cout << "Element posle prisvoeniya stroki" << std::endl;
	std::cout << f << std::endl; 


	


	return;
}