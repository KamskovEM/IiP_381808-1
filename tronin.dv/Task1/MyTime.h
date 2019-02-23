#pragma once

#include <iostream>

class MyTime
{
public:

	//Konstruktor po umolchaniyu
	MyTime(void);

	//Konstruktor inicializacii
	MyTime(unsigned char, unsigned char, unsigned char);

	//Konstruktor kopirovaniya
	MyTime(const MyTime&);

	//Konstruktor  preobrazovaniya stroki vida "12.24.35"
	MyTime(const char*);

	~MyTime();

	//Zapros strochnogo predstavleniya
	char* ToString();

	//Metod dostupa--------------------------
	unsigned char GetH() { return h; };
	unsigned char GetM() { return m; };
	unsigned char GetS() { return s; };

	//Peregruzka operacii---------------------
	MyTime operator+(const MyTime&);
	MyTime operator-(const MyTime&);
	MyTime& operator=(const MyTime&);
	bool MyTime::operator==(const MyTime&);
	bool MyTime::operator!=(const MyTime&);
	bool operator>(const MyTime&);
	bool operator<(const MyTime&);

	friend std::ostream& operator<<(std::ostream&,  MyTime&);
	friend std::istream& operator>>(std::istream&,  MyTime&);


private:

	unsigned char h, m, s;
	char str[9];
	unsigned char Parse(const char*);		//Perevod iz strokovogo predstavleniya
};

std::istream& operator>>(std::istream&,  MyTime&);
std::ostream& operator<<(std::ostream&,  MyTime&);


