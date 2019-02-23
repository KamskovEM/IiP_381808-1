#include <iostream> 
#include <cstdlib> 

#include <string> 
#include <cmath> 
using namespace std;
class triangle {
public:
	void tri(double a, double b, double c);
	bool exist();//проверка, существует ли треугольник?
	double perimetr();
	double square();
	int Type();//тип треугольника, 1 - прямоугольный, 2-остроугольный 3-тупоугольный
private:
	double A, B, C;// стороны треугольника
};

void triangle::tri(double a, double b, double c)
{
	A = a;
	B = b;
	C = c;
}
int triangle::Type()
{
	double h, a, b;
	if ((A > B) && (A > C)) { h = A; a = B; b = C; }
	else if ((B >= A) && (B >= C)) { h = B; a = A; b = C; }
	else if ((C > B) && (C > A)) { h = C; a = A; b = B; }
	if (h*h == a * a + b * b) { return 1; }
	if (h*h < a * a + b * b) { return 2; }
	if (h*h > a * a + b * b) { return 3; }

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

	cout << "Enter the lengths of the sides of the triagle \n";
	triangle p;
	double a, b, c;
	cin >> a >> b >> c;
	p.tri(a, b, c);
	bool q = p.exist();
	if (q == 1)
	{
		cout << "Triagle exists \n";
		p.Type();
		cout << "Perimeter of the triangle = " << p.perimetr() << "\n";
		cout << "Area of the the triangle = " << p.square() << "\n";
	}
	else cout << "Such Triangle do not exists \n"; 

	
	return 0;
}
