#include "Vector3D.h"
#include <math.h>
#include <iostream>

Vector3D::Vector3D() 
{
	x = y = z = lenght = 0;
}


Vector3D::Vector3D(const Vector3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	lenght = v.lenght;
}

Vector3D::Vector3D(double _x, double _y, double _z) 
{
	x = _x;
	y = _y;
	z = _z;
	lenght = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3D::~Vector3D()
{
	x = y = z = lenght = 0;
}

Vector3D& Vector3D::operator=(const Vector3D& v) 
{
	(*this).x = v.x;
	(*this).y = v.y;
	(*this).z = v.z;
	(*this).lenght = v.lenght;
	return (*this);
}

Vector3D Vector3D::operator+(const Vector3D& v)
{
	Vector3D res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	res.lenght = sqrt(pow(res.x, 2) + pow(res.y, 2) + pow(res.z, 2));
	return res;
}

Vector3D Vector3D::operator-(const Vector3D& v)
{
	Vector3D res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	res.lenght = sqrt(pow(res.x, 2) + pow(res.y, 2) + pow(res.z, 2));
	return res;
}
double Vector3D::operator*(const Vector3D& v)
{
	double scalar;
	scalar = (*this).x*v.x + (*this).y*v.y + (*this).z*v.z;
	return scalar;
}

Vector3D operator*(double l, const Vector3D& v)
{
	Vector3D res;
	res.x = l * v.x;
	res.y = l * v.y;
	res.z = l * v.z;
	res.lenght = sqrt(pow(res.x, 2) + pow(res.y, 2) + pow(res.z, 2));
	return res;
}

bool Vector3D::operator==(const Vector3D& v)
{
	if ((*this).lenght == v.lenght)
		return true;
	else
		return false;
}

bool Vector3D::operator!=(const Vector3D& v)
{
	if ((*this).lenght != v.lenght)
		return true;
	else
		return false;
}

bool Vector3D::operator> (const Vector3D& v)
{
	if ((*this).lenght > v.lenght)
		return true;
	else
		return false;
}

bool Vector3D::operator< (const Vector3D& v)
{
	if ((*this).lenght < v.lenght)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& stream, const Vector3D& v) {

	stream << " X = " << v.x << " Y = " << v.y << " Z = "<< v.z << "\n Длина вектора = " << v.lenght << endl;

	return stream;

}

istream& operator>>(istream& stream, Vector3D& v) {

	stream >> v.x >> v.y >> v.z >> v.lenght;

	return stream;

}