#include "Tabulating.h"



Tabulating::Tabulating()
{
	a = 0;
	b = 0;
	n = 0;
	AX = NULL;
	FY = NULL;
}

Tabulating::Tabulating(double _a, double _b, int _n)
{
	a = _a;
	b = _b;
	n = _n;
	AX = new double[n];
	FY = new double[n];
}

Tabulating::Tabulating(const Tabulating &c)
{
	a = c.a;
	b = c.b;
	n = c.n;
	AX = new double[n];
	FY = new double[n];
	for (int i = 0; i < n+2; i++)
	{
		AX[i] = c.AX[i];
		FY[i] = c.FY[i];

	}
}

Tabulating::~Tabulating()
{
	a = 0;
	b = 0;
	n = 0;
	delete[] AX;
	AX = NULL;
	delete[] FY;
	FY = NULL;
}

double Tabulating::Checka()
{
	return a;
}

double Tabulating::Checkb()
{
	return b;
}

int Tabulating::Checkn()
{
	return n;
}

void Tabulating::Tabul(FTab* F)
{
	double f;
	double sec = (b - a) / (n - 1);
	for (int i=0, f=a;i<n-1;i++,f+=sec) 
	{
		AX[i] = f;
		FY[i] = F(f);
	}
	AX[n-1] = b;
	FY[n-1] = F(b);
}

void Tabulating::ResultTabul()
{
	cout << "Результаты табулирования промежутка ["<<a<<","<<b<<"] на "<<n<<" точек:" << endl;
	for (int i = 0; i <= n-1; i++)
	{
		cout << "X = " << AX[i] << " | Y = " << FY[i] << endl;

	}
}

ostream& operator<<(ostream& stream, const Tabulating& c) {
	stream << c.a << ' ' << c.b << ' ' << c.n << ' ';
	for (int i = 0; i < c.n-1; i++) {
		stream << c.AX[i] << ' ' << c.FY[i] << endl;
	}
	
	return stream;
}

istream& operator>>(istream& stream, Tabulating& с) {
	с.AX = new double[с.n];
	с.FY = new double[с.n];
	stream >> с.a >> с.b >> с.n;
	for (int i = 0; i < с.n-1; i++) {
		stream >> с.AX[i] >> с.FY[i];
	}
	return stream;
}