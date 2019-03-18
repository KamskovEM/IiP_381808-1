#pragma once
#include "Date.h"
#include <string>

using namespace std;

class Calendar
{
private:
	const int month_value[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int lenght = 30;
	int cur_lenght;
	Date* time;
	string* event;
public:
	Calendar(void);
	Calendar(const int _lenght);
	Calendar(const Calendar& c);
	void add(const int _time, const string _event);
	void add(const int _day, const int _month, const int _year, const string _event);
	Date getDate(const string _event);
	int getDifference(Date& _date, const string _event);
	int getDifference(const int _day, const int _month, const int _year, const string _event);
	bool dateShift(const string _event, const int _day);
	Calendar& operator= (const Calendar& c);
	friend istream & operator>> (istream & in, Calendar & c);
	friend ostream & operator<< (ostream & out, const Calendar & c);
	~Calendar();
};

