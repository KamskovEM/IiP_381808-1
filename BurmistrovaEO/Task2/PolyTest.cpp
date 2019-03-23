#include <iostream>
#include <fstream>
#include "Poly.h"
using namespace std;


int main()
{
	string path = "Polyon.txt";
	unsigned int n;
	do
	{
		cin >> n;
		//cout << "¬ведено некорректное значение." << endl;
	} while ((n < 0) || (n > 12));
	Poly f1(n);
	Poly f2;
	cin >> f1;
	cout << f1 << "  f1" << endl;
	cout << f2 << "  f2" << endl;
	cout << f1.koeff(f1, 3) << "  koef" << endl;
	cout << f1.polyval(f1, 1) << "poly value in x " << endl;
	f2 = f1.deriv(f1);
	cout << f2 << "  deriv" << endl;
	cout << f1.polysize(f1) << "   polynomial size of f1"<< endl;

	fstream fil;
	fil.open(path, fstream::in | fstream::out | fstream::app);
	if (!fil.is_open())
	{
		cout << "File opening Error" << endl;
	}
	else
	{
		cout << "File is open" << endl;

		fil << f1;

	}

	fil.close();

	//getchar();
	//getchar();
}