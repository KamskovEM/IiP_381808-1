#include <iostream>
#include <fstream>
#include <clocale>
#include <vector>
#include <string>
#include <algorithm>
#include "Decimal.h"

using namespace std;

Decimal::Decimal()
{

}

Decimal::~Decimal()
{
	num.shrink_to_fit();
}

Decimal & Decimal::operator=(const Decimal& d)
{
	num.resize(d.num.size());
	for (int i = 0; i < num.size(); i++) {
		num[i] = d.num[i];
	}
	return (*this);
}

Decimal & Decimal::operator=(const unsigned long long n)
{
	int i = 0;
	long long nm = n;
	num.resize(0);
	while (nm > 0 || i == 0) {
		num.push_back((char)(nm % 10));
		nm /= 10;
		i++;
	}
	return *this;
}

Decimal Decimal::operator+(const Decimal& d)
{
	int ost = 0, i;
	Decimal res1;
	Decimal res2;
	if (d.num.size() > (*this).num.size()) {
		res1 = d;
		res2 = (*this);
	}
	else {
		res2 = d;
		res1 = (*this);
	}
	for (i = 0; i < res2.num.size(); i++) {
		if (ost) {
			if (res1.num[i] + res2.num[i] + 1 >= 10) {
				res1.num[i] = (res1.num[i] + res2.num[i] + 1) % 10;
			}
			else {
				res1.num[i] = (res1.num[i] + res2.num[i] + 1);
				ost = 0;
			}
		}
		else {
			if (res1.num[i] + res2.num[i] >= 10) {
				res1.num[i] = (res1.num[i] + res2.num[i]) % 10;
				ost = 1;
			}
			else {
				res1.num[i] = (res1.num[i] + res2.num[i]);
				ost = 0;
			}
		}
	}
	while (i < res1.num.size()) {
		if (ost) {
			if (1 + res1.num[i] > 9) {
				res1.num[i] = 0;
			}
			else {
				res1.num[i]++;
				ost = 0;
			}
		}
		i++;
	}
	if (ost) {
		res1.num.push_back(1);
	}
	return res1;
}

Decimal Decimal::operator+(const unsigned long long n)
{
	Decimal d;
	int m = n;
	while (m > 0) {
		d.num.push_back(m % 10);
		m /= 10;
	}
	return (*this) + d;
}

Decimal Decimal::operator-(const Decimal& d)
{
	int ost = 0, i;
	Decimal res1;
	Decimal res2;
	res1 = (*this);
	res2 = d;
	if (res2 >= res1) {
		res1 = 0;
		return res1;
	}
	for (i = 0; i < res2.num.size(); i++) {
		if (ost) {
			if (res1.num[i] < res2.num[i] + 1) {
				res1.num[i] = (10 + res1.num[i] - res2.num[i] - 1);
			}
			else {
				res1.num[i] = res1.num[i] - res2.num[i] - 1;
				ost = 0;
			}
		}
		else {
			if (res1.num[i] < res2.num[i]) {
				res1.num[i] = (10 + res1.num[i] - res2.num[i]);
				ost = 1;
			}
			else {
				res1.num[i] = res1.num[i] - res2.num[i];
			}
		}
	}
	while (i < res1.num.size()) {
		if (ost) {
			if (res1.num[i] < 1) {
				res1.num[i] = 9;
			}
			else {
				res1.num[i]--;
				ost = 0;
			}
		}
		i++;
	}
	while (res1.num[--i] == 0) {
		res1.num.pop_back();
	}
	return res1;
}

bool Decimal::operator>(const Decimal& d) {
	if (num.size() > d.num.size()) {
		return true;
	}
	else if (num.size() < d.num.size()) {
		return false;
	}
	else {
		int i = num.size() - 1;
		while (i > -1) {
			if (num[i] > d.num[i]) {
				return true;
			}
			else if (num[i] < d.num[i]) {
				return false;
			}
			i--;
		}
	}
	return false;
}

bool Decimal::operator<(const Decimal& d) {
	if (num.size() < d.num.size()) {
		return true;
	}
	else if (num.size() > d.num.size()) {
		return false;
	}
	else {
		int i = num.size() - 1;
		while (i >= 0) {
			if (num[i] < d.num[i]) {
				return true;
			}
			else if (num[i] > d.num[i]) {
				return false;
			}
			i -= 1;
		}
		return false;
	}
}

bool Decimal::operator>=(const Decimal& d) {
	if (num.size() > d.num.size()) {
		return true;
	}
	else if (num.size() < d.num.size()) {
		return false;
	}
	else {
		int i = num.size() - 1;
		while (i >= 0) {
			if (num[i] > d.num[i]) {
				return true;
			}
			else if (num[i] < d.num[i]) {
				return false;
			}
			i -= 1;
		}
	}
	return true;
}

bool Decimal::operator<=(const Decimal& d) {
	if (num.size() < d.num.size()) {
		return true;
	}
	else if (num.size() > d.num.size()) {
		return false;
	}
	else {
		int i = num.size() - 1;
		while (i >= 0) {
			if (num[i] < d.num[i]) {
				return true;
			}
			else if (num[i] > d.num[i]) {
				return false;
			}
		    i -= 1;
		}
	}
	return true;
}

bool Decimal::operator==(const Decimal& d) {
	if (num.size() == d.num.size()) {
		int i = num.size() - 1;
		while (i >= 0) {
			if (num[i] != d.num[i]) {
				return false;
			}
			i -= 1;
		}
	}
	else {
		return false;
	}
	return true;
}

bool Decimal::operator!=(const Decimal& d) {
	if (num.size() == d.num.size()) {
		int i = num.size() - 1;
		while (i >= 0) {
			if (num[i] != d.num[i]) {
				return true;
			}
			i -= 1;
		}
	}
	else {
		return true;
	}
	return false;
}

istream & operator>>(istream & stream, Decimal & d)
{
	string str;
	stream >> str;
	d.num.resize(str.size());
	for (int i = 0; i < str.size(); i++) {
		d.num[i] = str[str.size() - i - 1] - '0';
	}
	return stream;
}

ostream & operator<<(ostream & stream, Decimal & d)
{
	for (int i = d.num.size() - 1; i >= 0; i--) {
		stream << (int)d.num[i];
	}
	return stream;
}
