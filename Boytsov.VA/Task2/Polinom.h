#pragma once
#include <iostream>
#include <fstream>
using namespace std;

enum MyPolinomExeption { OUTOFRANGE };
class Polinom
{
public:
	Polinom(); //Konstructor po umolchaniyu
	Polinom(int _power); //Kostructor initsializatsii
	Polinom(const Polinom &v);  //Konstructor kopirovaniya
	~Polinom();  //Destructor
	int GetPower();// Function polucheniya stepeni polinoma	
	double GetCoefficient(int i);// Function polucheniya coefficienta pri stepeni i
	Polinom derivative(); //Function vzyatiya proizvodnoy
	double CountPolinom(double x); //Function vichisleniya v tochke x
	double &operator[](int index); //Operaciya indeksatcii
	const double &operator[](int index) const;
	Polinom& operator=(const Polinom& v);//Operator prisvaivaniya
	Polinom operator+(const Polinom& v);//Operator slojeniya
	friend istream &operator >> (istream& stream, Polinom &v); //Vvod polinoma s klaviaturi
	friend istream &operator >> (ifstream& is, Polinom& v); //Chtenie polinoma iz file
	friend ostream &operator << (ostream& stream, const Polinom &v); //Vivod polinoma na konsol'
	friend ostream &operator << (ofstream& os, const Polinom &v); //Zapis' polinoma v file 
private:
	int power; //Stepen' polinoma
	double *coefficient; //massiv dlya hraneniya coeff. polinoma
};

