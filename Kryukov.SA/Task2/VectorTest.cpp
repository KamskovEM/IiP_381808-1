//  VECTORTestr.cpp/////////////////////////////////////
#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Vector.h" 
//#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int Count = 19;
	try
	{
		VECTOR v1(Count, 2);
		v1.show("v1");
	int a = 10;
		int b;
		v1[3] = a;//задать элемент по индексу
	v1.show("v1");
	b = v1[2];
	cout << b << endl;//получить элемент по индексу
	VECTOR v2(Count, 3);
	v2.show("v2");
	VECTOR v3;
	v3 = v2;//операция присваивания
	v3.show("v3");
	int scalar;
	scalar = v3 * v1;
	cout <<"скалярное произведение "<< scalar<< endl;//скалярное произведение
	VECTOR v4;
	v4 = v1 + v2;//сумма векторов
	cout << "сумма : " <<v4 ;
	v1.Newlong(7);//задаем размер
	int SiZe;
	SiZe =v1.razmer();//узнаем размер
	cout << "razmer=" << SiZe<< endl;
	double len;
	len = v2.lenght();//вычисляем длину
	cout <<"длина: " << len;
	// Запись в поток
	cout << "\nos << v1 << v2 << endl;-------- " << endl;
	v1.show("v1");
	v2.show("v2");
	ofstream os; // поток для записи
	os.open("vector.txt"); // файл для записи
	os << v1 << v2 << endl;
	os.close();
	// Чтение из потока
	cout << "\nis >> v3 >> v4; --------------------------" << endl;
	ifstream is; // поток для чтения
	is.open("vector.txt"); // файл для чтения
	is >> v3 >> v4;
	v3.show("v3");
	v4.show("v4");
	is.close();
	}
    catch (VectorExeption)
	{
		cout << "Исключение: неверно задан размер" << endl;
	}
	return 0;
}

	



























