#include <iostream> 
#include <vector> 
#include <cmath> 
#include <stdexcept> 
#include <cstdlib> 
#include <ctime> 
using namespace std;

class Triangle {

private:
	double sideA, sideB, sideC;

public:

	Triangle();
	Triangle(int a, int b, int c);
	~Triangle();
	bool checkIfTriangle();
	double cosinusfun(double a, double b, double c);
	const char* checkTriangleType();
	const char* checkTriangleTypetwo();
	double squareoftriangle();
};
Triangle::Triangle() { //конструктор
	this->sideA = 0;
	this->sideB = 0;
	this->sideC = 0;
}
// this в данном случае можно было бы не писать
Triangle::Triangle(int a, int b, int c) { //конуструктор, если значения будут неположительными, то они станут равны 0
	if (a < 0 || b < 0 || c < 0) {
		this->sideA = 0;
		this->sideB = 0;
		this->sideC = 0;
	}
	else {
		this->sideA = a;
		this->sideB = b;
		this->sideC = c;
	}
}

Triangle::~Triangle() {}; //деструктор	
bool Triangle::checkIfTriangle() {
	if (sideA + sideB > sideC && sideC + sideB > sideA && sideA + sideC > sideB)
		return true;
	else return false;
}
double Triangle::cosinusfun(double a, double b, double c) {
	double cosinus = (c*c + b * b - a * a) / (2.0 * b*c);
	return cosinus;
}
const char* Triangle::checkTriangleType() {
	if (!checkIfTriangle()) {
		return "Треугольник не существует";
	}
	else {
		if (sideA == sideB && sideB == sideC)
			return "Равносторонний треугольник";
		else if (sideA == sideB || sideB == sideC || sideC == sideA)
			return "Равнобедренный треугольник";
		else
			return "Разносторонний треугольник";
	}
}
const char* Triangle::checkTriangleTypetwo() {
	if (!checkIfTriangle()) {
		return "Треугольник не существует";
	}
	else {
		if ((cosinusfun(sideA, sideB, sideC) == 0) || (cosinusfun(sideB, sideC, sideA) == 0) || (cosinusfun(sideC, sideA, sideB) == 0))
		{
			return "Прямоугольный треугольник";
		}
		else
		{
			if ((cosinusfun(sideA, sideB, sideC) < 0) || (cosinusfun(sideB, sideC, sideA) < 0) || (cosinusfun(sideC, sideA, sideB) < 0))
			{
				return "Тупоугольный треугольник";
			}
			else
			{
				return "Остроугольный треугольник";
			}
		}
	}
}
double Triangle::squareoftriangle() {
	double p = (sideA + sideB + sideC) / 2.0;
	double square = sqrt(p*(p - sideA)*(p - sideB)*(p - sideC));
	return square;
}
int main() {
	setlocale(LC_CTYPE, "Russian");
	Triangle test1(-1, -2, -3);
	Triangle test2(-1, 2, 3);
	Triangle test3(0, 0, 0);
	Triangle test4(2, 0, 3);
	Triangle test5(1, 3, 5);
	Triangle test6(3, 5, 7);
	Triangle test7(3, 4, 5);
	Triangle test8(5, 6, 9);
	Triangle test9(5, 5, 9);
	Triangle test10(3, 3, 3);
	Triangle triangles[10] = { test1,test2,test3,test4,test5,test6,test7,test8, test9, test10 };
	for (int i = 0; i < 10; i++) {
		cout << "Информация о треугольнике с номером " << i + 1 << ": " << endl;
		cout << "Тип треугольника по сторонам: " << triangles[i].checkTriangleType() << endl;
		cout << "Тип треугольника по углам: " << triangles[i].checkTriangleTypetwo() << endl;
		if (triangles[i].checkIfTriangle() == true)
			cout << "Площадь треугольника равна: " << triangles[i].squareoftriangle() << endl;
		cout << "\n" << endl;
	}
	getchar();
	getchar();
}







