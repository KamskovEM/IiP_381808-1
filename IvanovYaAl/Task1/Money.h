#include <clocale>
#include <iostream>
#include <fstream>

using namespace std;

class Money
{
private:
	int X;								//Rubles
	int Y;								//Kopeiky
public:
	//Kostructors
	Money();							//Konstructor po umolchaniu
	Money(const Money &c);				//Konstructor kopirovaniya
	Money(int _X, int _Y);				//Konstructor inicilizacii
	Money(int _A);						//Konstructor ReType
	//Destructor
	~Money();
	void getX(int e) {					//Poluchenie Rubley
		X = e;
	}
	void getY(int o) {					//Poluchenie Kopeek
		Y = o;
	}
	bool operator==(const Money& c);	//Sravnenie
	bool operator!=(const Money& c);	//Ne Ravno
	bool operator<(const Money& c);		//Men'she
	bool operator>(const Money& c);		//Bol'she

	//Potokoviy Vivod
	friend ostream& operator<<(ostream& stream, const Money& c);
	//Potokoviy Vvod
	friend istream& operator>>(istream& stream, Money& c);

	Money& operator=(const Money& c1);	//Operaciya Ravno
	Money  operator+(const Money& c2);	//Operaciya Summa
	Money  operator-(const Money& c3);	//Operaciya Vichitaniya
	Money operator*(int c);				//Operaciya Umnojeniya
	Money  operator/(int c);			//Operaciya Deleniya
};
//Vivod
ostream& operator<<(ostream& stream, const Money& c);
//Vvod
istream& operator>>(istream& stream, Money& c);