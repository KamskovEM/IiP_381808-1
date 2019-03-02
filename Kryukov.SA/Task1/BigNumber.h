#pragma once
using namespace std;
class Decimal {
	// class fields************************************************
private:
	int lgth;
	unsigned char* num;
	
	
public:
	int a;
	// Operation peregruzka---------------------------------------------------
		// input and output to stream
	friend ostream& operator<<(ostream& Ostream, const Decimal& Dcm);
	friend istream& operator>>(istream& Istream, Decimal& Dcm);
	//comparison operations
	
	bool operator==(const Decimal& Dcm);
	bool operator!=(const Decimal& Dcm);
	bool operator>(const Decimal& Dcm);
	bool operator>=(const Decimal& Dcm);
	bool operator<=(const Decimal& Dcm);
    bool operator<(const Decimal& Dcm);
	//prisvaivaniye
	Decimal& operator=(const Decimal& Dcm);
	//summa and difference
	Decimal operator+(const Decimal& Dcm);
	Decimal operator-(const Decimal& Dcm);

	// Constructors
	//INICIALIZATOR AND PRIVIDENIE TIPA
	Decimal(int razmer);
	// PO UMOLCHANIU
	Decimal(void);
	// Destructor
	~Decimal(void);
};