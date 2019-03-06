#include <clocale>
#include <iostream>
#include <fstream>

using namespace std;

class Polinom
{
public:
	//----------------------constructor 
	Polinom();//default constructor
	Polinom(int an);//type conversion constructor
	Polinom(const Polinom &); //copy constructor
	//Polinom(int _n);//constructor initializer
	//----------------------destructor
	~Polinom();//
	//----------------------
private:
	int n; //polynomial degree
	double *Coef; //pointer to the array of coefficients of the polynomial koef 
public:
	int Getn(); //polynomial function
	double GetCoef(int);//coefficient function at i-th degree
	Polinom derivative();//derivative
	Polinom operator=(const Polinom &);//overloaded = operator
	double answer(double x);//counting function for a given value
	friend istream &operator >> (istream &s, Polinom &c);//overloaded input operator
	friend ostream &operator<< (ostream &s, const Polinom &c); // overloaded output operator
};
ostream& operator<<(ostream & stream, const Polinom &a);
istream& operator >> (istream & stream, Polinom &a);

