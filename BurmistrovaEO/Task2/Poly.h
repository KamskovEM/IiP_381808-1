#pragma once
#include <iostream>
#include <fstream>
class Poly
{
	unsigned int st;
	double *znach;
public:
	Poly();
	Poly(unsigned int st);
	Poly& operator=(Poly op);
	unsigned int degree(Poly &op);
	unsigned int polysize(Poly &op);
	double koeff(Poly &op, int i);
	double polyval(Poly &op, double x);
	Poly deriv(Poly &op);
	friend std::ostream& operator<<(std::ostream& stream, const Poly obj);
	friend std::istream& operator>>(std::istream& stream, Poly obj);
	~Poly();
};
std::ostream& operator<<(std::ostream& stream, const Poly obj);
std::istream& operator>>(std::istream& stream, Poly obj);
