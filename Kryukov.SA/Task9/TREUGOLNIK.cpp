// Класс треугольник
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
class Treugolnik {
public:

	double a, b, c, p, S, P, max, id;
	void get()
	{
		cout << "\nВведите сторону а; ";
		cin >> a;
		cout << "\nВведите сторону b; ";
		cin >> b;
		cout << "\nВведите сторону с; ";
		cin >> c;
	}
	void Existence()
	{
		id = 0;
		if (a >= b + c || b >= a + c || c >= a + b)
		{
			cout << "\nТреугольника не существует:";
			id = 1;
		}
		else
			cout << "\nТреугольник существует:";
	}
	void square()
	{
		p = (a + b + c) / 2;
		S = sqrt(p*(p - a)*(p - b)*(p - c));
		cout << "\nПлощадь треугольника=: " << S;
	}
	void perimeter()
	{
		P = a + b + c;
		cout << "\nПериметр треугольника=: " << P;
	}
	void type()
	{
		if (a >= b && a >= c)
			max = a;
		if (b >= a && b >= c)
			max = b;
		if (c >= b && c >= a)
			max = c;

		if (a == max && max < sqrt(b*b + c * c) || b == max && max < sqrt(a*a + c * c) || c == max && max < sqrt(b*b + a * a))
			cout << "\nТреугольник остроугольный ";
		if (a == max && max == sqrt(b*b + c * c) || b == max && max == sqrt(a*a + c * c) || c == max && max == sqrt(b*b + a * a))
			cout << "\nТреугольник прямогольный ";
		if (a == max && max > sqrt(b*b + c * c) || b == max && max > sqrt(a*a + c * c) || c == max && max > sqrt(b*b + a * a))
			cout << "\nТреугольник тупоугольный ";
	}


};


int main()
{
	setlocale(LC_ALL, "ru");
	int V;

	Treugolnik K;
	K.get();

	K.Existence();
	V = K.id;
	if (V != 1)
	{
		K.square();
		K.perimeter();
		K.type();
	}
	getchar();
	getchar();
}
