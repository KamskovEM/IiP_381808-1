// ����� �����������
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
class Treugolnik {
private:
	double a, b, c;
public:
	void get();
	void Existence();
	void square();
	void perimeter();
	void type();
};
void Treugolnik::get()
{
	cout << "\n������� ������� a ";
	cin >> a;
	cout << "\n������� ������� b ";
	cin >> b;
	cout << "\n������� ������� � ";
	cin >> c;
}
void Treugolnik::Existence()
{

	if (a >= b + c || b >= a + c || c >= a + b)
	{
		cout << "\n������������ �� ����������:";

	}
	else
		cout << "\n����������� ����������:";
}
void  Treugolnik::square()
{
	double S;
	double p;
	if (a < b + c && b < a + c && c < a + b)
	{
		p = (a + b + c) / 2;
		S = sqrt(p*(p - a)*(p - b)*(p - c));
		cout << "\n������� ������������=: " << S;
	}
}
void Treugolnik::perimeter()
{
	double P;
	if (a < b + c && b < a + c && c < a + b)
	{
		P = a + b + c;
		cout << "\n�������� ������������=: " << P;
	}
}
void Treugolnik::type()
{
	double max;
	if (a < b + c && b < a + c && c < a + b)
	{
		if (a >= b && a >= c)
			max = a;
		if (b >= a && b >= c)
			max = b;
		if (c >= b && c >= a)
			max = c;

		if (a == max && max < sqrt(b*b + c * c) || b == max && max < sqrt(a*a + c * c) || c == max && max < sqrt(b*b + a * a))
			cout << "\n����������� ������������� ";
		if (a == max && max == sqrt(b*b + c * c) || b == max && max == sqrt(a*a + c * c) || c == max && max == sqrt(b*b + a * a))
			cout << "\n����������� ������������ ";
		if (a == max && max > sqrt(b*b + c * c) || b == max && max > sqrt(a*a + c * c) || c == max && max > sqrt(b*b + a * a))
			cout << "\n����������� ������������ ";
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	Treugolnik K;
	K.get();
	K.Existence();
	K.square();
	K.perimeter();
	K.type();
	getchar();
	getchar();
}
