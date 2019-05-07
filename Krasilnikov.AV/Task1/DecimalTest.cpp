#include <iostream>
#include <fstream>
#include <cstdbool>
#include "Decimal.h"


using namespace std;

int main() {
	Decimal a, b, c;
	cout << "Vvedite 2 chisla lyuboy dlinny: ";
	cin >> a >> b;
	c = a + b;
	cout << "sum: " << c << endl << endl;
	c = a - b;
	cout << "raznost: " << c << "    //Esli raznost' ravna 0, znachit pervoe chislo men'she vtorogo" << endl << endl;
	cout << "a > b = " << (a > b) << endl;
	cout << "a < b = " << (a < b) << endl;
	cout << "a >= b = " << (a >= b) << endl;
	cout << "a <= b = " << (a <= b) << endl;
	cout << "a == b = " << (a == b) << endl;
	cout << "a != b = " << (a > b) << endl;
	getchar();
	getchar();
	return 0;
}