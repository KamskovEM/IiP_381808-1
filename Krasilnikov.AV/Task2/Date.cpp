#include "Date.h"



Date::Date(void)
{
	time = 0;
	day = 1;
	month = 1;
	year = 1;
}


Date::Date(const int _time)
{
	day = 1;
	month = 1;
	year = 1;
	time = _time;
	int i = 1;
	while (time > 365) {
		if (i % 400 == 0 || ((i % 100 != 0) && (i % 4 == 0))) {
			year++;
			time -= 366;
		}
		else {
			year++;;
			time -= 365;
		}
		i++;
	}
	if (!(i % 400 == 0 || ((i % 100 != 0) && (i % 4 == 0))) && time == 365) {
		year++;
		time -= 365;
	}
	i = 0;
	while (time >= month_value[i]) {
		if (i == 1 && (year % 400 == 0 || ((year % 100 != 0) && (year % 4 == 0)))) {
			if (time > month_value[i]) {
				time -= month_value[i] + 1;
				month++;
				i++;
			}
			else {
				break;
			}
		}
		else {
			time -= month_value[i];
			month++;
			i++;
		}
	}
	day += time;
	time = _time;
}

Date::Date(const int _day, const int _month, const int _year)
{
	time = 0;
	day = _day;
	month = _month;
	year = _year;
	for (int i = 1; i < _year; i++) {
		if (i % 400 == 0 || ((i % 100 != 0) && (i % 4 == 0))) {
			time += 366;
		}
		else {
			time += 365;
		}
	}
	for (int i = 1; i < _month; i++) {
		time += month_value[i - 1];
		if (i == 2 && (_year % 400 == 0 || ((_year % 100 != 0) && (_year % 4 == 0)))) {
			time++;
		}
	}
	time += _day;
}

Date::Date(const Date & d)
{
	time = d.time;
	day = d.day;
	month = d.month;
	year = d.year;
}

Date Date::operator+(const int day)
{
	if (time + day < 737790) {
		Date d(time + day);
		return d;
	}
	else {
		return *this;
	}
}

Date Date::operator-(const int day)
{
	if (time - day >= 0) {
		Date d(time - day);
		return d;
	}
	else {
		return *this;
	}
}

Date & Date::operator=(const Date & d)
{
	time = d.time;
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}

int Date::getTime()
{
	return time;
}

bool Date::operator==(const Date & d)
{
	if (time == d.time) {
		return 1;
	}
	else {
		return 0;
	}
}

ostream & operator<<(ostream & out, const Date & d)
{
	out << setw(2) << setfill('0') << d.day << '.';
	out << setw(2) << setfill('0') << d.month << '.';
	out << setw(4) << setfill('0') << d.year;
	return out;
}

istream & operator>>(istream & in, Date & d)
{
	int day, month, year;
	char c;
	in >> day >> c >> month >> c >> year;
	d.day = day;
	d.month = month;
	d.year = year;
	return in;
}
