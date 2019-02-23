#pragma once
char max(double a, double b, double c);
class triangle {
public:
	triangle();
	triangle(double a, double b, double c);
	triangle(const triangle& A);
	double a, b, c;
	bool ifexist(double a, double b, double c);
	int type(double a, double b, double c);
	double p(double a, double b, double c);
	double s(double a, double b, double c);
	~triangle();
};