#include "Polinom.h"

Polinom::Polinom() {
	kof = NULL;
	n = 0;
}
Polinom::Polinom(int def) {
	n = def;
	kof = new double[n + 1];
	for (int i = 0; i <= n; i++) {
		kof[i] = 0.0;
	}
}
Polinom::Polinom(const Polinom &c) {
	n = c.n;
	kof = new double[n + 1];
	for (int i = 0; i <= n; i++) {
		kof[i] = c.kof[i];
	}
}

Polinom::~Polinom() {
	kof = NULL;
	n = 0;
}
int Polinom::GetDl() {//Polu4enie stepeni
	return n;
}
Polinom& Polinom:: operator+(const Polinom &c) {//operator summi
	if (n >= c.n)//A>B
	{
		Polinom non = *this;
		for (int i = 1; i <= n; i++)
			non.kof[i] = kof[i] + c.kof[i];
		return non;
	}
	else//A<B
	{
		Polinom non = c;
		for (int i = 1; i <= n; i++)
			non.kof[i] = c.kof[i] + kof[i];
		return non;
	}
}
istream &operator >> (istream &s, Polinom &c) {//vvod
	for (int i = 0; i <= c.n; i++) {
		s >> c.kof[i];
	}
	return s;
}
void Polinom::showPolinom(const Polinom& c) {//vivod
	for (int i = 1; i <= c.n; i++) {
		if (c.kof[i] == 0)
			cout << "";
		else
			if (i != 1) {
				if (c.kof[i] > 0)
					if (c.kof[i] != 1)
						cout << "+" << c.kof[i] << "x^" << i;
					else
						cout << "+" << "x^" << i;
				else
					if (c.kof[i] != -1)
						cout << "" << c.kof[i] << "x^" << i << "";
					else
						cout << "-" << "x^" << i << "";

			}
		if (i == 1 && c.kof[i] != 0)
			cout << c.kof[i] << "x";
	}
	cout << endl;
}
Polinom Polinom::Show_Pol() {
	Polinom fas(n);
	for (int i = 1; i <= n; i++) {
		fas.kof[i] = kof[i];
	}
	showPolinom(fas);
	return fas;
}
ostream &operator << (ostream &s, const Polinom &c) {
	for (int i = 1; i < c.n; i++) {
		s << c.kof[i] << " ";
	}
	return s;
}
Polinom& Polinom::operator = (const Polinom &c) {//operator ravenstva
	if (this != &c)
	{
		if (n != c.n)
		{
			n = c.n;
			delete[] kof;
			kof = new double[n + 1];
		}
		for (int i = 0; i <= c.n; i++)
			kof[i] = c.kof[i];
	}
	return *this;
}
double Polinom::getkof(int i) {//polu4enie koeficienta po nomeru stepeni
	if (i <= n)
		return kof[i];
	else
		return 0.0;
}
double Polinom::s4et(double x) {//pods4et polinoma
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += kof[i] * pow(x, i);
	}
	return sum;
}
Polinom Polinom::proizvod() {//proizvodnaya
	Polinom fas(n);
	for (int i = 1; i <= n; i++) {

		if (i != 1) {
			fas.kof[i] = kof[i+1] * (i+1);
		}
		else if (i == 1) {
			fas.kof[i] = kof[i];
		}
	}
	showProizvod(fas);
	return fas;
}

void Polinom::showProizvod(const Polinom& c) {//vivod proizvodnoy
	for (int i = 1; i <= c.n; i++) {
		if (c.kof[i] == 0)
			cout << "";
		else
			if (i != 1 && i != 2) {
				if (c.kof[i] > 0)
					if (c.kof[i] != 1)
						cout << "+" << c.kof[i] << "x^" << i - 1;
					else
						cout << "+" << "x^" << i - 1;
				else
					if (c.kof[i] != -1)
						cout << "" << c.kof[i] << "x^" << i - 1 << "";
					else
						cout << "-" << "x^" << i - 1 << "";

			}
		if (i == 1 && c.kof[i] != 0)
			cout << c.kof[i] << "";
		if (i == 2 && c.kof[i] != 0)
			if (c.kof[i] > 0)
				cout << "+" << c.kof[i] << "x";
			else
				cout << c.kof[i] << "x";
	}
	cout << endl;
}

