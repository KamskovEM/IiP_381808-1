#pragma once
#include <iostream>
#include <locale.h>
#include "Triangle.h"

using namespace std;

Triangle::Triangle() { A = 0; B = 0; C = 0; }

Triangle::Triangle(Triangle& Tri) { Tri.A = A; Tri.B = B; Tri.C = C; }

Triangle::Triangle(double a, double b, double c) { A = a; B = b; C = c; }

Triangle::~Triangle() { A = 0; B = 0; C = 0; }

bool Triangle::TriangleCorrect(){
	if ((A + B > C) && (A + C > B) && (B + C > A)) return 0; return 1;
}


double Triangle::Cos(double a, double b, double c) {
	return (a*a - b * b - c * c) / (-1 * 2 * b*c);
}

int Triangle::Type(){
	if (Cos(A, B, C) < 0 || Cos(B, A, C) < 0 || Cos(C, A, B) < 0) { return 1; };
	if (abs(Cos(A, B, C)) < 0.01 || abs(Cos(B, A, C)) < 0.01 || abs(Cos(C, A, B)) < 0.01) { return 2; };
	return 3;
}

int Triangle::Equiteral(){
	if (abs(A - B) < 0.01 && abs(A - C) < 0.01 && abs(B - C) < 0.01) { return 1; };
	if (abs(A - B) < 0.01 || abs(A - C) < 0.01 || abs(B - C) < 0.01) { return 2; };
	return 0;
}

double Triangle::Square(){
	double p = (A + B + C) / 2;
	return sqrt(p*(p - A)*(p - B)*(p - C));
}

double Triangle::Perimetr() {
	double p = A + B + C;
	return p;
}