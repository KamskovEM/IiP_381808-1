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
	const char* GetString() const;

	//Metod dostupa--------------------------
	unsigned char GetH() const  { return h; };
	unsigned char GetM() const  { return m; };
	unsigned char GetS() const  { return s; };

	//Peregruzka operacii---------------------
	MyTime operator+(const MyTime&);
	MyTime operator-(const MyTime&);
	MyTime& operator=(const MyTime&);
	bool operator==(const MyTime&) const;
	bool operator!=(const MyTime&) const;
	bool operator>(const MyTime&) const;
	bool operator<(const MyTime&) const;

	friend std::ostream& operator<<(std::ostream&, const MyTime&);
	friend std::istream& operator>>(std::istream&,  MyTime&);


private:

	unsigned char h, m, s;
	char str[9];
	unsigned char Parse(const char*);		//Perevod iz strokovogo predstavleniya
	void ToString();
};

std::istream& operator>>(std::istream&,  MyTime&);
std::ostream& operator<<(std::ostream&, const  MyTime&);


