#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
class triangle {
public:
	void tri(double a, double b, double c);
	bool exist();
	double perimetr();
	double square();
	void Type();
private:
	double A, B, C;
};

void triangle::tri(double a, double b, double c)
{
	A = a;
	B = b;
	C = c;
}
void triangle::Type()
{
	double h, a, b;
	if ((A > B) && (A > C)) { h = A; a = B; b = C; }
	else if ((B >= A) && (B >= C)) { h = B; a = A; b = C; }
	else if ((C > B) && (C > A)) { h = C; a = A; b = B; }
	if (h*h == a * a + b * b) { cout << " Треугольник - прямоугольный" << endl; }
	if (h*h < a * a + b * b) { cout << " Треугольник - остроугольный" << endl; }
	if (h*h > a * a + b * b) { cout << " Треугольник - тупоугольный" << endl; }

}
bool triangle::exist()
{
	if ((A + B > C) && (A + C > B) && (B + C > A)) {
		return 1;
	}
	else
	{

		return 0;
	}
}

double triangle::perimetr()
{
	return (A + B + C);
}
double triangle::square()
{
	double p = (A + B + C) / 2;
	double s = sqrt(p*(p - A)*(p - B)*(p - C));
	return s;

}

int main()
{
	setlocale(LC_CTYPE, "rus");
	cout << "Введите длины сторон треугольника  \n";
	triangle p;
	double a, b, c;
	cin >> a >> b >> c;
	p.tri(a, b, c);
	bool q = p.exist();
	if (q == 1)
	{
		cout << "Треугольник существует \n";
		p.Type();
		cout << "Периметр треугольника = " << p.perimetr() << "\n";
		cout << "Площадь  треугольника = " << p.square() << "\n";
	}
	else 		cout << "Такого треугольника не существует \n";

	getchar();
	getchar();
	return 0;
}
