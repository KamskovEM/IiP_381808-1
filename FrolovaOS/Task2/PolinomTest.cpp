#include <iostream>
#include <fstream>
#include "Polinom.h"

using namespace std;

int main()
{
	int n;
	cout << "Enter the degree of the polynomial A " << '\n';
	cin >> n;
	Polinom A(n);
	cout << "Enter polynomial coefficients A: " << '\n';
	cin >> A;
	cout << "Polynomial A: " << A << '\n';
	cout << "Derivative  A: " << A.derivative() << '\n';
	cout << "Enter the index of the element, whose coefficient you want to know" << '\n';
	int ind;
	cin >> ind;
	cout << "Coefficient is " << A.GetCoef(ind - 1) << '\n';
	cout << "The degree of the polynomial is equal to " << A.Getn() << '\n';
	cout << "Enter the value x " << '\n';
	double x;
	cin >> x;
	cout << "The value of the polynomial at x = " << x << " is " << A.answer(x) << '\n';
	ofstream os("Test.txt");
	os << A;
	os.close();
	ifstream is("Test.txt");
	is >> A;
	cout << "Read from file:  " << A << endl;
	system("pause");
	return 0;
}