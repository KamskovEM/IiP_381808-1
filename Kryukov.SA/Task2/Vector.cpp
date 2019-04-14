#include <iostream>
#include <cmath>
#include <algorithm>
#include "Vector.h"
#include <fstream>
#include <clocale>
//opisanie/////////////////////////////////////////////////////////////////////////////////////
using namespace std;
const int  maxSIZE = 20;
VECTOR::VECTOR()//po umolchaniu
{
	Size = 0;
	num = NULL;
}
VECTOR::~VECTOR()//Destructor
{
	if (num != NULL){
		delete[] num;
		num = NULL;
		Size = 0;
		}
}
//INICIALIZATORs
VECTOR::VECTOR(int Siz) : Size(Siz)
{
	if (Size<maxSIZE)
	num = new int[Size];
	else
		throw VectorExeption();
}
VECTOR::VECTOR(int Siz, int m)
{
	if (Siz < maxSIZE)
		Size = Siz;
	num = new int[Size];
	for (int i = 0; i < Size; i++)
		num[i] = m;
}
//COPY
VECTOR::VECTOR(const VECTOR &Dr)
{
	
	Size = Dr.Size;
	num = new int[Size];
	for (int i = 0; i < Size; i++)
		num[i] = Dr.num[i];
}
//����������
VECTOR& VECTOR:: operator=(const VECTOR &Dr)
{
	if (this != &Dr)
	{
		if (Size != Dr.Size)
		{
			delete[] num;
			Size = Dr.Size;
			num = new int [Size];
		}
		for (int i = 0; i < Size;i++)
			num[i] = Dr.num[i];
	}
	return *this;
}
VECTOR VECTOR::operator+(const VECTOR &Dr) 
{
	if (Size != Dr.Size)
		abort(); 
	VECTOR rez(Size);//�������������
	for (int i = 0; i <Size ; i++)
		rez.num[i] = num[i] + Dr.num[i];
	return rez;
}
int  VECTOR::operator*(const VECTOR &Dr)
{int rez = 0;
	if (Size = Dr.Size)
	{
		
		for (int i = 0; i < Size; i++)
			rez += num[i] * Dr.num[i];
	}
	else
		throw VectorExeption();
	return rez;
}
//�������� �� �������
void VECTOR::show(const char* name)
{
	cout << name << ": ";
	for (int i = 0; i < Size; i++)
		cout << num[i] << "\t";//���������
	cout << endl;
}

// ����� � �����
ostream& operator<<(ostream& stream, const VECTOR &Dr)
{
	stream << Dr.Size << " ";
	for (int i = 0; i < Dr.Size; i++)
		stream << Dr.num[i] << " ";
	stream << endl;
	return stream;
}

//������ ������ ������� 
void VECTOR::Newlong(int _size)
{
	if (_size <= maxSIZE)
		Size = _size;
}
//������ ������ �������
int VECTOR::razmer()
{
	return Size;
}
//������ � ��������� ���������� �� ������ 
int& VECTOR::operator[](int index)
{
	if (index < 0 || index > 20 )
		throw VectorExeption();
		return num[index];
}
//��������� ������ �������
double VECTOR::lenght()
{
int sum = 0;	
for (int i = 0; i < Size; i++)
		sum += num[i] * num[i];
	return sqrt(sum);
}



















