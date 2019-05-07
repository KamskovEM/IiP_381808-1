#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

class Menu
{
private:
	unsigned int count; //���������� ������� ���� 
	string *arr; //������ �������� �������
	unsigned int current; //��������� �����
	COORD currentPosition; //������� ������������� ����

public:
	Menu(); //����������� �� ���������
	Menu(int); //����������� �������������
	Menu(const Menu&); //����������� �����������
	Menu(istream&); //����������� ������ ���� �� �����

	~Menu();

	int GetCount() const  { return count; } //������� ���������� ��������� 
	int GetLast() const { return current; } //������� ���������� ���������� ��������
	void SetItem(int n, const string&); //������� �������� ������
	void Show(int x = -1, int y = -1); //����� ���� �� �����
	int Input(); //����� ������ ���� �����-�� �������
	

	friend std::ostream& operator<<(std::ostream& stream, const Menu&);
	friend std::istream& operator>>(std::istream& stream, Menu&);
};

enum Exeption {OutOfRange, InvalidStream};

