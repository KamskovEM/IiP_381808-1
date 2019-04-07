#pragma once
#include <iostream>

class Money
{
public:
	Money();
	Money(int valueR, unsigned char value);
	Money(const Money& a);
	~Money();

	friend std::istream& operator>> (std::istream &in, Money &a);
	friend std::ostream& operator<< (std::ostream &out, const Money &a);


	Money& operator=(const Money& m);//prisvaivanie
	Money operator+(const Money& m);//slozhenie
	Money operator-(const Money& m);//vichitanie
	friend Money operator*(const Money& m, double d); //ymnozhenie
	friend Money operator/(const Money& m, double d); //delenie
	bool operator> (const Money& m);
	bool operator< (const Money& m);
	bool operator== (const Money& m); //sravnenie
	bool operator>= (const Money& m);
	bool operator<= (const Money& m);


private:

	int valueR;
	unsigned char valueK;
	

};

