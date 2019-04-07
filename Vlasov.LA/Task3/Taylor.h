#pragma once
using namespace std;

string IntToStr(int i);
string DoubToStr(double Val);
double F(double a, int n);
string SF(int n);

class Taylor 
{
	int n;
	double a;
	string *kp;
public:

	Taylor(double a, int l);
	~Taylor();
	int getlength();
	double calculate(double x);
	string* getrow();
	double otklon(double x);
	string operator[](int i);
	friend ostream& operator<<(ostream& stream, const Taylor& T);
	int fact(int i);
};
