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
///////////////////����������
VECTOR& operator=(const VECTOR &Dr);
VECTOR operator+(const VECTOR &Dr);
int  operator*(const VECTOR &Dr);
void show(const char* name);//�� �������
//������ � ��������
friend ostream& operator<<(ostream& stream, const VECTOR &Dr); // ����� 
friend istream& operator>>(istream& stream, VECTOR &Dr); // ����
//������ � ������
int& operator[](int index);       
void Newlong(int _size);
int razmer();
//����� �����
double lenght( );
	//defoult
//class Range
//{};
};
ostream& operator<<(ostream& stream, const VECTOR &vec); // ����� � �����
istream& operator>>(istream& stream, VECTOR &vec); // ���� �� ������
enum Exeptions
{
};
// iscluchenie ----------------------------
struct VectorExeption
{
	VectorExeption()
	{}
};









