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
		v1[3] = a;//������ ������� �� �������
	v1.show("v1");
	b = v1[2];
	cout << b << endl;//�������� ������� �� �������
	VECTOR v2(Count, 3);
	v2.show("v2");
	VECTOR v3;
	v3 = v2;//�������� ������������
	v3.show("v3");
	int scalar;
	scalar = v3 * v1;
	cout <<"��������� ������������ "<< scalar<< endl;//��������� ������������
	VECTOR v4;
	v4 = v1 + v2;//����� ��������
	cout << "����� : " <<v4 ;
	v1.Newlong(7);//������ ������
	int SiZe;
	SiZe =v1.razmer();//������ ������
	cout << "razmer=" << SiZe<< endl;
	double len;
	len = v2.lenght();//��������� �����
	cout <<"�����: " << len;
	// ������ � �����
	cout << "\nos << v1 << v2 << endl;-------- " << endl;
	v1.show("v1");
	v2.show("v2");
	ofstream os; // ����� ��� ������
	os.open("vector.txt"); // ���� ��� ������
	os << v1 << v2 << endl;
	os.close();
	// ������ �� ������
	cout << "\nis >> v3 >> v4; --------------------------" << endl;
	ifstream is; // ����� ��� ������
	is.open("vector.txt"); // ���� ��� ������
	is >> v3 >> v4;
	v3.show("v3");
	v4.show("v4");
	is.close();
	}
    catch (VectorExeption)
	{
		cout << "����������: ������� ����� ������" << endl;
	}
	return 0;
}

	



























