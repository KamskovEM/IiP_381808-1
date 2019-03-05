#include <clocale>
#include <iostream>
#include <fstream>
using namespace std;

class Money
{
public:
    Money();
	Money(const Money &t);
	Money(int _A);
	
	~Money();
private:
	int A; //kol-vo rubley
	int B;// kol-vo kopeek
public:
	void setA(int r) { A = r; }
	void setB(int k) { B = k; }
	Money operator*(double t);
	Money  operator/(double t);
	Money& operator=(const Money& c);
	Money  operator+(const Money& c);
	Money  operator-(const Money& c1);
	bool operator<(const Money& c);
	bool operator>(const Money& c);
	bool operator==(const Money& c);
	bool operator!=(const Money& c);


	friend ostream& operator<<(ostream& stream, const Money& c);
	friend istream& operator>>(istream& stream, Money& c);
};
ostream& operator<<(ostream& stream, const Money& c);
istream& operator>>(istream& stream, Money& c);