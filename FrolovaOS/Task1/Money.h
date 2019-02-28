#include <clocale>

#include <iostream>

#include <fstream>

using namespace std;

class Money
{
public:
	//+++++++++++конструкторы
	Money();
	Money(const Money &t);
	Money(int _A);
	//+++++++++++деструктор
	~Money();
private:

	int A; // количество рублей 
	int B;// количество копеек
public:
	void setA(int r) { A = r; }
	void setB(int k) { B = k; }
	Money& operator=(const Money& c);
	Money  operator+(const Money& c);
	Money  operator-(const Money& c1);
	Money operator*(double t);
	Money  operator/(double t);
	bool operator==(const Money& c);
	bool operator!=(const Money& c);
	bool operator<(const Money& c);
	bool operator>(const Money& c);

	friend ostream& operator<<(ostream& stream, const Money& c);

	friend istream& operator>>(istream& stream, Money& c);

};
ostream& operator<<(ostream& stream, const Money& c);

istream& operator>>(istream& stream, Money& c);
