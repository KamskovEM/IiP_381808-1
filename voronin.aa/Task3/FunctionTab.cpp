#include "FunctionTab.h"
#include<cmath>
#include<iostream>
#include<fstream>

FunctionTab::FunctionTab()
{
	interval_a = 0;
	interval_b = 0;
	count = 0;
	points = NULL;
	value = NULL;

	
}
FunctionTab::FunctionTab(double _i1, double _i2,int _n) {
	count = _n;
	interval_a = _i1;
	interval_b = _i2;
	points = new double[count];
	value = new double[count];
}
FunctionTab::FunctionTab(const FunctionTab& _f) {
	interval_a = _f.interval_a;
	interval_b = _f.interval_b;
	count = _f.count;
	if(_f.value!=NULL){
	value = new double[count];
	for (int i = 0; i < count; i++) 
		value[i] = _f.value[i];
	}
	else value = NULL;

	if (_f.points != NULL) {
		points = new double[count];
		for (int i = 0; i < count; i++)
			points[i] = _f.points[i];
	}
	else points = NULL;
}
FunctionTab::~FunctionTab()
{
	delete(value);
	delete(points);
	interval_a = 0;
	interval_b = 0;
	count = 0;
	points = NULL;
	value = NULL;
}

void FunctionTab::setinterval(double _a, double _b) {
	interval_a = _a;
	interval_b = _b;
	return;
}
void FunctionTab::setcount(int _n) {
	count = _n;
	delete(points);
	delete(value);
	points = new double[count];
	value = new double[count];
	return;
}
void FunctionTab::do_tab(double(*function)(double)){
	for (int i = 0; i < count; i++) {
		points[i] = interval_a + i * ((interval_b - interval_a) / count);
	}
	for (int i = 0; i < count; i++) {
		value[i] = function(points[i]);
	}
}
void FunctionTab::get_tab() {
	std::cout << "Левая граница- " << interval_a << "  Правая граница- " << interval_b << "  Количество точек-" << count <<std::endl;
	for (int i = 0; i < count; i++) {
		std::cout << "Точка- " << points[i] << "  Значение " << value[i] << std:: endl;
	}
	return;
}

std::ostream & operator<<(std::ostream & stream, const FunctionTab & _f )
{
	stream << _f.interval_a << ' ' <<_f.interval_b <<' ' <<_f.count <<' ';

	for (int i = 0; i < _f.count; i++) {
		stream <<_f.points[i] <<' ' << _f.value[i] << ' ';
	}
	return stream;
}
std::istream & operator>>(std::istream & stream, FunctionTab & _f)
{

	stream >> _f.interval_a >>_f.interval_b >>_f.count;
	delete(_f.points);
	delete(_f.value);
	_f.points = new double[_f.count];
	_f.value = new double[_f.count];
	for (int i = 0; i <_f.count; i++) {

		stream >>_f.points[i] >> _f.value[i];
	}
	return stream;
}

double function1(double _x) {
	return sin(_x);
}
double function2(double _x) {
	return cos(_x);
}
double function3(double _x) {
	return exp(_x);
}
double function4(double _x) {
	return _x * _x;
}
double function5(double _x) {
	return (pow(_x, 3));
}
double function6(double _x) {
	return (sqrt(abs(_x)));
}
double function7(double _x) {
	return (tan(_x));
}