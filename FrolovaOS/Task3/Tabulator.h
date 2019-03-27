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
	Tabulator(int _n, int _a, int _b);//constructor initializertype conversion constructor
	Tabulator(const Tabulator &); //copy constructor
	//Tabulator(int _n);//type conversion constructor
	//----------------------destructor
	~Tabulator();//
	//----------------------
private:
	int n; //number of tabs n
	double *resX; //array of values 
	double *resY; //array of values 
	int a, b;//tabulation interval
	Tfun* fun;

public:

	int Getn(); // get number of tabs n
	int Geta();
	int Getb();
	void Setn(int _n);
	void Seta(int _a);
	void Setb(int _b);
	double ff(double x);
	Tabulator operator-(const Tabulator & c1);
	double tab(double n, int a, int b);
	//void copy(Tfun* _fun);
	Tabulator(Tfun* _fun);
	void Tabulirovanie(Tfun* fun, double tab);
	void Show();
	double&operator [](int ind);
	void OutputRes();
	double ans(Tfun* fun, double x);
	Tabulator& operator=(const Tabulator &);//overloaded = operator


	friend istream &operator >> (istream &s, Tabulator &c);//overloaded input operator
	friend ostream &operator<< (ostream &s, const Tabulator &c); // overloaded output operator
};
//double ff2(double x);
//double ff1(double x);
//double ff3(double x);
ostream& operator<<(ostream & stream, const Tabulator &a);
istream& operator >> (istream & stream, Tabulator &a);//default constructor


