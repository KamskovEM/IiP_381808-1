#pragma once
#include <iostream>

class Ratio
{
public:
	int n;
	unsigned int m;
	Ratio();
	Ratio(int v, unsigned int u);
	Ratio(const Ratio &object)
	{
		n = object.n;
		m = object.m;
	};
	Ratio operator=(Ratio op);
	Ratio operator+(Ratio op);
	Ratio operator-(Ratio op);
	Ratio operator*(Ratio op);
	Ratio operator/(Ratio op);
	bool operator<(Ratio op);
	bool operator>(Ratio op);
	bool operator==(Ratio op);
	bool operator!=(Ratio op);
	bool operator<=(Ratio op);
	bool operator>=(Ratio op);
	friend std::ostream& operator<<(std::ostream& stream, const Ratio obj);
	friend std::istream& operator>>(std::istream& stream, Ratio obj);

	~Ratio();
};

std::ostream& operator<<(std::ostream& stream, const Ratio obj);
std::istream& operator>>(std::istream& stream, Ratio obj);

