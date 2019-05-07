#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Date
{
private:
	const int month_value[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int time;
	int day;
	int month;
	int year;
public:
	Date(void);
	Date(const int _time);
	Date(const int _day, const int _month, const int _year);
	Date(const Date& d);
	Date operator+ (const int day);
	Date operator- (const int day);
	Date& operator= (const Date& d);
	int getTime();
	bool operator== (const Date& d);
	friend ostream & operator<< (ostream & out, const Date & d);
	friend istream & operator>> (istream & in, Date & d);
};

