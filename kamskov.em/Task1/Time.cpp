#include "Time.h"
#include <iostream>

Time::Time(void) // konstruktor po ymolchaniuy
{
	hou = min = sec = 0;
}
Time::Time(int _hou, int _min, int _sec) // konstruktor inicializacii
{
	hou = _hou;
	min = _min;
	sec = _sec;
}
Time::Time(const Time& T) // konstruktor kopirovaniya
{
	hou = T.hou;
	min = T.min;
	sec = T.sec;
}
Time::Time(string TimeStr) // konstruktor pr. tipa iz stroki
{
	hou = ((int)TimeStr[0] - (int)'0')*10 + (int)TimeStr[1] - (int)'0';
	min = ((int)TimeStr[3] - (int)'0') * 10 + (int)TimeStr[4] - (int)'0';
	sec = ((int)TimeStr[6] - (int)'0') * 10 + (int)TimeStr[7] - (int)'0';
}
Time::~Time()
{
	hou = min = sec = 0;
}
Time Time::operator+(const Time & T) // operaciya slojeniya
{
	Time tmp;
	tmp.sec = sec + T.sec;
	tmp.min = min + T.min;
	tmp.hou = hou + T.hou;
	tmp.Check(tmp);
	return tmp;
}
Time Time::operator-(const Time& T) // operaciya vichitaniya
{
	Time tmp;
	tmp.hou = hou - T.hou;
	tmp.min = min - T.min;
	tmp.sec = sec - T.sec;

	while (tmp.sec < 0) {
		tmp.sec = 60 + tmp.sec;
		tmp.min--;
	}
	while (tmp.min >= 60) {
		tmp.min = 60 + tmp.min;
		tmp.hou--;
	}
	if (tmp.hou >= 24) {
		tmp.hou = 24 - tmp.hou;
	}

	return tmp;
}
Time& Time::operator=(const Time& T) // operaciya prisvaivaniya
{
	hou = T.hou;
	min = T.min;
	sec = T.sec;
	return *this;
}
ostream& operator<<(ostream& stream, const Time& T) 
{
	stream << T.hou << ":" << T.min << ":" << T.sec;
	return stream;
}
istream& operator>>(istream& stream, Time& T)
{
	stream >> T.hou; 
	stream >> T.min;
	stream >> T.sec;
	return stream;
}
bool Time::operator==(const Time& T) const
{
	if (hou == T.hou && min == T.min && sec == T.sec)
	{
		return true;
	}
	return false;
}
bool Time::operator!=(const Time& T) const
{
	if (hou != T.hou || min != T.min || sec != T.sec)
	{
		return true;
	}
	return false;
}
bool Time::operator>(const Time& T) const
{
	if (hou * 3600 + min * 60 + sec > T.hou * 3600 + T.min * 60 + T.sec)
	{
		return true;
	}
	return false;
}
bool Time::operator<(const Time& T) const
{
	if (hou * 3600 + min * 60 + sec < T.hou * 3600 + T.min * 60 + T.sec)
	{
		return true;
	}
	return false;
}
string Time::TimeStr(const Time& T)
{
	string TimeStr;
	TimeStr[0] = T.hou / 10;
	TimeStr[1] = T.hou % 10;
	TimeStr[2] = ':';
	TimeStr[3] = T.min / 10;
	TimeStr[4] = T.min % 10;
	TimeStr[5] = ':';
	TimeStr[6] = T.sec / 10;
	TimeStr[7] = T.sec % 10;
	return TimeStr;
}
void Time::Check(Time & T)
{
	while (T.sec >= 60)
	{
		T.sec = T.sec - 60;
		T.min++;
	}
	while (T.min >= 60)
	{
		T.min = T.min - 60;
		T.hou++;
	}
	while (T.hou >= 24)
	{
		T.hou = T.hou - 24;	
	}
}

