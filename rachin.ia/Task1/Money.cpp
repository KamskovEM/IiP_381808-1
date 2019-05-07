#include "Money.h"



void outputMenu() {
	cout << "Viberite deystvie:\n";
	cout << "1 - Sum and difference\n";
	cout << "2 - Multiplication and division\n";
	cout << "3 - Compare\n";
	cout << "4 - All operations\n";
	cout << "5 - <New task>\n";
	cout << "0 - <Exit>\n";

}
//Po umolchaniyu
Money::Money()
{
	R = 0; K = 0;
};

void Money::MoneyPere() 
{
	R = R + (K / 100); K = K % 100;
}

//Copy
Money::Money(const Money& i) 
{
	R = i.R; K = i.K;
};
//Initialization
Money::Money(int _R, int _K) : R(_R), K(_K) {} 
//Preobraz type
Money::Money(double M)
{
	R = (int)M;
	K = (int)(M * 100) % 100;
};
//Destructor
Money::~Money()
{
	R = 0; 
	K = 0;
};

Money& Money::operator=(const Money& i) 
{
	(*this).R = i.R; K = i.K;
	return *this;
};

Money Money::operator+(const Money& i) 
{
	Money sum;
	sum.R = R + i.R;
	sum.K = K + i.K;
	return sum;
};

Money Money::operator-(const Money& i)
{
	Money raz;
	if (*this < i)
	{
		int v= (i.R * 100 + i.K) - (R * 100 + K);
		raz.R = -(v / 100);
		raz.K = v % 100;
		return raz;
	}
	else
	{
		int v = (R * 100 + K) - (i.R * 100 + i.K);
		raz.R = v / 100;
		raz.K = v % 100;
		return raz;
	}
	
};



bool Money::operator<(const Money& i)
{
	if (R < i.R) { return 1; }
	else if (R == i.R && K < i.K) { return 1; }
	return 0;

};

bool Money::operator>(const Money& i)
{
	if (R > i.R) { return 1; }
	else if (R == i.R && K > i.K) { return 1; }
	return 0;
}; 

bool Money::operator!=(const Money& i)
{
	if (!(R == i.R) || !(K == i.K)) { return 1; }
	else { return 0; };
};

bool Money::operator==(const Money& i)
{
	if ((R == i.R) && (K == i.K)) { return 1; }
	else { return 0; };
};

ostream& operator<<(ostream& stream, const Money& i) {

	stream << i.R << " " << i.K << endl;

	return stream;

}

istream& operator>>(istream& stream, Money& i) 
{
	stream >> i.R >> i.K;

	return stream;
};	

Money operator*(const Money& i, double& d)
{
	Money Um;
	int N=(int)(i.K+i.R*100)*d;
	

	Um.K = N%100;
	Um.R = N/100;
	return Um;
};

Money operator/(const Money& i, double& d)
{
	Money Del;
	int v = i.R * 100 + i.K;
	Del.R = int(v / d) / 100;
	Del.K = int(int(v / d) % 100);
	return Del;
};

void Money::WriteR(int r) {
	(*this).R = r;
}

void Money::WriteK(int k) {
	(*this).K = k;
}