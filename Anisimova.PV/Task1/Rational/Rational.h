#pragma once
#include <iostream> 
#include <fstream>
#include<clocale>
using namespace std;

class Rational {
private:
	int n;      // chislitel'
	int m;    // znamenatel'

public:

	// Konstryktor--------------------------
	Rational();
	Rational(int, int);
	//Destryktor---------------------------
	~Rational();

	// Metody -----------------------------
	Rational operator = (const Rational&);     //prisvaivanie
	Rational operator + (const Rational&);     // + rational chisel
	Rational operator - (const Rational&);     // - rational chisel
	Rational operator * (const Rational&);	   // * rational chisel
	Rational operator / (const Rational&);	   // / rational chisel 

	// Sravnenye fractions
	bool operator == (const Rational&);

	//Function vvoda/vyvoda fraction
	friend ostream & operator << (ostream & stream, const Rational &c);
	friend istream & operator >> (istream & stream, Rational &c);
};
ostream& operator<<(ostream & stream, const Rational &c);//Peregruzka vivoda
istream & operator >> (istream & stream, Rational &c);//Peregruzka vvoda
