#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Thermometer.h"
using namespace std;
Time::Time() 
{
	day = month = year = hour = temp = 0;
}
Time::Time(int _year, int _month, int _day, int _hour, int _temp)
{
	year = _year;
	month = _month;
	day = _day;
	hour = _hour;
	temp = _temp;
}
Time::~Time() {
	day = month = year = hour = temp = 0;
}
bool Time::Datecheck(Time T)
{
	if (year == T.year && month == T.month && day == T.day)
		return true;
	return false;
}
bool Time::Yearcheck(int _year) {
	if (_year == year) return true;
	return false;
}
bool Time::Monthcheck(int _month) {
	if (_month == month) return true;
	return false;
}
ostream & operator << (ostream & stream, const Time &T)
{
	stream << " " << T.year << " " << T.month << " " << T.day << " " << T.hour << " " << T.temp << endl;
	return stream;
}
istream & operator >> (istream & stream, Time &T) 
{
	stream >> T.year >> T.month >> T.day >> T.hour >> T.temp;
	return stream;
}
Thermometer::Thermometer()
{
	time = 0;
	size = 0;
}
Thermometer::Thermometer(Time T, int _size)
{
	size = _size;
	time = new Time[size];
}
Thermometer::~Thermometer() 
{
	size = 0;
	delete[] time;
}
Time Thermometer::StartInfo()
{ 
	return time[0];
}
int Thermometer::Temp(Time T) 
{ 
	int i = 0;
	for (int i = 0; i < size; i++)
	{
		if (time[i].Datecheck(T) && time[i].hour == T.hour) {
			return time[i].temp;
		}
	}
	return false; // na slychai esli net pokazatelei, chtobi ne podumali chto temp. = 0
}
void Thermometer::TempZaSutki(Time T)
{
	bool f = true;
	int i = 0;
	for (int i = 0; i < size; i++)
	{
		if (time[i].Datecheck(T))
		{
			f = false;
			cout << time[i].hour << ":00 - " << time[i].temp << endl;
		}
	}
	if (!f) return;
	cout << "Ne Naideno" << endl;
}
double Thermometer::SrTempZaSutki(Time T)
{
	bool f = true;
	int i = 0, k = 0;
	double tmp = 0;
	for (int i = 0; i < size; i++)
	{
		if (time[i].Datecheck(T))
		{
			tmp = tmp + time[i].temp;
			k++;
			f = false;
		}
	}
	if (!f) return tmp / k;
	return f;
}
double Thermometer::SrTempZaMesyac(int _year, int _month)
{ 
	bool f = true;
	int i = 0, k = 0;
	double tmp = 0;
	for (int i = 0; i < size; i++)
	{
		if (time[i].Monthcheck(_month) && time[i].Yearcheck(_year))
		{
			tmp = tmp + time[i].temp;
			f = false;
			k++;
		}
	}
	if (!f) return tmp / k;
	return f;
}
double Thermometer::SrTempAll() {
	double tmp = 0;
	int k = 0;
	for (int i = 0; i < size; i++) 
	{
		tmp = tmp + time[i].temp;
		k++;
	}
	return tmp / k;
}
double Thermometer::SrTempDnem(int _year, int _month)
{
	bool f = true;
	int i = 0, k = 0;
	double tmp = 0;
	for (int i = 0; i < size; i++)
	{
		if (time[i].Monthcheck(_month) && time[i].Yearcheck(_year) && time[i].hour > 6 && time[i].hour <= 18)
		{
			tmp = tmp + time[i].temp;
			k++;
			f = false;
		}
	}
	if (!f) return tmp / k;
	return f;
}
double Thermometer::SrTempNochy(int _year, int _month) {
	bool f = true;
	int i = 0, k = 0;
	double tmp = 0;
	for (int i = 0; i < size; i++)
	{
		if (time[i].Monthcheck(_month) && time[i].Yearcheck(_year) && (time[i].hour <= 6 || time[i].hour > 18)) {
			tmp = tmp + time[i].temp;
			k++;
			f = false;
		}
	}
	if (!f) return tmp / k;
	return f;
}
void Thermometer::Add(Time T) { 
	Time* timetmp; 
	timetmp = new Time[size + 1]; // sozdanie novogo massiva size + 1 dlya novogo izmereniya
	for (int i = 0; i < size; i++) 
	{
		timetmp[i] = time[i];
	}
	timetmp[size] = T;
	size++;
	time = timetmp;
}
istream & operator >> (istream & stream, Thermometer &_T) {
	stream >> _T.size;
	_T.time = new Time[_T.size];
	for (int i = 0; i < _T.size; i++) {
		stream >> _T.time[i];
	}
	return stream;
}
ostream & operator << (ostream & stream, Thermometer const &_T) {
	stream << _T.size << endl;
	for (int i = 0; i < _T.size; i++) {
		stream << _T.time[i] << " ";
	}
	return stream;
}