#include <iostream>
#include <cmath>
#include "Taylor.h"
#include <sstream>
using namespace std;

int main() 
{
	int n;
	double a;
	cout << "Vvedite parametr a: ";
	cin >> a;
	cout << endl << "Vvedite chislo chlenov ryada: ";
	cin >> n;
	
	Taylor T(a, n);
	
	cout << endl << T.getlength() << endl;
	
	cout << T << endl;
	
	cout << T[1] << endl;

	double x;
	cout << "Vvedite tochku x: ";
	cin >> x;
	cout << T.calculate(x) << endl;
	
	cout << T.otklon(3) << endl;
	


	return 0;
}
