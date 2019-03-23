#pragma once
#include <fstream>

using namespace std;
class MyOctal
{
private:
	int length;
	unsigned char* num;
public:
	static const int maxLength = 32;

	MyOctal();
	MyOctal(int length);
	MyOctal(const MyOctal &myOctal);
	~MyOctal();

	MyOctal & operator = (const MyOctal &c);
	MyOctal operator + (const MyOctal &c);
	MyOctal operator - (const MyOctal &c);
	bool operator == (const MyOctal &c);

	friend ostream & operator << (ostream & stream, const MyOctal &c);
	friend istream & operator >> (istream & stream, MyOctal &c);


	void turnOver();

	MyOctal GetMax();
};

