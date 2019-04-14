#include "MyOctal.h"

#include <iostream>
#include <algorithm>
using namespace std;

MyOctal::MyOctal()//konstruktor po umolchaniu
{
	length = 0;
	num = NULL;
}

MyOctal::MyOctal(int length)//constructor initilizacii
{
	if (length > maxLength) length = maxLength;
	this->length = length;
	num = new unsigned char[length];
	for (int i = 0; i < length; i++)
		num[i] = 0;
}

MyOctal::MyOctal(const MyOctal & myOctal)//konstrucktor copirovania
{
	length = myOctal.length;
	num = new unsigned char[length];
	for (int i = 0; i < length; i++)
		num[i] = myOctal.num[i];
}


MyOctal::~MyOctal()//destructor
{
	length = 0;
	delete[] num;
}



MyOctal & MyOctal::operator=(const MyOctal & c)//Peregruzka =
{
	if (length < c.length)
	{
		delete[] num;
		num = new unsigned char[c.length];
	}
	length = c.length;
	for (int i = 0; i < length; i++) num[i] = c.num[i];
	return *this;
}
MyOctal MyOctal::operator + (const MyOctal & c)//Peregruzka +
{
	int maxL = length;
	if (maxL < c.length) maxL = c.length;
	if (maxL < maxLength)maxL++;
	MyOctal res(maxL);

	int out = 0;
	for (int i = 0; i < maxL; i++)
	{
		int a = i < length ? (num[i] - '0') : 0;
		int b = i < c.length ? (c.num[i] - '0') : 0;

		
		int sum = a + b + out;
		out = sum / 8;
		
		sum %= 8;
		res.num[i] = (char)(sum + '0');
	}
	while (res.length>1 && res.num[res.length - 1] == '0')res.length--;

	return res;
}
MyOctal MyOctal::operator - (const MyOctal & c)//Peregruzka -
{


	int maxL = max(length, c.length);
	MyOctal res(maxL);
	int d = 0;
	for (int i = 0; i < maxL; i++)
	{
		int q = (i < length) ? (num[i] - '0') : 0;
		int w = (i < c.length) ? (c.num[i] - '0') : 0;
		//cout << q << " + " << w << endl;
		if (q + d < w)
		{
			res.num[i] = (8 + q + d - w) + '0';
			d = -1;
		}
		else
		{
			res.num[i] = (q + d - w) + '0';
			d = 0;
		}

	}
	if (d==-1)//esli pereshli porog v minus
	{
		MyOctal r = GetMax();
		for (int i = 0; i < res.length; i++)
			r.num[i] = ('7' - res.num[i])+'0';
		return r + res;
	}
	while (res.length > 1 && res.num[res.length - 1] == '0')res.length--;
	return res;
}
bool MyOctal::operator==(const MyOctal & c)//Peregruzka ==
{
	if (length != c.length)return false;
	for (int i = 0; i < length; i++)
		if (num[i] != c.num[i]) return false;
	return true;
}

ostream & operator << (ostream & stream, const MyOctal & c)//Vivod v potok
{
	stream << c.length << " ";
	for (int i = c.length-1; i >=0; i--)
		stream << c.num[i];
	stream << " ";
	return stream;
}

istream & operator>>(istream & stream, MyOctal & c)//Vvod v potok
{
	int length;
	stream >> length;
	if (length > c.maxLength)length = c.maxLength;
	if (c.length < length)
	{
		delete[] c.num;
		c.num = new unsigned char[length];
	}
	c.length = length;
	for (int i = 0; i < c.length; i++)
		stream >> c.num[i];
	
	
	c.turnOver();
	
	return stream;
}

void MyOctal::turnOver()//perevorot chisla zadom napered
{
	for (int i = 0; i < length / 2; i++)
		swap(num[i], num[length - 1 - i]);
}

MyOctal MyOctal::GetMax()//vozvrat max
{
	MyOctal res(maxLength);
	for (int i = 0; i < maxLength; i++)
		res.num[i] = 7 + '0';
	return res;
}
