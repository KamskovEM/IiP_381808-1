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
//Перегрузка
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
	VECTOR rez(Size);//инициализатор
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
//показать на консоли
void VECTOR::show(const char* name)
{
	cout << name << ": ";
	for (int i = 0; i < Size; i++)
		cout << num[i] << "\t";//табуляция
	cout << endl;
}

// вывод в поток
ostream& operator<<(ostream& stream, const VECTOR &Dr)
{
	stream << Dr.Size << " ";
	for (int i = 0; i < Dr.Size; i++)
		stream << Dr.num[i] << " ";
	stream << endl;
	return stream;
}
// ввод из потока
istream& operator>>(istream& stream, VECTOR &Dr)
{
	int str;
	stream >> str;
	if (Dr.Size != str)
	{
		if (Dr.num != NULL)
			delete[] Dr.num;
		Dr.Size = str;
		Dr.num = new int [str];
	}
	for (int i = 0; i <Dr.Size; i++)
		stream >> Dr.num[i];
	return stream;
}

//задать размер вектора 
void VECTOR::Newlong(int _size)
{
	if (_size <= maxSIZE)
		Size = _size;
}
//узнать размер вектора
int VECTOR::razmer()
{
	return Size;
}
//задать и вычислить компоненту по номеру 
int& VECTOR::operator[](int index)
{
	if (index < 0 || index > 20 )
		throw VectorExeption();
		return num[index];
}
//вычислить длинну вектора
double VECTOR::lenght()
{
int sum = 0;	
for (int i = 0; i < Size; i++)
		sum += num[i] * num[i];
	return sqrt(sum);
}



















