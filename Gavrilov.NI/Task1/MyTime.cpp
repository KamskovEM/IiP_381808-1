#include "MyTime.h"
#include <string>

using namespace std;

MyTime::MyTime()
{
	myTime = 0;
}
MyTime::MyTime(int t)
{
	myTime = t;
	ToNormal();
}
MyTime::MyTime(string str)
{
	myTime = ((str[0] - '0') * 10 + (str[1] - '0')) * 3600
		+ ((str[3] - '0') * 10 + (str[4] - '0')) * 60
		+ ((str[6] - '0') * 10 + (str[7] - '0'));
	ToNormal();
}
MyTime::MyTime(const MyTime &mt)
{
	myTime = mt.myTime;
	ToNormal();
}

MyTime::~MyTime()
{
	myTime = 0;
}

MyTime & MyTime::operator=(const MyTime & c)
{
	myTime = c.myTime;
	ToNormal();
	return *this;
}
MyTime MyTime::operator + (const MyTime & c)
{
	MyTime res;
	res.myTime = myTime+c.myTime;
	res.ToNormal();
	return res;
}
MyTime MyTime::operator - (const MyTime & c)
{
	MyTime res;
	res.myTime = 3600*24+myTime-c.myTime;
	res.ToNormal();
	return res;
}
bool MyTime::operator==(const MyTime & c)//Peregruzka =
{
	return myTime==c.myTime;
}

ostream & operator << (ostream & stream, const MyTime & c)//Vivod v potok
{
	stream << c.myTime << 't';
	return stream;
}
istream& operator>>(istream & stream, MyTime & c)//Vvod v potok
{
	char x;
	stream >> c.myTime >> x;
	return stream;
}


string MyTime::GetStr()
{
	int s = myTime;

	int secs = s % 60;
	s /= 60;
	int mins = s % 60;
	s /= 60;
	int hours = s;

	string str = "";
	if (hours < 10)
		str += '0';
	str += to_string(hours) + ':';
	if (mins < 10)
		str += '0';
	str += to_string(mins) + ':';
	if (secs < 10)
		str += '0';
	str += to_string(secs);

	return str;
}

int MyTime::GetInt()
{
	return myTime;
}

void MyTime::ToNormal()
{
	if(myTime<0)
		myTime += 3600 * 24*-(myTime/(3600*24)-1);
	else
		myTime -= 3600 * 24 * (myTime / (3600 * 24));;
}

