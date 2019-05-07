#pragma once
#include <string>
using namespace std;
class Time
{
public:
	//konstruktori ---------------------------------
	Time(void); // konstruktor po ymolchaniuy
	Time(int, int, int); // konstruktor inicializacii
	Time(const Time&); // konstruktor kopirovaniya
	Time(string); // konstruktor pr. tipa iz stroki
	~Time(); // destruktor
	//peregruzka operacij --------------------------
	Time operator+ (const Time&); // operaciya slojeniya
	Time operator- (const Time&); // operaciya vichitaniya
	Time& operator= (const Time&); // operaciya prisvaivaniya
	// operacii vvoda/vivoda v potok
	friend ostream& operator<< (ostream& stream, const Time&); 
	friend istream& operator>> (istream& stream, Time&);
	//peregruzka operacij sravneniya ---------------
	bool operator==(const Time&) const; 
	bool operator!=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator<(const Time&) const;
	string TimeStr(const Time&); // metod predstavleniya v vide stroki
	void Check(Time &); //metod proverki pokazatelei vremeni

private:
	int hou; // chasi
	int min; // minuti
	int sec; // sekyndi
};

