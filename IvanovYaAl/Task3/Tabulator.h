#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

typedef double Tfunc(double);

class Tabulator {
private:
	Tfunc* func;
	int n;
	double a, b;
	double* pointX;
	double* pointY;
public:
	Tabulator();
	Tabulator(int _n, double _a, double _b);
	Tabulator(const Tabulator &c);
	~Tabulator();
	int Return_N(int n);
	double Return_A(double a);
	double Return_B(double b);
	void Tabulirovanie(Tfunc* _func);
	void TabShow();
	friend ostream& operator << (ostream & stream, const Tabulator &c);
	friend istream& operator >> (istream & stream, Tabulator &c);
};

ostream& operator << (ostream & stream, const Tabulator &c);
istream& operator >> (istream & stream, Tabulator &c);