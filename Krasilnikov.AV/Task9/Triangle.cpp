#include "Triangle.h"
#include <amp_math.h>



Triangle::Triangle(void)
{
	a = 0; b = 0; c = 0;
}

Triangle::Triangle(double _a, double _b, double _c)
{
	a = _a;
	b = _b;
	c = _c;
}

bool Triangle::toBe()
{
	if ((a + b > c) || (a + c > b) || (c + b > a)) {
		return true;
	}
	else {
		return false;
	}
}

double Triangle::perimeter()
{
	if (toBe) {
		return a + b + c;
	}
	return 0;
}

double Triangle::mer()
{
	double p = perimeter() / 2;
	if (toBe) {
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	else {
		return 0;
	}
}
