#pragma once

void outputMenu(); //Menu

class Triangle {  
private:
	double A, B, C;  //�������

public:

	void TestT();  //��� ������������
	double Perm(); //��������
	double Area();  //�������
	void Sides(double a, double b, double c);  //�������


};

void InputSides(double *a, double *b, double *c);   //���� ������


