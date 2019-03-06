#pragma once

class Triangle
{
private:
	double A, B, C;//Стороны треугольника
public:
	//Конструкторы-----------------------------------------
	Triangle(void);//По умолчанию
	Triangle(Triangle&);//Копирования
	Triangle(double a, double b, double c);//Иннициализации
	//Деструкторы------------------------------------------
	~Triangle();
	//Методы-----------------------------------------------
	bool TriangleCorrect();//Проверка существования треугольника
	int Type();//Определение типа треугольника
	int Equiteral();//равносторонний или равнобедренный
	double Square();//Площадь
	double Perimetr();//Периметр
	double GetA() { return A; }//Возвращает значение стороны
	double GetB() { return B; }
	double GetC() { return C; }
	double Cos(double a, double b, double c);//Косинус угла между В и С
};
