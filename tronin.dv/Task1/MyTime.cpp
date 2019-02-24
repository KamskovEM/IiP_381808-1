#pragma once
#include "MyTime.h"
#include <iostream>


MyTime::MyTime()
{
	h = m = s = 0;
	ToString();
}


MyTime::MyTime(unsigned char h, unsigned char m, unsigned char s)
{
	this->h = h;
	this->m = m;
	this->s = s;
	ToString();
}

MyTime::MyTime(const MyTime& t)
{
	h = t.h;
	m = t.m;
	s = t.s;
	ToString();
}

MyTime::MyTime(const char* c)
{
	h = Parse(c);
	m = Parse(c + 3);
	s = Parse(c + 6);
	ToString();
}

MyTime::~MyTime()
{
	h = m = s = 0;
}

const char* MyTime::GetString() const 
{	
	return str;
}

void MyTime::ToString()
{
	str[0] = (char)(h / 10 + '0');
	str[1] = (char)(h % 10 + '0');
	str[2] = '.';
	str[3] = (char)(m / 10 + '0');
	str[4] = (char)(m % 10 + '0');
	str[5] = '.';
	str[6] = (char)(s / 10 + '0');
	str[7] = (char)(s % 10 + '0');
	str[8] = '\0';
}

unsigned char MyTime::Parse(const char* str)
{
	unsigned char rez = 0;
	int i = 0;
	while (str[i] != 0 && str[i] != '.')
	{
		rez = rez * 10 + (str[i] - '0');
		i++;
	}
	return rez;
}

MyTime MyTime::operator+(const MyTime& c)
{
	MyTime tmp;
	if (s + c.s > 60)
	{
		tmp.m++;
		tmp.s = (s + c.s) - 60;
	}
	else 
		tmp.s = s + c.s;
	if (m + c.m > 60)
	{
		tmp.h++;
		tmp.m = (m + c.m) - 60;
	}
	else 
		tmp.m = m + c.m;
	if (h + c.h > 24)
	{
		tmp.h = (h + c.h) - 24;
	}
	else
		tmp.h = h + c.h;
	return tmp;	
}


MyTime MyTime::operator-(const MyTime& c)
{
	MyTime tmp;
	bool fs = false,
		fm = false; //indicator "zaema" v razryade
	if (s < c.s)
	{
		fs = true;
		tmp.s = (s - c.s) + 60;
	}
	else
		tmp.s = s - c.s;
	if (m - (fs ? 1 : 0) < c.m)
	{
		fm = true;
		tmp.m = (m - (fs ? 1 : 0) - c.m) + 60;
	}
	else
		tmp.m = m - (fs ? 1 : 0) - c.m;
	if (h - (fm ? 1 : 0) < c.h)
	{
		tmp.h = (h - (fm ? 1 : 0) - c.h) + 24;
	}
	else
		tmp.h = h - (fm ? 1 : 0) - c.h;
	return tmp;
	
}


MyTime& MyTime::operator=(const MyTime& c)
{
	if (this != &c)
	{
		h = c.h;
		m = c.m;
		s = c.s;
		for (int i = 0; i < 9; i++)
		{
			str[i] = c.str[i];
		}
	}
	return *this;
}


bool MyTime::operator>(const MyTime& c) const
{
	if (h < c.h) return false;
	if (m < c.h) return false;
	if (s < c.s) return false;
	return true;	
}

bool MyTime::operator<(const MyTime& c) const
{
	if (h > c.h) return false;
	if (m > c.h) return false;
	if (s > c.s) return false;
	return true;
}

bool MyTime::operator==(const MyTime& c) const
{
	if (h == c.h && m == c.m && s == c.m) return true;
	return false;
}


bool MyTime::operator!=(const MyTime& c) const
{
	if (h != c.h) return true;
	if (m != c.m) return true;
	if (s != c.s) return true;
	return false;
}



std::ostream& operator<<(std::ostream& stream,  const MyTime& c)
{	
	stream << c.GetString();
	return stream;
}
	


std::istream& operator>>(std::istream& stream,  MyTime& c)
{
	char str[9];
	stream.getline(str, 9);
	c = str;
	return stream;
}
	



