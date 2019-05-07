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
Triangle::Triangle() { //constructor
	this->sideA = 0;
	this->sideB = 0;
	this->sideC = 0;
}
// This v dannom sluchae ne obyazatel`no pisat`
Triangle::Triangle(int a, int b, int c) { //constructor, esli znachenyia budut<0, to oni stanut ravni 0
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

Triangle::~Triangle() {}; //destructor	
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
		return "����������� �� ����������";
	}
	else {
		if (sideA == sideB && sideB == sideC)
			return "�������������� �����������";
		else if (sideA == sideB || sideB == sideC || sideC == sideA)
			return "�������������� �����������";
		else
			return "�������������� �����������";
	}
}
const char* Triangle::checkTriangleTypetwo() {
	if (!checkIfTriangle()) {
		return "����������� �� ����������";
	}
	else {
		if ((cosinusfun(sideA, sideB, sideC) == 0) || (cosinusfun(sideB, sideC, sideA) == 0) || (cosinusfun(sideC, sideA, sideB) == 0))
		{
			return "������������� �����������";
		}
		else
		{
			if ((cosinusfun(sideA, sideB, sideC) < 0) || (cosinusfun(sideB, sideC, sideA) < 0) || (cosinusfun(sideC, sideA, sideB) < 0))
			{
				return "������������ �����������";
			}
			else
			{
				return "������������� �����������";
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
		cout << "���������� � ������������ � ������� " << i + 1 << ": " << endl;
		cout << "��� ������������ �� ��������: " << triangles[i].checkTriangleType() << endl;
		cout << "��� ������������ �� �����: " << triangles[i].checkTriangleTypetwo() << endl;
		if (triangles[i].checkIfTriangle() == true)
			cout << "������� ������������ �����: " << triangles[i].squareoftriangle() << endl;
		cout << "\n" << endl;
	}
	getchar();
	getchar();
}








