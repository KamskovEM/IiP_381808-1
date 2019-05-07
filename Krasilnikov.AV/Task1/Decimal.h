#pragma once
#include <vector>

using namespace std;

class Decimal
{
private:
	vector<unsigned char> num;
public:
	Decimal();
	~Decimal();
	Decimal& operator= (const Decimal& d);
	Decimal& operator= (const unsigned long long n);
	Decimal operator+ (const Decimal& d);
	Decimal operator+ (const unsigned long long n);
	Decimal operator- (const Decimal& d);
	bool operator> (const Decimal& d);
	bool operator< (const Decimal& d);
	bool operator== (const Decimal& d);
	bool operator>= (const Decimal& d);
	bool operator<= (const Decimal& d);
	bool operator!= (const Decimal& d);
	friend istream& operator>>(istream& stream, Decimal& d);
	friend ostream& operator<<(ostream& stream, Decimal& d);
};

