#pragma once
#include <string>

using namespace std;
class Triangle
{
public:
	//������������
	Triangle();
	Triangle(int a, int b, int c);
	Triangle(const Triangle &);

	//������
	bool isExists();
	string type();
	int S();
	int P();

	//������ �������
	int& A();
	int& B();
	int& C();

	//�����������
	~Triangle();
private:
	int a, b, c;
};

