#include "Money.h"
#include<cmath>
#include<iostream>
Money::Money() {
	c = 0;
	r = 0;
	z = '+';

}
Money::Money(char a, int b,int  d) {
	z = a;
	r = b;
    c = d;
}
Money::Money(const Money & _a) {
	c = _a.c;
	r = _a.r;
	z = _a.z;
}
Money::~Money() {
	c = 0;
	r = 0;
	z = '+';
	
}
Money& Money::operator=(const Money& m) {
	r = m.r;
	c = m.c;
	z = m.z;
	return *this;
}
bool Money::operator==(const Money& m) {
	if (r == m.r&&c == m.c&&z == m.z)
		return 1;
	else return 0;

}
ostream& operator<<(ostream& stream, const Money& m) {
	stream << m.z << m.r <<','   << m.c << endl;
	return stream;

}
istream& operator>>(istream& stream,Money& m) {
	char k;
	stream  >>m.z >> m.r >>k >> m.c ;
	return stream;

}
Money Money::operator+(const Money& m) {
	Money res;
	if (((z == '+') && (m.z == '+')) || ((z == '-') && (m.z == '-')))  //esli obe summi >0
		return sum(res, m);
	

	if ((z == '+') && (m.z == '-'))  
		return min(res, m);
	
	 if ((z == '-') && (m.z == '+'))
	return min(res,m);
}
Money Money::operator-(const Money& m) {
	Money res;
	if (((z == '+') && (m.z == '+')) || ((z == '-') && (m.z == '+')))  //esli obe summi >0
		return min(res, m);


	if ((z == '+') && (m.z == '-'))
		return sum(res, m);

	if ((z == '-') && (m.z == '-'))
		return min(res, m);
}	
Money operator*(const Money& m, double d) {
		 Money res;
		 if (((m.z == '+') && (d >= 0)) || ((m.z == '-') && (d < 0)))
			 res.z = '+';
		 if ((m.z == '-') && (d >= 0))
			 res.z = '-';
		 if ((d < 0) && (m.z == '+'))
			 res.z = '-';
		 double tmp1,tmp2;
		 tmp1 = m.c;
		 tmp2 = m.r;
		  tmp1 *= abs(d);
		  tmp2 *=abs(d);
		  res.r = (int)tmp2;
		  res.c = (((int)(100 * tmp2)) % 100);
		  res.c += (int)tmp1;
		  if (res.c >= 100);
		  res.r += (int)res.c / 100;
		  res.c = res.c % 100;
		 return res;
}
Money operator/(const Money& m, double d) {
	Money res;
	if (((m.z == '+') && (d >= 0)) || ((m.z == '-') && (d < 0))) 
		res.z = '+';
	if ((m.z == '-') && (d >= 0))  
		res.z = '-';
	if ((d < 0) && (m.z == '+'))
		res.z = '-';
	double tmp1, tmp2;
	tmp1 = m.c;
	tmp2 = m.r;
	tmp1 /= abs(d);
	tmp2 /= abs(d);
	res.r = (int)tmp2;
	res.c = (((int)(100 * tmp2)) % 100);
	res.c += (int)tmp1;
	if (res.c >= 100);
	res.r += (int)res.c / 100;
	res.c = res.c % 100;
	return res;
}
Money Money::sum(Money& res, const Money& m) {
	res.c += c + m.c;
	res.r = m.r + r;
	if (res.c >= 100) {
		res.r += 1;
		res.c -= 100;
	}
	res.z = z;
	return res;
}
Money Money::min(Money& res, const Money& m) {
	if ((r > m.r) || (r == m.r&&c > m.c)) {
		res.r = r - m.r;
		res.c = c - m.c;
		res.z = z;
	}
	else {
		res.r = m.r - r;
		res.c = m.c - c;
		res.z = m.z;
	}
	if (res.c <= 0) {
		if (res.r == 0) {
			res.c = abs(c);
			res.z = '-';
		}
		else {
			res.r -= 1;
			res.c = 100 - abs(res.c);

		}
	}
	res.c = abs(res.c);
	res.r = abs(res.r);

	return res;
}