#include <iostream>
#include <cmath>
#include <sstream>
#include "Taylor.h"
#include <cstdlib>

using namespace std;


string IntToStr(int param)
{
	string str = "";
	for (str = ""; param; param /= 10)
		str += (char)('0' + param % 10);
	reverse(str.begin(), str.end());
	return str;
}

string DoubToStr(double Val)
{
	string result;
	std::ostringstream ost;
	ost << Val;
	result = ost.str();
	return result;
}

double F(double a, int n)
{
	switch (n % 4)
	{
	case 0:
		return sin(a);
		break;

	case 1:
		return cos(a);
		break;

	case 2:
		return -sin(a);
		break;

	case 3:
		return -cos(a);
		break;
	}
}

string SF(int n)
{
	switch (n % 4)
	{
	case 0:
		return "sin(a)";
		break;

	case 1:
		return "cos(a)";
		break;

	case 2:
		return "-sin(a)";
		break;

	case 3:
		return "-cos(a)";
		break;
	}
}

Taylor::Taylor(double a, int l) 
{
	n = l;
	kp = new string[n];
	for (int i = 0; i < n; i++)
		kp[i] = SF(i) + "/" + DoubToStr(i) + "!";
}

Taylor::~Taylor() 
{
	n = 0;
}

int Taylor::getlength() 
{
	return n;
}

double Taylor::calculate(double x)
{
	double res = 0;
	for (int i = 0; i < this->n; i++)
		res += F(this->a, i) / fact(i) * pow((x - this->a), i);
	return res;
}

string Taylor::operator[] (int i) 
{
	if (i > 0 && i < n + 1)
		return kp[i - 1];
	else
		return "Ne korrectnoe znachenie";
}

string* Taylor::getrow() 
{
	return kp;
}

ostream& operator<<(ostream& stream, const Taylor& T) 
{
	string row = "koeffecienti: " + T.kp[0];
	for (int i = 1; i < T.n; i++) 
	{
		row += " " + T.kp[i];
	}
	stream << row;
	return stream;
}

int Taylor::fact(int i) 
{
	if (i < 2) 
	{
		return 1;
	}
	else 
	{
		return i * fact(i - 1);
	}
}

double Taylor::otklon(double x) 
{
	return abs(this->calculate(x) - sin(x));
}
