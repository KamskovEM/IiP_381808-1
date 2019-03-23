#include "Polinom.h"



Polinom::Polinom()
{
	k = 0;
	coef = NULL;
}

Polinom::Polinom(const Polinom& i) 
{
	k = i.k;
	coef = new double[k + 1];
	for (int j = 0; j < k + 1; j++) coef[j] = i.coef[j];
};

Polinom::Polinom(int _k) 
{
	k = _k;
	coef = new double[k + 1];
	for (int j = 0; j < k + 1; j++)coef[j] = 0.0;
};

Polinom::~Polinom()
{
	k = 0;
	coef = NULL;
	delete[] coef;
}

Polinom Polinom::operator+(const Polinom& i)
{	
	if (k == i.k) {
		Polinom Res(k);
		for (int j = 0; j < k + 1; j++) Res.coef[j] = coef[j] + i.coef[j];
		return Res;
	}
	else {
		if (k < i.k) {
			Polinom Res(i.k);
			for (int j = 0; j < k + 1; j++) Res.coef[j] = coef[j] + i.coef[j];
			for (int j = k + 1; j < i.k + 1; j++) Res.coef[j] = i.coef[j];
			return Res;
		}
		else {
			Polinom Res(k);
			for (int j = 0; j < i.k + 1; j++) Res.coef[j] = coef[j] + i.coef[j];
			for (int j = i.k + 1; j < k + 1; j++) Res.coef[j] = coef[j];
			return Res;
		}
	}
	}
	


Polinom& Polinom::operator=(const Polinom& i)
{
	if (this != &i)
	{
		if (k != i.k)
		{
			delete[] coef;
			k = i.k;
			coef = new double[k + 1];
		}
	}
		for (int j = 0; j < k + 1; j++) coef[j] = i.coef[j];

		return *this;
}

double& Polinom::operator[](int j)
{
	if (j >= 0 && j < k + 1) return coef[j];
	else throw Excep(WrongValue, j);
}

void Polinom::Output()
{
	cout << coef[0];
	if (coef[1] != 0) 
	{
	if (coef[1] > 0)
		cout << "+" << coef[1] << "x";
	else cout << coef[1] << "x";
	}
	for(int j=2;(j<k+1);j++)
	{
		if (coef[j] == 0)
		{
			continue;
		}
		else 
		{
			if (coef[j] > 0)
			{
				if(coef[j]==1)cout << "+" << "x^" << j;
				else
				cout << "+" << coef[j] << "x^" << j;
			}
			else 
			{
				if (coef[j] == -1)cout << "-" << "x^" << j;
				else
					cout << coef[j] << "x^" << j;
			}
		}
	}
	cout << endl;
}

double Polinom::FuncVal(double x)
{
	double res=0;
	for (int j = 0; j < k + 1; j++)res = res + coef[j] * pow(x, j);
	return res;

}
Polinom Polinom::devar()
{
	Polinom i(k-1);
	for (int j = 0; j < k; j++)i.coef[j] = (j + 1)*coef[j + 1];
	return i;
}

ostream& operator<<(ostream& stream, const Polinom& i) 
{
	stream << i.k;
	for (int j = 0; j <= i.k; j++)
	{
		stream << ' ' << i.coef[j];
	}
	return stream;
}
istream& operator>>(istream& stream, Polinom& i)
{
	stream >> i.k;
	i.coef = new double[i.k];
	for (int j = 0; j < i.k + 1; j++) 
		stream >> i.coef[j];
	return stream;
}
