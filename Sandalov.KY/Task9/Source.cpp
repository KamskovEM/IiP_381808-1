#include "Triangle.h"
#include "locale"

int main() {
	setlocale(LC_ALL, "Russian");
	Triangle first(3, 4, 5);
	string a = "Yes", b = "No";
	string c;
	cout << "�������� �� �������� ������� ������������ �� ������ (������� 3, 4, 5)?\n������� 'Yes' ��� 'No'\n";
	cin >> c;
	double da, db, dc;
	if (c == "Yes")
	{
		cout << "������� ����� ����� ������:\n";
		cin >> da >> db >> dc;
		first.resize(da, db, dc);
	}
	if (first.true_triangle())
	{
		first.type_of_triangle();
		cout << "�������� ������������ = " << first.perimetr() << " � ��� ������� = " << first.ploshad();
	}


	return 0;
}