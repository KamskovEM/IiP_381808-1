#include <iostream>
#include <string>
#include <fstream>

#include "Menu.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream is;
	is.open("test.txt");


	Menu menu(is);
	menu.Show(0,0);
	int i = menu.Input();
	cout << "�� ������� ����� ����:" << i << endl;
	cout << menu.GetCount() << endl;
	cout << menu.GetLast() << endl;
	while (true) //���� ������������� �������� ������� ����
	{
		cout << "����� ����� ���� �� �� ������ ������? ������� '-1', ����� �����" << endl;
		int c;
		cin >> c;
		if (c == -1) break;
		cout << "��� �� �� ������ ������� ��������� ����� ����?" << endl;
		string tmp;
		cin >> tmp;
		menu.SetItem(c, tmp);
	}
	menu.Show();
	menu.Input();
	try // �������� ����������
	{
		menu.SetItem(4, "����� 4");
	}
	catch (Exeption i)
	{
		if (i == OutOfRange) cout << "\n�� ����� �� ������� ����" << endl;
	}
}