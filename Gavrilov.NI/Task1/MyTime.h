#pragma once
#include<string>

using namespace std;

class MyTime
{
private:
	int myTime;
public:
	MyTime();
	MyTime(int t);
	MyTime(string str);
	MyTime(const MyTime &mt);
	~MyTime();

	MyTime & operator = (const MyTime &c);
	MyTime operator + (const MyTime &c);
	MyTime operator - (const MyTime &c);
	bool operator == (const MyTime &c);

	friend ostream & operator << (ostream & stream, const MyTime &c);
	friend istream & operator >> (istream & stream, MyTime &c);

	string GetStr();
	int GetInt();
	void ToNormal();
};

