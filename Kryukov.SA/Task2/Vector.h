#pragma once
#include <fstream> 
using namespace std;
class VECTOR
{
private: 
	int Size ;//razmer
	int *num; //components
public:
	//constructors
	VECTOR();//po umolchaniu
	///////////inicializators
	explicit VECTOR(int Siz);
	VECTOR(int Siz, int m);

	//COPY
	VECTOR(const VECTOR &Dr);
	
	~VECTOR();//Destructor
			 
			  ///////////////////перегрузка
	VECTOR& operator=(const VECTOR &Dr);
	VECTOR operator+(const VECTOR &Dr);
	int  operator*(const VECTOR &Dr);

	void show(const char* name);//на консоль


	//работа с потоками
	friend ostream& operator<<(ostream& stream, const VECTOR &Dr); // вывод 
	friend istream& operator>>(istream& stream, VECTOR &Dr); // ввод
	//чтение и запись

	int& operator[](int index);       

	void Newlong(int _size);
	void razmer();// (int Size);
	//найти длину
	double lenght( );
	
	//исключения
class Range
{

};

};

ostream& operator<<(ostream& stream, const VECTOR &vec); // вывод в поток
istream& operator>>(istream& stream, VECTOR &vec); // ввод из потока










