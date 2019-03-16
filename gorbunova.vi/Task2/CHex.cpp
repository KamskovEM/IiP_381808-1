#include "CHex.h"
#include <iostream>

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
}

Hex& Hex::operator=(const Hex &obj)
{
	if (this == &obj) return *this;
	delete[]pmem;
	size = obj.size;
	pmem = new unsigned char[size];
	for (int i = 0; i < size; i++)
	{
		pmem[i] = obj.pmem[i];
	}
	return *this;
}

Hex Hex::operator+(const Hex &obj) 
{
	int a = 0, b = 0; 
	int p = 1;
	for (int i = 0; pmem[i] != '\0'; i++) 
	{
		switch (pmem[i])
		{
		case '0': a += 0 * p; break;
		case '1': a += 1 * p; break;
		case '2': a += 2 * p; break;
		case '3': a += 3 * p; break;
		case '4': a += 4 * p; break;
		case '5': a += 5 * p; break;
		case '6': a += 6 * p; break;
		case '7': a += 7 * p; break;
		case '8': a += 8 * p; break;
		case '9': a += 9 * p; break;
		case 'A': a += 10 * p; break;
		case 'B': a += 11 * p; break;
		case 'C': a += 12 * p; break;
		case 'D': a += 13 * p; break;
		case 'E': a += 14 * p; break;
		case 'F': a += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	p = 1;
	for (int i = 0; obj.pmem[i] != '\0'; i++) 
	{
		switch (obj.pmem[i])
		{
		case '0': b += 0 * p; break;
		case '1': b += 1 * p; break;
		case '2': b += 2 * p; break;
		case '3': b += 3 * p; break;
		case '4': b += 4 * p; break;
		case '5': b += 5 * p; break;
		case '6': b += 6 * p; break;
		case '7': b += 7 * p; break;
		case '8': b += 8 * p; break;
		case '9': b += 9 * p; break;
		case 'A': b += 10 * p; break;
		case 'B': b += 11 * p; break;
		case 'C': b += 12 * p; break;
		case 'D': b += 13 * p; break;
		case 'E': b += 14 * p; break;
		case 'F': b += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	int c = a + b; 
	int c_size = 0;
	int temp = c;
	while (temp != 0) 
	{
		temp /= 16;
		c_size++;
	}
	Hex result(c_size); 
	int i = 0;
	while (c != 0)
	{
		switch (c % 16)
		{
		case 0: result.pmem[i] = '0'; break;
		case 1: result.pmem[i] = '1'; break;
		case 2: result.pmem[i] = '2'; break;
		case 3: result.pmem[i] = '3'; break;
		case 4: result.pmem[i] = '4'; break;
		case 5: result.pmem[i] = '5'; break;
		case 6: result.pmem[i] = '6'; break;
		case 7: result.pmem[i] = '7'; break;
		case 8: result.pmem[i] = '8'; break;
		case 9: result.pmem[i] = '9'; break;
		case 10: result.pmem[i] = 'A'; break;
		case 11: result.pmem[i] = 'B'; break;
		case 12: result.pmem[i] = 'C'; break;
		case 13: result.pmem[i] = 'D'; break;
		case 14: result.pmem[i] = 'E'; break;
		case 15: result.pmem[i] = 'F'; break;
		default:
			break;
		}
		c /= 16;
		i++;
	}
	result.pmem[i] = '\0'; 
	return result; 
}

Hex Hex::operator-(const Hex &obj) 
{
	int a = 0, b = 0;
	int p = 1;
	for (int i = 0; pmem[i] != '\0'; i++)
	{
		switch (pmem[i])
		{
		case '0': a += 0 * p; break;
		case '1': a += 1 * p; break;
		case '2': a += 2 * p; break;
		case '3': a += 3 * p; break;
		case '4': a += 4 * p; break;
		case '5': a += 5 * p; break;
		case '6': a += 6 * p; break;
		case '7': a += 7 * p; break;
		case '8': a += 8 * p; break;
		case '9': a += 9 * p; break;
		case 'A': a += 10 * p; break;
		case 'B': a += 11 * p; break;
		case 'C': a += 12 * p; break;
		case 'D': a += 13 * p; break;
		case 'E': a += 14 * p; break;
		case 'F': a += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	p = 1;
	for (int i = 0; obj.pmem[i] != '\0'; i++)
	{
		switch (obj.pmem[i])
		{
		case '0': b += 0 * p; break;
		case '1': b += 1 * p; break;
		case '2': b += 2 * p; break;
		case '3': b += 3 * p; break;
		case '4': b += 4 * p; break;
		case '5': b += 5 * p; break;
		case '6': b += 6 * p; break;
		case '7': b += 7 * p; break;
		case '8': b += 8 * p; break;
		case '9': b += 9 * p; break;
		case 'A': b += 10 * p; break;
		case 'B': b += 11 * p; break;
		case 'C': b += 12 * p; break;
		case 'D': b += 13 * p; break;
		case 'E': b += 14 * p; break;
		case 'F': b += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	int c = a - b;
	int c_size = 0;
	int temp = c;
	while (temp != 0)
	{
		temp /= 16;
		c_size++;
	}
	Hex result(c_size);
	int i = 0;
	while (c != 0)
	{
		switch (c % 16)
		{
		case 0: result.pmem[i] = '0'; break;
		case 1: result.pmem[i] = '1'; break;
		case 2: result.pmem[i] = '2'; break;
		case 3: result.pmem[i] = '3'; break;
		case 4: result.pmem[i] = '4'; break;
		case 5: result.pmem[i] = '5'; break;
		case 6: result.pmem[i] = '6'; break;
		case 7: result.pmem[i] = '7'; break;
		case 8: result.pmem[i] = '8'; break;
		case 9: result.pmem[i] = '9'; break;
		case 10: result.pmem[i] = 'A'; break;
		case 11: result.pmem[i] = 'B'; break;
		case 12: result.pmem[i] = 'C'; break;
		case 13: result.pmem[i] = 'D'; break;
		case 14: result.pmem[i] = 'E'; break;
		case 15: result.pmem[i] = 'F'; break;
		default:
			break;
		}
		c /= 16;
		i++;
	}
	result.pmem[i] = '\0';
	return result;
}

Hex Hex::operator*(const Hex &obj)
{
	int a = 0, b = 0;
	int p = 1;
	for (int i = 0; pmem[i] != '\0'; i++)
	{
		switch (pmem[i])
		{
		case '0': a += 0 * p; break;
		case '1': a += 1 * p; break;
		case '2': a += 2 * p; break;
		case '3': a += 3 * p; break;
		case '4': a += 4 * p; break;
		case '5': a += 5 * p; break;
		case '6': a += 6 * p; break;
		case '7': a += 7 * p; break;
		case '8': a += 8 * p; break;
		case '9': a += 9 * p; break;
		case 'A': a += 10 * p; break;
		case 'B': a += 11 * p; break;
		case 'C': a += 12 * p; break;
		case 'D': a += 13 * p; break;
		case 'E': a += 14 * p; break;
		case 'F': a += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	p = 1;
	for (int i = 0; obj.pmem[i] != '\0'; i++)
	{
		switch (obj.pmem[i])
		{
		case '0': b += 0 * p; break;
		case '1': b += 1 * p; break;
		case '2': b += 2 * p; break;
		case '3': b += 3 * p; break;
		case '4': b += 4 * p; break;
		case '5': b += 5 * p; break;
		case '6': b += 6 * p; break;
		case '7': b += 7 * p; break;
		case '8': b += 8 * p; break;
		case '9': b += 9 * p; break;
		case 'A': b += 10 * p; break;
		case 'B': b += 11 * p; break;
		case 'C': b += 12 * p; break;
		case 'D': b += 13 * p; break;
		case 'E': b += 14 * p; break;
		case 'F': b += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	int c = a * b;
	int c_size = 0;
	int temp = c;
	while (temp != 0)
	{
		temp /= 16;
		c_size++;
	}
	Hex result(c_size);
	int i = 0;
	while (c != 0)
	{
		switch (c % 16)
		{
		case 0: result.pmem[i] = '0'; break;
		case 1: result.pmem[i] = '1'; break;
		case 2: result.pmem[i] = '2'; break;
		case 3: result.pmem[i] = '3'; break;
		case 4: result.pmem[i] = '4'; break;
		case 5: result.pmem[i] = '5'; break;
		case 6: result.pmem[i] = '6'; break;
		case 7: result.pmem[i] = '7'; break;
		case 8: result.pmem[i] = '8'; break;
		case 9: result.pmem[i] = '9'; break;
		case 10: result.pmem[i] = 'A'; break;
		case 11: result.pmem[i] = 'B'; break;
		case 12: result.pmem[i] = 'C'; break;
		case 13: result.pmem[i] = 'D'; break;
		case 14: result.pmem[i] = 'E'; break;
		case 15: result.pmem[i] = 'F'; break;
		default:
			break;
		}
		c /= 16;
		i++;
	}
	result.pmem[i] = '\0';
	return result;
}

bool Hex::operator==(const Hex &obj) 
{
	int a = 0, b = 0;
	int p = 1;
	for (int i = 0; pmem[i] != '\0'; i++)
	{
		switch (pmem[i])
		{
		case '0': a += 0 * p; break;
		case '1': a += 1 * p; break;
		case '2': a += 2 * p; break;
		case '3': a += 3 * p; break;
		case '4': a += 4 * p; break;
		case '5': a += 5 * p; break;
		case '6': a += 6 * p; break;
		case '7': a += 7 * p; break;
		case '8': a += 8 * p; break;
		case '9': a += 9 * p; break;
		case 'A': a += 10 * p; break;
		case 'B': a += 11 * p; break;
		case 'C': a += 12 * p; break;
		case 'D': a += 13 * p; break;
		case 'E': a += 14 * p; break;
		case 'F': a += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	p = 1;
	for (int i = 0; obj.pmem[i] != '\0'; i++)
	{
		switch (obj.pmem[i])
		{
		case '0': b += 0 * p; break;
		case '1': b += 1 * p; break;
		case '2': b += 2 * p; break;
		case '3': b += 3 * p; break;
		case '4': b += 4 * p; break;
		case '5': b += 5 * p; break;
		case '6': b += 6 * p; break;
		case '7': b += 7 * p; break;
		case '8': b += 8 * p; break;
		case '9': b += 9 * p; break;
		case 'A': b += 10 * p; break;
		case 'B': b += 11 * p; break;
		case 'C': b += 12 * p; break;
		case 'D': b += 13 * p; break;
		case 'E': b += 14 * p; break;
		case 'F': b += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	return (a == b);
}

bool Hex::operator!=(const Hex &obj) 
{
	return !(*this == obj);
}

bool Hex::operator>=(const Hex &obj) 
{
	int a = 0, b = 0;
	int p = 1;
	for (int i = 0; pmem[i] != '\0'; i++)
	{
		switch (pmem[i])
		{
		case '0': a += 0 * p; break;
		case '1': a += 1 * p; break;
		case '2': a += 2 * p; break;
		case '3': a += 3 * p; break;
		case '4': a += 4 * p; break;
		case '5': a += 5 * p; break;
		case '6': a += 6 * p; break;
		case '7': a += 7 * p; break;
		case '8': a += 8 * p; break;
		case '9': a += 9 * p; break;
		case 'A': a += 10 * p; break;
		case 'B': a += 11 * p; break;
		case 'C': a += 12 * p; break;
		case 'D': a += 13 * p; break;
		case 'E': a += 14 * p; break;
		case 'F': a += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	p = 1;
	for (int i = 0; obj.pmem[i] != '\0'; i++)
	{
		switch (obj.pmem[i])
		{
		case '0': b += 0 * p; break;
		case '1': b += 1 * p; break;
		case '2': b += 2 * p; break;
		case '3': b += 3 * p; break;
		case '4': b += 4 * p; break;
		case '5': b += 5 * p; break;
		case '6': b += 6 * p; break;
		case '7': b += 7 * p; break;
		case '8': b += 8 * p; break;
		case '9': b += 9 * p; break;
		case 'A': b += 10 * p; break;
		case 'B': b += 11 * p; break;
		case 'C': b += 12 * p; break;
		case 'D': b += 13 * p; break;
		case 'E': b += 14 * p; break;
		case 'F': b += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	return (a >= b);
}

bool Hex::operator<=(const Hex &obj)
{
	int a = 0, b = 0;
	int p = 1;
	for (int i = 0; pmem[i] != '\0'; i++)
	{
		switch (pmem[i])
		{
		case '0': a += 0 * p; break;
		case '1': a += 1 * p; break;
		case '2': a += 2 * p; break;
		case '3': a += 3 * p; break;
		case '4': a += 4 * p; break;
		case '5': a += 5 * p; break;
		case '6': a += 6 * p; break;
		case '7': a += 7 * p; break;
		case '8': a += 8 * p; break;
		case '9': a += 9 * p; break;
		case 'A': a += 10 * p; break;
		case 'B': a += 11 * p; break;
		case 'C': a += 12 * p; break;
		case 'D': a += 13 * p; break;
		case 'E': a += 14 * p; break;
		case 'F': a += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	p = 1;
	for (int i = 0; obj.pmem[i] != '\0'; i++)
	{
		switch (obj.pmem[i])
		{
		case '0': b += 0 * p; break;
		case '1': b += 1 * p; break;
		case '2': b += 2 * p; break;
		case '3': b += 3 * p; break;
		case '4': b += 4 * p; break;
		case '5': b += 5 * p; break;
		case '6': b += 6 * p; break;
		case '7': b += 7 * p; break;
		case '8': b += 8 * p; break;
		case '9': b += 9 * p; break;
		case 'A': b += 10 * p; break;
		case 'B': b += 11 * p; break;
		case 'C': b += 12 * p; break;
		case 'D': b += 13 * p; break;
		case 'E': b += 14 * p; break;
		case 'F': b += 15 * p; break;
		default:
			break;
		}
		p *= 16;
	}
	return (a <= b);
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