#include "Polinom.h"
#include<cmath>
#include<iostream>
#include<fstream>

Polinom::Polinom()
{
	deg = 0;
	value =  new double[deg + 1];
	for (int i = 0; i <deg+1; i++) {
		value[i] = 0;
	}
}
Polinom::Polinom(int n) {
	deg = n;
	value = new double[deg + 1];
}
Polinom::Polinom(int n, double mas[]) {
	deg = n;
    value = new double[deg + 1];
	for (int i = 0; i < deg+1; i++) {
		value[i] = mas[i];
	}
}
Polinom::Polinom(const Polinom& p) {
	deg = p.deg;
	value = new double[deg + 1];
	for (int i = 0; i < deg+1; i++) {
		value[i] = p.value[i];
	}
}
Polinom::~Polinom()
{
	delete(value);
	deg = 0;
	value = 0;
}
void Polinom::out() {
	std::cout << "Степень_полинома- " << deg << ' ';;

	for (int i = deg; i >= 0; i--) {
		if (i != 0)
			std::cout << value[i] << "x^" << i << '+';
		else std::cout << value[i];
	}
	return;
}
double Polinom :: getfun(double x) {
	double y = 0;
	for (int i = 0; i < deg+1; i++) {
		y += value[i] * pow(x, i);
	}
	return y;
}
Polinom Polinom::derivative() { 
	Polinom res(deg-1);
	for (int i = 0; i < res.deg+1; i++)
		res.value[i] = value[i + 1] * (i + 1) ;
	return res;
} 
Polinom& Polinom::operator=(const Polinom& p) {
	deg = p.deg;
	delete(value);
    value = new double[deg + 1];
	for (int i = 0; i < deg+1; i++) {
		value[i] = p.value[i];
	
	}
	return *this;
}
Polinom Polinom::operator+(const Polinom& p) {
	int tmp;
	int tmp2;
	if (deg > p.deg) {
		tmp2 = p.deg;
		tmp = deg;

	}
	else {
		tmp2 = deg;
		tmp = p.deg;
	}
	Polinom res(tmp);


	for (int i = 0; i < tmp2 + 1;i++) {
		res.value[i] = p.value[i] + value[i];
	}
	if (deg > p.deg)
	for (int i = tmp2+1; i < tmp + 1; i++) {
		res.value[i] = value[i];
	}
	else 
		for (int i = tmp2+1; i < tmp + 1; i++) {
		res.value[i] = p.value[i];
	}
	return res;
}
ostream & operator<<(ostream & stream, const Polinom & p)
{
	stream  << p.deg <<' ';;

	for (int i = p.deg; i >= 0; i--) {
	stream << p.value[i]  <<' ' ;
	}
	return stream;
}
istream & operator>>(istream & stream, Polinom & p)
{
	
	stream >> p.deg;
	
	for (int i = p.deg-1; i >= 0; i--) {

		stream >> p.value[i];
}
	return stream;
}
double& Polinom::operator[](int n) {
	if (n < 0)
		throw PolExeption(IndexOutOfRange, "Значение не может быть меньше 0");
	if (n > deg)
		throw PolExeption(IndexOutOfRange, "Значение не может быть больше степени полинома");
	return value[n];
}
const double& Polinom::operator[](int n) const {
	if (n < 0)
		throw PolExeption(IndexOutOfRange, "Значение не может быть меньше нуля");
	if (n > deg)
		throw PolExeption(IndexOutOfRange, "Значение не может быть больше степени полинома");
	return value[n];
}
