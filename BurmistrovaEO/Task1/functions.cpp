#include <iostream>
#include <cmath>
#include "Ratio.h"
using namespace std;

int NOD(int v, unsigned int u)
{
	while (v != u)
	{
		if (v > u)
			v = v - u;
		if (u > v)
			u = u - v;
	}
	return u;
}
