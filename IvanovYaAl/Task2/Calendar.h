#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class Calendar {
public:
	int date;//data
	int month;//mesyac
	int year;//god
	string event;//sobitie
	Calendar();//konstructor po umolchaniu
	Calendar(const Calendar &c);//konstructor kopirovaniya
	Calendar(int _date, int _month, int _year, string _event);//konstructor inicilizacii

	~Calendar();//destructor

	void setDate(int o) {//funkcii zapici v kalss ( da ya znau chto u menya vvod peregrujen, eto na vsyakiy sluchai)
		date = o;
	}
	void setMonth(int k) {
		month = k;
	}
	void setYear(int l) {
		year = l;
	}
	void setEvent(string p) {
		event = p;
	}
	void setAll(int o, int k, int l, string p) {
		setDate(o);
		setMonth(k);
		setYear(l);
		setEvent(p);
	}
	bool leapYear(Calendar leap) {//vesakosniy god
		if (leap.year % 4 != 0) { return 0; }
		else if (leap.year % 100 == 0) {
			if (leap.year % 400 == 0) { return 1; }
			else { return 0; }
		}
		else { return 1; }
	}
	int dateMonth(Calendar _month) {//kol-vo dney v mesyace
		if ((_month.month == 2) && (leapYear(_month))) {
			return 29;
		}
		else if ((_month.month == 1) | (_month.month == 3) | (_month.month == 5) | (_month.month == 7) | (_month.month == 8) | (_month.month == 10) | (_month.month == 12)) {
			return 31;
		}
		else if ((_month.month == 2) && !(leapYear(_month))) {
			return 28;
		}
		else {
			return 30;
		}
	}
	friend ostream& operator << (ostream& stream, const Calendar& c);
	friend istream& operator >> (istream& stream, Calendar& c);
	Calendar operator-(const Calendar& second);//operator vichitaniya
	Calendar operator ^(Calendar pop);//operator sdviga
};
ostream& operator << (ostream& stream, const Calendar& c);
istream& operator >> (istream& stream, Calendar& c);