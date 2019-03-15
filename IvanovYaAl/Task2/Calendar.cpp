#include "Calendar.h"

Calendar::Calendar() {
	date = 0;
	month = 0;
	year = 0;
	event = ' ';
}

Calendar::Calendar(const Calendar &c) {
	date = c.date;
	month = c.month;
	year = c.year;
	event = c.event;
}

Calendar::Calendar(int _date, int _month, int _year, string _event) :
	date(_date), month(_month), year(_year), event(_event) {}

Calendar::~Calendar() {
	date = 0;
	month = 0;
	year = 0;
	event = ' ';
}

ostream& operator<<(ostream& stream, const Calendar& c) {
	stream << c.date << " " << c.month << " " << c.year << " " << c.event;
	return stream;
}

istream& operator>>(istream& stream, Calendar& c) {
	stream >> c.date >> c.month >> c.year >> c.event;
	return stream;
}

Calendar Calendar:: operator -(const Calendar& second) {
	Calendar tmp;
	tmp.year = year - second.year;
	tmp.month = month - second.month;
	tmp.date = date - second.date;
	if (tmp.month < 0) {
		tmp.year--;
		tmp.month += 12;
	}
	if (tmp.date < 0) {
		tmp.date += dateMonth(second);
		tmp.month--;
	}
	if (tmp.year < 0) {
		tmp.year *= -1;
	}
	return tmp;
}

Calendar Calendar::operator ^ (Calendar pop) {
	int u = 0;
	cout << "Future(1) or Past(2)?" << endl;
	cout << "Choose: " << endl;
	cin >> u;
	cout << "Na skol'ko delat' sdvig?" << endl;
	int l1, l2, l3;
	cin >> l1 >> l2 >> l3;
	pop.year = l3;
	pop.month = l2;
	pop.date = l1;
	Calendar sd, ikar;
	ikar.date = date;
	ikar.month = month;
	ikar.year = year;
	if (u == 1) {
		sd.year = year + pop.year;
		sd.date = date + pop.date;
		if (sd.date > dateMonth(sd)) {
			sd.date += dateMonth(sd);
			month++;
		}
		sd.month = month + pop.month;
		if (sd.month > 12) {
			sd.year++;
			sd.month -= 12;
		}
	}
	if (u == 2) {
		sd = ikar - pop;
	}
	sd.event = event;
	cout << "Vvedite novoe sobitie: " << endl;
	string sob;
	cin >> sob;
	event = sob;
	return sd;
}


