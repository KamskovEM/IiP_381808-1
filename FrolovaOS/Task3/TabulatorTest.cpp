#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Tabulator.h"



double ff1(double x)
{
	return sin(x);
}

double ff2(double x)
{
	return cos(x);
}
double ff3(double x)
{
	return exp(x);
}


using namespace std;

int main()
{

	Tabulator   T;
	Tfun* ff;

	int h;
		double h1,h2;
	cout << "Enter the number of tabs n" << '\n';
	cin >> h;

	cout << "Enter the border of interval, a  and b " << endl;
	cin >> h1 >> h2;

	Tabulator X(h, h1, h2);
	

	cout << "tabulation points : " << X.Getn() << endl;
	cout << "Border of interval [ " << X.Geta() << "," << X.Getb() << " ]" << '\n';
	cout << "Enter the function:" << '\n';
	cout << "1:sin(x)" << '\n';
	cout << "2:cos(x)" << '\n';
	cout << "3:exp(x)" << '\n';
	double g = X.tab();
	int fvar;
	cin >> fvar;

	switch (fvar)
	{
	case 1: {ff = ff1; X.Tabulirovanie(ff, g);  break; }
	case 2: {ff = ff2; X.Tabulirovanie(ff, g); break; }
	case 3: {ff = ff3; X.Tabulirovanie(ff, g); break; }
	}
	
	X.Show();
	
	ofstream os;
	os.open("Tabulator.txt");
	os << X << endl;
	os.close();


	ifstream is;
	is.open("Tabulator.txt");
	is >> T;
	T.Show();
	is.close();
	getchar();
	getchar();
	return 0;
}


