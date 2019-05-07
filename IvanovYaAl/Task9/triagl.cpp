#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>

using namespace std;

class Triple {
public:
	double x, y, z;
	void think(double x, double y, double z);

};

void Triple::think(double x, double y, double z)
	{
		if ((x + y < z) | (x + z < y) | (z + y < x)) {
			cout << "����������� �� ����������\n";
		}
		else {

			cout << "����������� ����������\n";
			if ((x == y) | (x == z) | (y == z) && !(x == z && x == y && z == y)) {
				cout << "����������� ��������������\n";
			}
			if (x == z && x == y && z == y) {
				cout << "����������� ��������������\n";
			}
			if (x*x + y * y == z * z | x * x + z * z == y * y | z * z + y * y == x * x) {
				cout << "����������� �������������\n";
			}

			cout << "�������� ������������ �����: " << x + z + y << endl;
			double p = (x + y + z) / 2;
			cout << "������� ������������ �����: " << sqrt(p*(p - x)*(p - y)*(p - z)) << endl;
		}
	}


int main() {
	system("chcp 1251>nul");
	double a, b, c;
	cout << "������� ������� ������������:\n";
	cin >> a; cin >> b; cin >> c;
	Triple obj;
	obj.think(a, b, c);
	system("pause>nul");
	return 0;
}