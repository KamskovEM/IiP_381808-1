#pragma once
#include <string>
#include <iostream>
/*
 * bol`shoe (32+32 bit) bezznakovoe chislo
 * vvod/vivod v 16-oi ili 2-oi sisteme
 */
enum PrintType
{
	Binar,
	Hex
};
class BigNumber
{
private:
	int m_upper_part;  // starshaya chast`
	int m_lower_part;  // mladshaya chast`
	PrintType pt;      // Binar ili Hex

public:

	// neymeracia ot 0 do 63
	bool GetBit(int position) const;
	
	void SetBit(int position, bool b);
	// ystanavlivaet tip vivoda
	void SetPrintType(PrintType _pt) { pt = _pt; }
private:
	// polysymmator
	void HalfAdder(
		bool inA,       // vhod A
		bool inB,       // vhod B
		bool& outSum,   // vihod symmi
		bool& outC      // vihod perenosa razryada
	);   
	// polnii symmator
	void Adder(
		bool inC,      // vhod perenosa razryada
		bool inA,
		bool inB,
		bool& outSum,
		bool& outC
	);
	// obratnoe chislo (-num)
	BigNumber Invert() const;
	// peregryzhenie operacii
public:
	
	friend bool operator==(const BigNumber numL, const BigNumber numR);
	friend bool operator!=(const BigNumber numL, const BigNumber numR);
	BigNumber operator+(const BigNumber& num);
	BigNumber operator-(const BigNumber& num);
	bool operator<(const BigNumber num);
	bool operator>(const BigNumber num);
	bool operator<=(const BigNumber num) { return !(*this > num); }
	bool operator>=(const BigNumber num) { return !(*this < num); }

	// realizaciya ymnojeniya pytem slojeniya
	BigNumber operator*(const BigNumber& num);
	// realizaciya deleniya vichitaniem
	BigNumber operator/(const BigNumber& num);
	BigNumber& operator=(const BigNumber& num);
	friend std::ostream& operator<< (std::ostream& out, const BigNumber& num);

public:
	// Konstryktori
	BigNumber();
	// konstryiryet iz strokovogo preadstavleniya chisla v 16-oi sisteme
	// nevmeshaushyusya sleva chast` otbrasivaet
	BigNumber(std::string HexNum); 
	~BigNumber();
};

std::ostream& operator<< (std::ostream& out, const BigNumber& num);
bool operator==(const BigNumber numL, const BigNumber numR);
bool operator!=(const BigNumber numL, const BigNumber numR);
