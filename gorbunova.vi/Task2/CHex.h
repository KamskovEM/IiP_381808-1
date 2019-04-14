#pragma once
#include <iostream>

class Hex
{
	unsigned char *pmem; 
	int size; 

	int hex2int(unsigned char c) const;
	unsigned char int2hex(int i) const;
public:
	Hex(int _size); // ����������� �������������
	Hex(const Hex &obj); // ����������� �����������
	~Hex(); // �����������
	Hex& operator=(const Hex &obj); // �������� ������������

	Hex operator+(const Hex &obj); // �������� "���������"
	Hex operator-(const Hex &obj); // ��������� "���������"

	bool operator==(const Hex &obj); // �������������� ���������
	bool operator!=(const Hex &obj); // ��������� ��������� ==
	bool operator>=(const Hex &obj); // �������������� ���������
	bool operator<=(const Hex &obj); // �������������� ���������
	bool operator>(const Hex &obj); // ��������� ��������� <=
	bool operator<(const Hex &obj); // ��������� ��������� >=

	friend std::ostream& operator<<(std::ostream &stream, const Hex &obj); 
	friend std::istream& operator>>(std::istream &stream, Hex &obj);
};

