#include "Tabulator.h"

Tabulator::Tabulator() {
	n = 0;
	a = 0.0;
	b = 0.0;
	inter = 0.0;
	pointY = NULL;
	pointX = NULL;
}
Tabulator::Tabulator(int _n, double _a, double _b) {
	n = _n;
	a = _a;
	b = _b;
	pointX = new double[n + 2];
	pointY = new double[n + 2];
	for (int i = 0; i < n + 2; i++) {
		pointX[i] = 0.0;
		pointY[i] = 0.0;
	}
}
Tabulator::Tabulator(const Tabulator& c) {
	n = c.n;
	a = c.a;
	b = c.b;
	pointX = new double[n + 2];
	pointY = new double[n + 2];
	for (int i = 0; i < n + 2; i++) {
		pointX[i] = c.pointX[i];
		pointY[i] = c.pointY[i];
	}
}
Tabulator::~Tabulator() {
	n = 0;
	a = 0.0;
	b = 0.0;
	delete[] pointX;
	pointX = NULL;
	delete[] pointY;
	pointY = NULL;
}
int Tabulator::Return_N(int n) {
	return n;
}
double Tabulator::Return_A(double a) {
	return a;
}
double Tabulator::Return_B(double b) {
	return b;
}

void Tabulator::Tabulirovanie(Tfunc* _func) {
	double coppyA = a;
	func = _func;
	double inter = (b - coppyA) / (n + 1);

	for (int i = 0; i < n + 2; i++) {
		pointX[i] = coppyA;
		pointY[i] = func(pointX[i]);
		coppyA += inter;
	}
}
void Tabulator::TabShow() {
	double inter = (b - a) / (n + 1);
	cout << "Kol-vo to4ek: " << n << endl;
	cout << "Interval: " << inter << endl;
	cout << "Interval ot " << a << "  do  " << b << endl;
	for (int i = 0; i < n + 2; i++) {
		cout << "Y" << i << " = " << pointY[i] << "   X" << i << " = " << pointX[i] << endl;
	}
	cout << endl;
}
ostream& operator << (ostream& stream, const Tabulator& c) {
	stream << c.a << " " << c.b << " " << c.n << " " << endl;
	for (int i = 0; i < c.n + 2; i++) {
		stream << c.pointX[i] << "  ";
	}
	for (int i = 0; i < c.n + 2; i++) {
		stream << c.pointY[i] << "  ";
	}
	stream << endl;
	return stream;
}
istream& operator >> (istream& stream, Tabulator& c) {
	int NewN;
	double NewA, NewB;
	stream >> NewA >> NewB >> NewN;
	c.a = NewA;
	c.b = NewB;
	c.n = NewN;
	c.pointX = new double[c.n + 2];
	c.pointY = new double[c.n + 2];
	for (int i = 0; i < c.n + 2; i++) {
		stream >> c.pointX[i];
	}
	for (int i = 0; i < c.n + 2; i++) {
		stream >> c.pointY[i];
	}
	return stream;
}