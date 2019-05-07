#pragma once
#include <iostream>

using namespace std;
class Vector3D
{
public:
	Vector3D(void); //Konstructor po umolchaniyu
	Vector3D(const Vector3D&); //Konstructor kopirovaniya
	Vector3D(double _x, double _y, double _z); //Kostructor initsializatsii
	~Vector3D(); //Destructor
	Vector3D& operator= (const Vector3D& v);//peregruzka operatora prisvaivaniya
	Vector3D operator+(const Vector3D& v);//peregruzka operatora slojeniya
	Vector3D operator-(const Vector3D& v);//peregruzka operatora vichitaniya
	double operator*(const Vector3D& v);//peregruzka operatora skalarnogo proizvedeniya
	friend Vector3D operator*(double l, const Vector3D& v);//peregruzka operatora  umnojeniya na skalar
	bool operator==(const Vector3D& v);//peregruzka operatora sravneniya
	bool operator!=(const Vector3D& v);//peregruzka operatora sravneniya
	bool operator>(const Vector3D& v);//peregruzka operatora sravneniya
	bool operator<(const Vector3D& v);//peregruzka operatora sravneniya
	friend ostream& operator<<(ostream& stream, const Vector3D& v);////peregruzka operatora vivoda
	friend istream& operator>>(istream& stream, Vector3D& v);//peregruzka operatora vvoda

private:
	double x, y, z; //Koordinati vectora
	double lenght; // Dlina vectora
};
Vector3D operator*(double l, const Vector3D& v);
ostream& operator<<(ostream& stream, const Vector3D& v);
istream& operator>>(istream& stream, Vector3D& v);