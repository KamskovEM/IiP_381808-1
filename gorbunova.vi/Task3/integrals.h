#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class integrals
{
private:
	double a, b, rez;//granitsy i rezultat
	int n;//kol-vo razbienii
	double(*function)(double);//functia dlya sin,cos i exp

    
public:
	integrals::integrals();//konstruktor po umolchaniy
	integrals(double _a, double _b, int _n,double rez, double(*function)(double));//Konstruktor inicializator
	integrals(integrals &obj);//Konstruktor kopirovania
	~integrals();//destruktor
	
	double LeftRectangle();//metod levih priamougolnikov
	double RightRectangle();//metod pravih priamougolnikov
	double CentralRectangle();//metod srednih priamougolnikov

	

	friend std::istream& operator>>(std::istream &stream, integrals &obj);//peregruzka vivoda
	friend std::ostream& operator<<(std::ostream &stream, integrals &obj);//peregruzka vvoda
};


 

