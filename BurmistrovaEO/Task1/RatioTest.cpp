#include <iostream>
#include <cmath>
#include "Ratio.h"
#include "functions.h"
using namespace std;

int main()
{
	Ratio d; // basic constructor  test
	Ratio a(4, 5), b(2 , -3), e(3, 5);// constructor w_given_parameters test
	cout << a; // output
	cout << b; //output
	Ratio c = a - b; // test for the operators "-" and "="
	cout << c; // output
	c = a / b; // test for the operators "/" and "="
	cout << c; // output
	c = c + b; // test for the operators "+" and "="
	cout << c; // output
	c = a * b; // test for the operators "*" and "="
	cout << c; // output
	// comparison operators
	if (a < b)
		cout << "a < b" << "\n";
	else
		cout << "a > b" << "\n";



	if (d == e)
		cout << "equal \n";
	else
		cout << "unequal \n";

	if (a <= d)
		cout << "a <= d \n";
	else
		cout << "a > d \n";




	getchar();
	getchar();
}