#include <iostream>
#include "BigNumber.h"
using namespace std;
int main()
{
	BigNumber num0;
	BigNumber num1("ABCD");
	BigNumber num2("EF12");
	BigNumber numBig("123456789ABCDEF");
	BigNumber numBig1("EDCBA9876543210");
	BigNumber numBig2("123456789ABCDE");
	cout << "testirovanie vivoda na ekran" << endl;
	cout << num0 << " " << num1 << " " << num2 << " " << numBig << endl;
	cout << endl << "testirovanie slojeniya" << endl;
	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	cout << numBig << " + " << num1 << " = " << numBig + num1 << endl;
	cout << numBig << " + " << numBig1 << " = " << numBig + numBig1 << endl;

	cout << endl << "testirovanie vichitaniya" << endl;
	cout << num2 << " - " << num1 << " = " << num2 - num1 << endl;
	cout << numBig << " - " << numBig2 << " = " << numBig - numBig2 << endl;

	cout << endl << "testirovanie ymnojeniya" << endl;
	BigNumber n1("123412341234"), n2("2");
	cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;

	cout << endl << "testirovanie deleniya" << endl;
	cout << "246824682468 / " << n1 << " = " << BigNumber("246824682468") / n1 << endl;

	cout << endl << num1 << " < " << num2 << " = " << (num1 < num2) << endl;

	cout << endl << num2 << " < " << num1 << " = " << (num2 < num1) << endl;

	cout << endl << num1 << " == " << num1 << " = " << (num1 == num1) << endl;

	cout << endl << num1 << " >= " << num1 << " = " << (num1 >= num1) << endl;

	char c;
	std::cin >> c;

}
