#include "CHex.h"
#include <iostream>

int Hex::hex2int(unsigned char c) const
{
	switch (c)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case 'A': return 10;
	case 'B': return 11;
	case 'C': return 12;
	case 'D': return 13;
	case 'E': return 14;
	case 'F': return 15;
	default:
		break;
	}
	return -1;
}

unsigned char Hex::int2hex(int i) const
{
	switch (i)
	{
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	default:
		break;
	}
	return '-';
}

Hex::Hex(int _size) : size(_size + 1) 
{ 
	pmem = new unsigned char[size]; 
	pmem[0] = '\0'; 
}

Hex::Hex(const Hex &obj) 
{
	size = obj.size; 
	pmem = new unsigned char[size]; 
	for (int i = 0; i < size; i++) 
	{
		pmem[i] = obj.pmem[i];
	}
}
Hex::~Hex() 
{
	size = 0; 
	delete[]pmem; 
	pmem = NULL; 
}

Hex& Hex::operator=(const Hex &obj) 
{
	if (this == &obj) return *this; 
	if (size != obj.size) 
	{
		delete[]pmem;
		size = obj.size;
		pmem = new unsigned char[size];
	}
	for (int i = 0; i < size; i++)
	{
		pmem[i] = obj.pmem[i];
	}
	return *this;
} 

Hex Hex::operator+(const Hex &obj)
{
	int max_size_result = 0; 
	if (size >= obj.size) max_size_result = size + 1;
	else max_size_result = obj.size + 1;
	char* result = new char[max_size_result]; 
	int i = 0, last = 0;
	while ((pmem[i] != '\0') && (obj.pmem[i] != '\0')) 
	{
		int sum = 0;
		sum = hex2int(pmem[i]) + hex2int(obj.pmem[i]) + last;
		if (sum >= 16)
		{
			sum -= 16;
			last = 1;
		}
		else
		{
			last = 0;
		}
		result[i] = int2hex(sum);
		i++;
	}
	int valid = i; 
	if (pmem[valid] != '\0') 
	{
		int sum = 0;
		sum = hex2int(pmem[i]) + last;
		if (sum >= 16)
		{
			sum -= 16;
			last = 1;
		}
		else
		{
			last = 0;
		}
		result[i] = int2hex(sum);
		i++;
		while (pmem[i] != '\0') { result[i] = pmem[i]; i++; }
	}
	if (obj.pmem[valid] != '\0') 
	{
		int sum = 0;
		sum = hex2int(obj.pmem[i]) + last;
		if (sum >= 16)
		{
			sum -= 16;
			last = 1;
		}
		else
		{
			last = 0;
		}
		result[i] = int2hex(sum);
		i++;
		while (obj.pmem[i] != '\0') { result[i] = obj.pmem[i]; i++; }
	}
	if (last != 0) 
	{
		result[i] = int2hex(last);
		i++;
	}
	result[i] = '\0'; 
	int size_result = 0; 
	while (result[size_result] != '\0') size_result++;
	Hex r(size_result); 
	for (i = 0; i < r.size; i++)
	{
		r.pmem[i] = result[i];
	}
	delete[]result; 
	return r;
}

Hex Hex::operator-(const Hex &obj) 
{
	int max_size_result = 0;
	if (size >= obj.size) max_size_result = size;
	else max_size_result = obj.size;
	char* result = new char[max_size_result];
	int i = 0, last = 0;
	while ((pmem[i] != '\0') && (obj.pmem[i] != '\0'))
	{
		int sub = 0;
		sub = hex2int(pmem[i]) - hex2int(obj.pmem[i]) - last;
		if (sub < 0)
		{
			sub += 16;
			last = 1;
		}
		else
		{
			last = 0;
		}
		result[i] = int2hex(sub);
		i++;
	}
	int valid = i;
	if (pmem[valid] != '\0') 
	{ 
		int sub = 0;
		sub = hex2int(pmem[i]) - last;
		if (sub < 0)
		{
			sub += 16;
			last = 1;
		}
		else
		{
			last = 0;
		}
		result[i] = int2hex(sub);
		i++;
		while (pmem[i] != '\0') { result[i] = pmem[i]; i++; }
	}
	result[i] = '\0';
	int size_result = 0;
	bool f = true; 
	while (result[size_result] != '\0')
	{
		size_result++;
		if (result[size_result] != '0') f = false;
	}
	if (f) 
	{
		Hex r(1);
		r.pmem[0] = '0';
		r.pmem[1] = '\0';
		delete[]result;
		return r;
	}
	else 
	{
		Hex r(size_result);
		for (i = 0; i < r.size; i++)
		{
			r.pmem[i] = result[i];
		}
		delete[]result;
		return r;
	}
}

bool Hex::operator==(const Hex &obj)
{
	if (size != obj.size) return false; 
	for (int i = 0; i < size; i++)
	{
		if (pmem[i] != obj.pmem[i]) return false;
	}
	return true; 
}

bool Hex::operator!=(const Hex &obj)
{ 
	return !(*this == obj);
}

bool Hex::operator>=(const Hex &obj) 
{
	if (size > obj.size) return true; 
	if (size < obj.size) return false;
	for (int i = size - 2; i >= 0; i--) 
	{
		if (pmem[i] < obj.pmem[i]) return false; 
	}
	return true;
}

bool Hex::operator<=(const Hex &obj) 
{
	if (size < obj.size) return true;
	if (size > obj.size) return false;
	for (int i = size - 2; i >= 0; i--)
	{
		if (pmem[i] > obj.pmem[i]) return false;
	}
	return true;
}

bool Hex::operator>(const Hex &obj)
{
	return !(*this <= obj);
}

bool Hex::operator<(const Hex &obj) 
{
	return !(*this >= obj);
}

std::ostream& operator<<(std::ostream &stream, const Hex &obj) 
{ 
	for (int i = obj.size - 2; i >= 0; i--) 
	{
		stream << obj.pmem[i];
	}
	return stream; 
}

std::istream& operator>>(std::istream &stream, Hex &obj) 
{
	unsigned char *buf = new unsigned char[obj.size + 1]; 
	stream >> buf;
	buf[obj.size] = '\0'; 
	int j = 0;
	for (int i = obj.size - 2; i >= 0; i--)
	{
		obj.pmem[j] = buf[i];
		j++;
	}
	obj.pmem[j] = '\0'; 
	delete[]buf;
	return stream;
}
