#include <iostream>
#include <cmath>
#include "Ratio.h"
using namespace std;

int NOD(int v, unsigned int u)
{
	while (abs(v) != u)
	{
		if (abs(v) > u)
			v = abs(v) - u;
		if (u > abs(v))
			u = u - abs(v);
	}
	return u;
}