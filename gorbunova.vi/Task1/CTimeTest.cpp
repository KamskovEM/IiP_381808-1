#include <iostream>
#include "CTime.h"

using namespace std;

int main()
{
	//Testirovanie constructorov
	cout << CTime(123) << endl;
	cout << CTime(10, 12, 13) << endl;
	cout << CTime("14:15:16") << endl;
	cout << endl;
	CTime time1("14:15:16");
	CTime time2("12:14:13");

	//Testirovanie operatsyi
	cout << time1 + time2 << endl;
	cout << time1 - time2 << endl;
	cout << (time1 > time2) << endl;
	cout << (time1 < time2) << endl;

	time1 = time2;
	cout << (time1 == time2) << endl;
	return 0;
}