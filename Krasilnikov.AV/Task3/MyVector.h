#pragma once

template <typename T>
class MyVector
{
private:
	T *mas;
	int cur_Length;
	int max_Length;
	const int INCR_BASE = 8;

public:
	MyVector(void);
	MyVector(unsigned int size);
	MyVector(unsigned int size, T base);
	MyVector(const MyVector& vec);
	T & operator[](unsigned int index);
	const T & operator[](unsigned int index) const;
	void push_back(T element);
	void pop_back();
	void resize(unsigned int _size);
	unsigned int size();
	~MyVector();
};