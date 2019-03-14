#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Polynomial.h"
#define MAX 13;
using namespace std;
enum PolynomialExeption { coeffINDOUTOFRANGE }; // тип исключения
Polynomial::Polynomial()
{
	size = 0;
	int sizemax = MAX;
	coeff = new double[sizemax];

}
Polynomial::Polynomial(int _size) {
	size = _size;
	coeff = new double[size + 1];
	int i;
	for (i = 0; i < size + 1; i++)
		coeff[i] = 0.0;
}
Polynomial::~Polynomial() {
	size = 0;
	coeff = NULL;
}
Polynomial::Polynomial(const Polynomial& _Poly)
{
	coeff = new double[_Poly.size];
	for (int i = 0; i <= _Poly.size; i++)
	{
		coeff[i] = _Poly.coeff[i];
	}
	size = _Poly.size;
}
Polynomial& Polynomial::operator= (const Polynomial& _Poly)
{
	if (this != &_Poly) {
		if (size < _Poly.size)
		{
			delete[] coeff;
			size = _Poly.size;
			coeff = new double[size + 1];
		}
		for (int i = 0; i <= size; i++)
		{
			coeff[i] = _Poly.coeff[i];
		}
	}
	return *this;
}
istream& operator>>(istream & stream, Polynomial & _Poly)
{

	for (int i = 0; i <= _Poly.size; i++)
	{
		stream >> _Poly.coeff[i];
	}
	return stream;
}
int Polynomial::GetPolydegree()
{
	return size;
}
double Polynomial::Polyfunvalue(double d1) {
	double y = 0.0;
	int i;
	for (i = 0; i <= size; i++)
		y += coeff[i] * pow(d1, i);
	return y;
}
Polynomial Polynomial::Polydifferential() {
	Polynomial polydif(size - 1);
	for (int i = 0; i <= polydif.size; i++)
	{
		polydif.coeff[i] = (i + 1)*coeff[i + 1];
	}
	return polydif;
}
ostream& operator<<(ostream & stream, const Polynomial & _Poly)
{
	/*Написано сложновато с ипользованием двух флагов, чтобы полином выводился без лишнего + перед 1 коэффицентом */
	int  size = 0;
	bool flag = true;
	bool firstflag = true;
	int i = 0;
	while (i <= _Poly.size && flag == true) {
		if (_Poly.coeff[i] != 0)
			flag = false;
		i++;
	}
	if (flag == false)
	{
		for (i = _Poly.size; i >= 1; i--)
		{
			if (firstflag == true)
			{
				stream << _Poly.coeff[i] << "*x^" << i;;
				firstflag = false;
			}
			else
			{
				if (_Poly.coeff[i] > 0)
				{
					stream << "+" << _Poly.coeff[i] << "*x^" << i;
				}
				if (_Poly.coeff[i] < 0)
				{
					stream << _Poly.coeff[i] << "*x^" << i;
				}
			}
		}
		if (i == 0)
		{
			if (_Poly.coeff[i] < 0)
				stream << _Poly.coeff[i];
			else if (_Poly.coeff > 0)
				stream << "+" << _Poly.coeff[i];
		}
		stream << endl;
	}
	else
	{
		stream << 0;
	}
	return stream;
}
double& Polynomial::operator[](int index) {
	if (index < 0 || index > size) {
		PolynomialExeption expt = coeffINDOUTOFRANGE;
		throw expt;
	}
	return coeff[index];
}
const double& Polynomial::operator[](int index) const {
	if (index < 0 || index > size) {
		PolynomialExeption expt = coeffINDOUTOFRANGE;
		throw expt;
	}
	return coeff[index];
}
//Необязательные методы
void Polynomial::SetPolycoeffs() {
	cout << "Ввод коэффицентов монома с помощью метода SetPolycoeffs:  " << endl;
	for (int i = 0; i <= size; i++)
		cin >> coeff[i];
}
void Polynomial::SetPolydegree(int degree)
{
	size = degree;
	int i;
	for (i = 0; i <= size; i++)
		coeff[i] = 0.0;

}