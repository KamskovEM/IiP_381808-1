#include <iostream>
#include <fstream>
#include "Polinom.h"

using namespace std;

int main()
{
	int n;
	cout << "Enter the degree of the polynomial A " << '\n';
	cin >> n;
	Polinom A(n), B(n);
	cout << "Enter polynomial coefficients A: " << '\n';
	for (int i = 0; i < n + 1; i++)
	{
		cin >> A[i];
	}
	cout << "Polynomial A: ";
	A.OutputPolinom();
	cout << "Derivative  A: ";
	A.derivative().OutputPolinom();
	int ind1;
met:
	try {
		cout << "Enter the index of the element, whose coefficient you want to know" << '\n';

		cin >> ind1;
		A[ind1 - 1];
	}
	catch (Exception& except) {
		cout << "Element number " << except.ind
			<< " is not exist" << endl;
		goto met;
	}

	cout << "Coefficient is " << A[ind1 - 1] << '\n';
	cout << "The degree of the polynomial is equal to " << A.Getn() << '\n';
	cout << "Enter the value x " << '\n';
	double x;
	cin >> x;
	cout << "The value of the polynomial at x = " << x << " is " << A.answer(x) << '\n';

	ofstream os("Test.txt");
	os << A;
	os.close();
	ifstream is("Test.txt");
	is >> B;
	is.close();


	cout << "Read from file:  " << endl;
	B.OutputPolinom();
	system("pause");
	return 0;
}