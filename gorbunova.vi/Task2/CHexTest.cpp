#include <iostream>
#include <fstream>
#include "CHex.h"

using namespace std;

int main() 
{
	
		int len_a = 0, len_b = 0;
		cout << "Enter len a, b : ";
		cin >> len_a >> len_b;
		Hex a(len_a), b(len_b);
		cout << "Enter a in hex format with len " << len_a << " : ";
		cin >> a; // ����� ������� ������ ����� �� 0 �� 9 � ����� A-F 
		cout << "Enter b in hex format with len " << len_b << " : ";
		cin >> b;
		cout << "a + b = :" << (a + b) << endl;
		cout << "a - b = :" << (a - b) << endl;
		cout << "a == b = :" << (a == b) << endl;
		cout << "a != b = :" << (a != b) << endl;
		cout << "a > b = :" << (a > b) << endl;
		cout << "a < b = :" << (a < b) << endl;
		
}