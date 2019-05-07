#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Thermometer.h"
using namespace std;
Time CreateTime(int _y, int _m, int _d, int _h)
{
	return Time(_y, _m, _d, _h, 0);
}
int main() {
	setlocale(LC_ALL, "Russian");
	int c, y, m, d, h;
	Time t;
	Thermometer T;
	ifstream in;
	in.open("file.txt");
	in >> T;
	in.close();
	cout << "1 - Nachalnye dannye" << endl;
	cout << "2 - Dobavit nablydenie" << endl;
	cout << "3 - Yznat pokazaniya po vremeny" << endl;
	cout << "4 - Yznat vse pokazaniya za sutki" << endl;
	cout << "5 - Yznat srednee pokazaniye v opredelenniy den" << endl;
	cout << "6 - Yznat srednee pokazaniye v opredelenniy mesyac" << endl;
	cout << "7 - Yznat srednee pokazaniye za vse vremya" << endl;
	cout << "8 - Yznat srednee dnevnoe pokazaniye v opredelenniy mesyac" << endl;
	cout << "9 - Yznat srednee nochnoe pokazaniye v opredelenniy mesyac" << endl;
	cout << "0 - Vuhod" << endl;
	bool f = true;
	ofstream out;
	while (f) {
		cin >> c;
		switch (c)
		{
		case 1:
			cout << T.StartInfo() << endl;
			break;
		case 2:
			cout << "Vvedite dannye nablydeniya: ";
			cin >> t;
			T.Add(t);
			cout << "Idet dobavlenie novih pokazanii v fail" << endl;
			out.open("file.txt");
			out << T;
			out.close();
			break;
		case 3:
			cout << "Vvedite datu i vremya: ";
			cin >> y >> m >> d >> h;
			if (T.Temp(CreateTime(y, m, d, h))) { cout << T.Temp(CreateTime(y, m, d, h)) << endl; }
			else cout << "Pokazaniya ne naidenu" << endl;
			break;
		case 4:
			cout << "Vvedite datu: ";
			cin >> y >> m >> d;
			T.TempZaSutki(CreateTime(y, m, d, 0));
			break;
		case 5:
			cout << "Vvedite datu: ";
			cin >> y >> m >> d;
			if (T.SrTempZaSutki(CreateTime(y, m, d, 0))) { cout << T.SrTempZaSutki(CreateTime(y, m, d, 0)) << endl; }
			else cout << "Pokazaniya ne naidenu" << endl;
			break;
		case 6:
			cout << "Vvedite mesyac i god: ";
			cin >> y >> m;
			if (T.SrTempZaMesyac(y, m)) { cout << T.SrTempZaMesyac(y, m) << endl; }
			else cout << "Pokazaniya ne naidenu" << endl;
			break;
		case 7:
			cout << T.SrTempAll() << endl;
			break;
		case 8:
			cout << "Vvedite mesyac i god: ";
			cin >> y >> m;
			if (T.SrTempDnem(y, m)) { cout << T.SrTempDnem(y, m) << endl; }
			else cout << "Pokazaniya ne naidenu" << endl;
			break;
		case 9:
			cout << "Vvedite mesyac i god: ";
			cin >> y >> m;
			if (T.SrTempNochy(y, m)) { cout << T.SrTempNochy(y, m) << endl; }
			else cout << "Pokazaniya ne naidenu" << endl;
			break;
		case 0:
			f = false;
			break;
		default:
			cout << "Viberite cifru iz predstavlennogo spiska: ";
		}
		ifstream in;
		in.open("file.txt");
		in >> T;
		in.close();
	}
	getchar();
	getchar();
	return 0;
}