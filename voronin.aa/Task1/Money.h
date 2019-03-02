#pragma once
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
class Money {
private:
	Money sum(Money& res, const Money& m);   // Sum of two objects
	Money min(Money& res, const Money& m);   // Min of two objects
	friend ostream&                                    //vivod
		operator<<(ostream& stream, const Money& m);
	friend istream&                                    //vvod
		operator>>(istream& stream, Money& m);
  
	char z;   //znak summi
	int c;   // kopeyki 
	int r;   // rubli
public:
	
	Money(); //konstuctor po umolchaniyu
	Money(char z, int r,int  c); //konstructor inicializacii
	Money(const Money& _a); //konstructor kopirovaniya
	~Money(); // destructor
	Money& operator=(const Money& m);//prisvaivanie
	Money operator+(const Money& m);//slozhenie
	Money operator-(const Money& m);//vichitanie
	friend Money operator*(const Money& m,double d); //ymnozhenie
	friend Money operator/(const Money& m, double d); //delenie
	bool operator == (const Money& m); //sravnenie

};