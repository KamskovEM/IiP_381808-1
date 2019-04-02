#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <Windows.h>
#include "MyVector.cpp"

using namespace std;

class Menu
{
private:
	int count;
	MyVector<string> elements;
	int selected;
public:
	Menu(void);
	Menu(int s);
	Menu(const Menu& m);
	void set_size(unsigned int c);
	unsigned int size();
	void set_line(int number, string line);
	string select(unsigned int i);
	string show_select();
	void show(unsigned int x, unsigned int y);
	friend istream & operator>> (istream & in, Menu & m);
	friend ostream & operator<< (ostream & out, const Menu & m);
	~Menu();
};
