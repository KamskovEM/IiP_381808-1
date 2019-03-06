

#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
using namespace std;



class Money
{
public:
	Money();  //Po umolchaniyu
	Money(const Money& i);  //In. Copy
	Money(int _R,int _K);	//In. Initialization
	Money(double);    //Preobrazovanie tipa
	~Money();	//Destructor
	void WriteR(int r);
	void WriteK(int k);
	void MoneyPere();
	//Peregruzka operacii
	Money& operator=(const Money& i);
	Money operator+(const Money& i);
	Money operator-(const Money& i);

	friend Money operator*(const Money& i, double& d);		//Peregr. umnozheniya
	friend Money operator/(const Money& i, double& d);		//pereg. deleniya
	

	bool operator<(const Money& i);
	bool operator>(const Money& i);
	bool operator!=(const Money& i);
	bool operator==(const Money& i);

	friend ostream& operator<<(ostream& stream, const Money& c);	//Peregruzka vivoda
	friend istream& operator>>(istream& stream, Money& c);		//Peregruzka vvoda

private:
	int R, K;		//Rubles, Kopecks
};

ostream& operator<<(ostream& stream, const Money& c);		//vivod
istream& operator>>(istream& stream, Money& c);	//Vvod

void outputMenu(); //Menu

Money operator*(const Money& i, double& d);		//Peregr. umnozheniya
Money operator/(const Money& i, double& d);		//pereg. deleniya
