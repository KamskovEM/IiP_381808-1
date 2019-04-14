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
	cout << "������� ����� ������: \n";
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
		cout << "�������������� �����������";
	if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
		cout << "�������������� �����������";
	if ((pow(a, 2) + pow(b, 2) == pow(c, 2)) || (pow(c, 2) + pow(b, 2) == pow(a, 2)) || (pow(a, 2) + pow(c, 2) == pow(b, 2)))
		cout << "������������� �����������";
	else
		cout << "������������� ��� ������������ �����������";
}
Triangle :: ~Triangle() {};
int main()
{
	setlocale(LC_CTYPE, "Russian");

	Triangle t1;
	cout << "��� ������������:   ";
	t1.kind(); cout << "\n";
	cout << "�������� ����������� �����:   ";
	cout << t1.perimeter();
	cout << "\n" << "������� ������������ �����:   ";
	cout << t1.area();
	getchar();
	getchar();
}