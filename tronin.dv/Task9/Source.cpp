// TriangleClass.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");

	class Triangle
	{
	public:
		Triangle() //����������� ��-��������� 
		{
			a = b = c = 0;
		}

		//���������� �����������������
		Triangle(double _a, double _b, double _c)
		{
			a = _a;
			b = _b;
			c = _c;
		}

		Triangle(const Triangle& cmp) //����������� ��-��������� 
		{
			a = cmp.a;
			b = cmp.b;
			c = cmp.c;
		}

		Triangle(int _a, int _b, int _c)
		{
			a = (int)_a;
			b = (int)_b;
			c = (int)_c;
		}

		bool Exist()
		{
			if ((c < a + b) && (a < c + b) && (b < a + c)) return true;
			else return false;
		}

		const char* Type()
		{
			if (Exist())
			{
				if ((cos(a, b, c) == 0) || (cos(b, c, a) == 0) || (cos(c, a, b) == 0))
				{
					return "�������������";
				}
				else
				{
					if ((cos(a, b, c) < 0) || (cos(b, c, a) < 0) || (cos(c, a, b) < 0))
					{
						return "������������";
					}
					else
					{
						return "�������������";
					}
				}
			}
			else return "�� ����������";
		}

		double Square()
		{
			double p = (a + b + c) / 2;
			return sqrt(p*(p - a)*(p - b)*(p - c));
		}

	private:
		double a, b, c;

		double cos(double c, double a, double b)
		{
			return (a * a + b * b - c * c) / (2 * a * b);
		}
	};

	double a, b, c;
	cout << "������ ������� ������������: ";
	cin >> a >> b >> c;

	Triangle A, B(a, b, c), C(B);
	cout << "������: " << (B.Exist() ? "���������� " : "�� ���������� ") << B.Type() << " �������: " << B.Square();

}

