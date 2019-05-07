#pragma once
using namespace std;
class Time {
private:
	int day; // Den
	int month; // Mesyac
	int year; // God 
	int hour; // Chas zamera
	int temp; // Pokazaniya termometra
public:
	//konstruktori ---------------------------------
	Time(void); // konstruktor po ymolchaniuy
	Time(int, int, int, int, int); // konstruktor inicializacii
	~Time(); // destruktor
	//----------------------------------------------
	bool Datecheck(Time); // Proverka sovpadeniya daty
	bool Yearcheck(int); // Proverka sovpadeniya goda
	bool Monthcheck(int); // Proverka sovpadeniya mesyaca
	// operacii vvoda/vivoda v potok ---------------
	friend ostream & operator << (ostream & stream, const Time &);
	friend istream & operator >> (istream & stream, Time &);
	//----------------------------------------------
	friend class Thermometer;
};
class Thermometer {
private:
	int size; // kol-vo pokazaniy
	Time* time; // massiv pokazaniy
public:
	//konstruktori ---------------------------------
	Thermometer(void); // konstruktor po ymolchaniuy
	Thermometer(Time, int); // konstruktor inicializacii
	~Thermometer(); // destruktor
	//----------------------------------------------
	Time StartInfo(); // nachalnye data i vremya
	int Temp(Time); // Pokazaniya termometra v vybrannuyu datu i vremya 
	void TempZaSutki(Time); // Vse pokazaniya termometra dlya vybrannoi daty
	double SrTempZaSutki(Time); // Srednyaya temp. v vybrannuyu datu
	double SrTempZaMesyac(int, int); // Srednyaya temp. v vybrannuy mesyac
	double SrTempAll(); // Srednyaya temp. za vse nablyudeniya
	double SrTempDnem(int, int); // Srednyaya dnevnaya temp. v vybrannuy mesyac
	double SrTempNochy(int, int); // Srednyaya nochnaya temp. v vybrannuy mesyac
	void Add(Time); // Dobavit pokazaniya termometra
	// operacii vvoda/vivoda v potok ---------------
	friend ostream & operator << (ostream & stream, Thermometer const &);
	friend istream & operator >> (istream & stream, Thermometer &);
};