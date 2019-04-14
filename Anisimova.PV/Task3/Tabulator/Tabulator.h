#pragma once
#include <iostream>
#include <fstream>
#include "pch.h"
#include <clocale>
using namespace std;

typedef double Tfun(double);

class Tabulator
{
	Tfun* f;
	double a;
	double b;
	double n;
	double *x;
	double *y;

public:
	// Konstryktory--------------------------
	Tabulator();                            // default
	Tabulator(double, double, int);         // initsializator
	Tabulator(const Tabulator &);           // ñopy
	//Destryktor---------------------------
	~Tabulator();

	//Vozvrat
	double SetA();
	double SetB();
	int SetN();

	//Tabulator
	void ABN(double, double,int);
	void Tabulyatsiya(Tfun _fun);
	void Screen();
	
    friend ostream & operator << (ostream & stream, const Tabulator &a);
	friend istream & operator >> (istream & stream, Tabulator &a);
};
//function
double f_sin(double);
double f_cos(double);
double f_exp(double);

ostream& operator << (ostream & stream, const Tabulator &a); //Peregryzka vyvoda
istream& operator >> (istream & stream, Tabulator &a);       //Peregryzka vvoda