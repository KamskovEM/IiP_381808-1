#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Kassa.h"
#include <string>

using namespace std;

Tovar::Tovar()
{
	code = price = skidka = count = 0;
	name = "0";
}
Tovar::Tovar(int _code, string _name, int _cost, int _skidka, int _count)
{
	code = _code;
	name = _name;
	price = _cost;
	skidka = _skidka;
	count = _count;
}
Tovar::~Tovar() {
	code = price = skidka = count = 0;
	name = "0";
}
bool Tovar::Codecheck(int _code) {
	if (_code == code) return true;
	return false;
}
ostream & operator << (ostream & stream, const Tovar &T)
{
	stream << T.code << ": " << T.name << " " << T.price << "p " << T.skidka << "%" << endl;
	return stream;
}
istream & operator >> (istream & stream, Tovar &T)
{
	stream >> T.code >> T.name >> T.price >> T.skidka;
	return stream;
}
Kassa::Kassa()
{
	tovar = 0;
	size = 0;
}
Kassa::Kassa(int _size)
{
	size = _size;
	buf = size + del;
	tovar = new Tovar[buf];
}
Kassa::~Kassa()
{
	size = 0;
	delete[] tovar;
}
Tovar Kassa::Info(int code)
{
	int i = Scan(code);
	return tovar[i];
}
int Kassa::Scan(int code)
{
	for (int i = 0; i < size; i++)
	{
		if (tovar[i].Codecheck(code)) // proverka na sovpadenie koda
		{
			return i;
		}
	}
	return -1;
}
void Kassa::Delete(int code)
{
	int i = Scan(code);
	if (tovar[i].count > 0) {
		tovar[i].count--;
	}
}
void Kassa::CreateCheck()
{
	bool f = false;
	for (int i = 0; i < size; i++)
	{
		if (tovar[i].count > 0) {
			f = true;
		}
	}
	if (f) {
		cout << "Vash check:" << endl;
		double S = 0;
		for (int i = 0; i < size; i++)
		{
			if (tovar[i].count > 0)
			{
				cout << tovar[i].name << ": " << tovar[i].price << "p x" << tovar[i].count << endl;
				S += (tovar[i].price - tovar[i].price * tovar[i].skidka / 100) * tovar[i].count;
			}
		}
		cout << "\nK oplate(s ychetom skidok):  " << S << "p" << endl;
	}
	else cout << "Vash spisok pokypok pyst" << endl;
}
void Kassa::Add(int code) {
	tovar[Scan(code)].count++;
}
ostream & operator << (ostream & stream, Kassa const &T) {
	stream << T.size << endl;
	for (int i = 0; i < T.size; i++) {
		stream << T.tovar[i];
	}
	return stream;
}
istream & operator >> (istream & stream, Kassa &T) {
	stream >> T.size;
	while(T.size >= T.buf) {
		delete[] T.tovar;
		T.buf += T.del;
		T.tovar = new Tovar[T.size];
	}
	for (int i = 0; i < T.size; i++) {
		stream >> T.tovar[i];
	}
	return stream;
}