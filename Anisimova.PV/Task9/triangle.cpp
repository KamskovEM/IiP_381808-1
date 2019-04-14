#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;
class triangle {
public:
	void tri(double a, double b, double c);
	double perimetr();
	double square();
	void type();
private:
	double A, B, C;
};

void triangle::tri(double a, double b, double c)
{
	A = a; B = b; C = c;
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
void triangle::type()
{
	if (A*A == B * B + C * C || B * B == A * A + C * C || C * C == B * B + A * A)
		cout << "������������� ";
	else
		if (A*A > B*B + C * C || B * B > A*A + C * C || C * C > B*B + A * A)
			cout << "������������";
		else
			cout << "�������������";
}
int main()
{
	system("chcp 1251>nul");
	cout << "������� ����� ������ ������������  \n";
	triangle p;
	double a, b, c;
	cin >> a >> b >> c;
	p.tri(a, b, c);
	if ((a + b > c) && (a + c > b) && (b + c > a))
	{
		cout << "����������� ���������� \n";
		cout << "�������� ������������ = " << p.perimetr() << "\n";
		cout << "�������  ������������ = " << p.square() << "\n";
		cout << "��� ������������  ";
		p.type();
		cout << "\n";
	}
	else  		cout << "������ ������������ �� ���������� \n";
	getchar();
	return 0;
}