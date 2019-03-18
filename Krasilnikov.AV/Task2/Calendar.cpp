#include "Calendar.h"


Calendar::Calendar(void)
{
	cur_lenght = 0;
	time = new Date[lenght];
	event = new string[lenght];
}

Calendar::Calendar(const int _lenght)
{
	cur_lenght = 0;
	lenght = _lenght;
	time = new Date[lenght];
	event = new string[lenght];
}

Calendar::Calendar(const Calendar & c)
{
	lenght = c.lenght;
	cur_lenght = c.cur_lenght;
	time = new Date[lenght];
	event = new string[lenght];
	for (int i = 0; i < lenght; i++) {
		time[i] = c.time[i];
		event[i] = c.event[i];
	}
}

void Calendar::add(const int _time, const string _event)
{
	if (_time > 737789 || _time < 0) {
		throw exception("Incorrect date");
	}
	if (cur_lenght == lenght) {
		throw exception("Calendar is full");
	}
	Date d(_time);
	time[lenght] = d;
	event[lenght] = _event;
	lenght++;
	return;
}

void Calendar::add(const int _day, const int _month, const int _year, const string _event)
{
	if (_year > 2020 || _year < 1 || _month > 12 || _month < 1 || _day < 1) {
		throw exception("Incorrect date");
	}
	if (cur_lenght == lenght) {
		throw exception("Calendar is full");
	}
	Date d(_day, _month, _year);
	time[cur_lenght] = d;
	event[cur_lenght] = _event;
	cur_lenght++;
	return;
}

Date Calendar::getDate(const string _event)
{
	for (int i = 0; i < cur_lenght; i++) {
		if (_event == event[i]) {
			return time[i];
		}
	}
	return Date(0);
}

int Calendar::getDifference(Date & _date, const string _event)
{
	for (int i = 0; i < cur_lenght; i++) {
		if (_event == event[i]) {
			return abs((time[i] - _date.getTime()).getTime());
		}
	}
	return -1;
}

int Calendar::getDifference(const int _day, const int _month, const int _year, const string _event)
{
	Date d(_day, _month, _year);
	for (int i = 0; i < cur_lenght; i++) {
		if (_event == event[i]) {
			d - time[i].getTime();
			return abs((d - time[i].getTime()).getTime());
		}
	}
	return -1;
}

bool Calendar::dateShift(const string _event, const int _day)
{
	for (int i = 0; i < cur_lenght; i++) {
		if (_event == event[i]) {
			Date d(time[i] + _day);
			for (int j = 0; j < cur_lenght; j++) {
				if (d == time[j]) {
					return 0;
				}
			}
			time[i] = d;
			return 1;
		}
	}
	return 0;
}

Calendar & Calendar::operator=(const Calendar & c)
{
	lenght = c.lenght;
	cur_lenght = c.cur_lenght;
	delete[] time;
	delete[] event;
	time = new Date[lenght];
	event = new string[lenght];
	for (int i = 0; i < cur_lenght; i++) {
		time[i] = c.time[i];
		event[i] = c.event[i];
	}
	return *this;
}


Calendar::~Calendar()
{	
	delete[] time;
	delete[] event;
}

istream & operator>>(istream & in, Calendar & c)
{
	in >> c.cur_lenght;
	for (int i = 0; i < c.cur_lenght; i++) {
		in >> c.time[i];
		getline(in, c.event[i]);
	}
	return in;
}

ostream & operator<<(ostream & out, const Calendar & c)
{
	out << c.cur_lenght;
	for (int i = 0; i < c.cur_lenght; i++) {
		out << endl;
		out << c.time[i] << ' ' << c.event[i];
	}
	return out;
}
