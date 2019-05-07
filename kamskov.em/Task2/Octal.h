#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Octal
{
public:

	//konstruktori ---------------------------------
	Octal(void); // konstruktor po ymolchaniuy
	Octal(int);  // konstruktor inicializacii
	Octal(const Octal&); // konstruktor kopirovaniya
	Octal(string); // konstruktor pr. tipa iz stroki
	~Octal(); // destruktor
	//peregruzka operacij --------------------------
	Octal operator*(const Octal&); // operaciya ymnozheniya
	Octal operator+ (const Octal&); // operaciya slojeniya
	Octal operator- (const Octal&); // operaciya vichitaniya
	Octal& operator= (const Octal&);  // operaciya prisvaivaniya
	// operacii vvoda/vivoda v potok ---------------
	friend ostream& operator<<(ostream& stream, const Octal&);
	friend istream& operator>>(istream& stream, Octal&);
	//peregruzka operacij sravneniya ---------------
	bool operator==(const Octal&);
	bool operator!=(const Octal&);
	bool operator>(const Octal&);
	bool operator<(const Octal&);
private:
	unsigned char* digit; // cifra 
	int length; // dlina chisla

	int ToInt(); // perevod v Int
	Octal ToChar(int); // perevod v peremennuyu klassa
	Octal To10(); // perevod v 10 s.s.
	Octal To8(); // perevod v 8 s.s.
};