#pragma once

void outputMenu(); //Menu

class Triangle {  
private:
	double A, B, C;  //Стороны

public:

	void TestT();  //Тип треугольника
	double Perm(); //Периметр
	double Area();  //Площадь
	void Sides(double a, double b, double c);  //Стороны


};

void InputSides(double *a, double *b, double *c);   //Ввод сторон


