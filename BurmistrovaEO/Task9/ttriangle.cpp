#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
class Triangle
{
public:
	double a, b, c;

	Triangle();
	double perimeter();
	double area();
	double half_perimeter();
	void kind();
	~Triangle();
};
Triangle::Triangle()
{
	cout << "Введите длины сторон: \n";
	while (a + b <= c || b + c <= a || a + c <= b)
	{
		cin >> a;
		cin >> b;
		cin >> c;
	}
};

double Triangle::perimeter() {

	return a + b + c;
}
double Triangle::half_perimeter() {
	return perimeter() / 2;
};

double Triangle::area() {
	double p = half_perimeter();
	return sqrt(p * (p - a) * (p - b)*(p - c));
}
void Triangle::kind() {
	if (a == b && b == c)
		cout << "Равносторонний треугольник";
	if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
		cout << "Равнобедренный треугольник";
	if ((pow(a, 2) + pow(b, 2) == pow(c, 2)) || (pow(c, 2) + pow(b, 2) == pow(a, 2)) || (pow(a, 2) + pow(c, 2) == pow(b, 2)))
		cout << "Прямоугольный треугольник";
	else
		cout << "Остроугольный или тупоугольный треугольник";
}
Triangle :: ~Triangle() {};
int main()
{
	setlocale(LC_CTYPE, "Russian");

	Triangle t1;
	cout << "Вид треугольника:   ";
	t1.kind(); cout << "\n";
	cout << "Периметр тругольника равен:   ";
	cout << t1.perimeter();
	cout << "\n" << "Площадь треугольника равна:   ";
	cout << t1.area();
	getchar();
	getchar();
}