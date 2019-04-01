#include <clocale>
#include <iostream>
#include <fstream>

using namespace std;

typedef double Tfun(double);



class Tabulator
{
public:
	//----------------------constructor 
	Tabulator();//default constructor
	Tabulator(int _n, double _a, double _b);//constructor initializertype conversion constructor
	Tabulator(const Tabulator &); //copy constructor
	//Tabulator(int _n);//type conversion constructor
	//----------------------destructor
	~Tabulator();//
	//----------------------
private:
	int n; //number of tabs n
	double *resX; //array of values 
	double *resY; //array of values 
	double a, b;//tabulation interval
	Tfun* fun;

public:

	int Getn(); // get number of tabs n
	int Geta();
	int Getb();
	
	
	double tab();
	
	void Tabulirovanie(Tfun* fun, double tab);
	void Show();

	


	friend istream &operator >> (istream &s, Tabulator &c);//overloaded input operator
	friend ostream &operator<< (ostream &s, const Tabulator &c); // overloaded output operator
};

ostream& operator<<(ostream & stream, const Tabulator &a);
istream& operator >> (istream & stream, Tabulator &a);


