#pragma once
class Triangle
{
public:
	Triangle(void);
	Triangle(double _a, double _b, double _c);
	bool toBe();
	double perimeter();
	double mer();
private:
	double a, b, c;
};

