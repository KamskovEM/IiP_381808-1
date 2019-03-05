#include <clocale>
#include <iostream>
#include <fstream>
#include "Money.h"
#include <math.h>

//konstructors
Money::Money() {								//Konstructor po umolchaniu
	X = 0;
	Y = 0;
}
Money::Money(const Money &c) {					//Konstructor kopirovaniya
	X = c.X;
	Y = c.Y;
}
Money::Money(int _X) {							//Konstructor ReType
	X = 1;
}
Money::Money(int _X, int _Y) : X(_X), Y(_Y) {}	//Konstructor inicilizacii
//Destructor
Money::~Money() {								//Destructor
	X = 0;
	Y = 0;
}
bool Money::operator==(const Money& c) {		//Sravnenie
	bool res;
	int k = (X * 100) + Y;
	int y = (c.X * 100) + c.Y;
	res = (k == y);
	return res;
}
bool Money::operator!=(const Money& c) {		//Ne Ravno
	bool res;
	res = !(*this == c);
	return res;
}
bool Money::operator>(const Money& c) {			//Bol'she
	bool res;
	int k = (X * 100) + Y;
	int y = (c.X * 100) + c.Y;
	if (k > y) {
		return res = 1;
	}
	else {
		return res = 0;
	}
}
bool Money::operator<(const Money& c) {			//Men'she
	bool res;
	int k = (X * 100) + Y;
	int y = (c.X * 100) + c.Y;
	if (k < y) {
		return res = 1;
	}
	else {
		return res = 0;
	}
}
Money& Money::operator=(const Money& c1) {		//Operaciya Ravno
	(*this).X = c1.X;
	Y = c1.Y;
	return *this;
}
Money Money ::operator+(const Money& c2) {		//Operaciya Summa
	Money result;
	int k = (X * 100) + Y;
	int l = (c2.X * 100) + c2.Y;
	result.X = (k + l) / 100;
	result.Y = (k + l) % 100;
	return result;
}
Money Money ::operator-(const Money& c3) {		//Operaciya Vichitaniya
	Money result;
	int k = (X * 100) + Y;
	int y = (c3.X * 100) + c3.Y;
	int l;
	l = k - y;
	result.X = l / 100;
	result.Y = abs(l % 100);
	if (X == c3.X) {
		if ((Y < c3.Y) && (result.X > 0))
			result.Y *= -1;
	}
	return result;
}
Money Money::operator*(int c) {					//Operaciya Umnojeniya
	Money result;
	int k = (X * 100) + Y;
	result.X = (k*c) / 100;
	result.Y = (k*c) % 100;
	return result;
}
Money Money::operator/(int c) {					//Operaciya Deleniya
	Money result;
	int k = (X * 100) + Y;
	result.X = (k / c) / 100;
	result.Y = (k / c) % 100;
	return result;
}
//Vivod
ostream& operator<<(ostream& stream, const Money& c) {
	stream << c.X << " " << c.Y << endl;
	return stream;
}
//Vvod
istream& operator>>(istream& stream, Money& c) {
	stream >> c.X >> c.Y;
	return stream;
}