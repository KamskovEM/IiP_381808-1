#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;


enum TPolynomialExeption { NotCorrectValue };
struct Exception
{
	TPolynomialExeption out_of_range;
	int ind;
	Exception(TPolynomialExeption _out_of_range, int _ind)
	{
		out_of_range = _out_of_range;
		ind = _ind;
	}
};

class Polynomial
{
public:
	int n;            //Stepen' polinoma
	int *coefficient; //ykazatel' na massiv koefficientif

	int&operator [](int index);    //index

	// Konstryktory--------------------------
	Polynomial();
	Polynomial(int);                //initsializator
	Polynomial(const Polynomial &); //Copy
	//Destryktor---------------------------
	~Polynomial();

	// Metody -----------------------------
	int Setn();                              //Zadat'/yznat' stepen' polinoma
	int SetCoeff(int);                       //Yznat' koefficient po znacheniy
	int Ans(int x);                          //polinom pri x
	Polynomial Deriv();                      //proizvodnaya
	Polynomial&operator=(const Polynomial&); //operator prisvaivaniya

	//Function vvoda/vyvoda
	friend ostream & operator << (ostream & stream, const Polynomial &a);
	friend istream & operator >> (istream & stream, Polynomial &a);
};
ostream& operator<<(ostream & stream, const Polynomial &a);//Peregryzka vyvoda
istream& operator >> (istream & stream, Polynomial &a);    //Peregryzka vvoda
