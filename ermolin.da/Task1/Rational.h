#pragma once
#include <iostream>

using namespace std;

class Rational
{
private:
	int m, n;//��������� � �����������
public:
	//������������-------------------------
	Rational();//�����������
	Rational(int m);//��������������� ����
	Rational(const Rational&c);//�����������
	Rational(int m, int n);//������������
	//����������-------------------------
	~Rational();
	//����������---------------------------
	Rational operator + (const Rational & b);//�������� ������
	Rational operator + (int b);//�������� � ����� ������
	Rational operator- (const Rational & b);//�������� ������
	Rational operator- (int b);//��������� ������
	Rational operator* (const Rational & b);//������������ ������
	Rational operator* (int b);//��������� �� �����
	Rational operator/ (const Rational & b);//������� ������
	Rational operator/ (int b);//������� �� �����
	Rational operator= (const Rational & b);//���������� �����
	Rational operator= (int b);//���������� ������
	bool operator== (const Rational & b);//��������� ������
	bool operator== (int b);//��������� � �����
	bool operator!= (const Rational & b);//����������� ������
	bool operator!= (int b);//����������� � �����
	bool operator< (const Rational & b);//��������� ������, �<b
	bool operator< (int b);//��������� ������, �<b
	bool operator> (const Rational & b);//��������� ������, �>b
	bool operator> (int b);//��������� ������, �>b
	bool operator<= (const Rational & b);//��������� ������, �<=b
	bool operator<= (int b);//��������� ������, �<=b
	bool operator>= (const Rational & b);//��������� ������, �>=b
	bool operator>=(int b);//��������� ������, �>=b
	friend ostream& operator<< (ostream& stream, const Rational & b);//���������� ������
	friend istream& operator>> (istream& stream, Rational & b);//���������� �����
	//������------------------------------
public:
	void SetM(int M) { m = M; }//��������� ���������
	void SetN(int N) { n = N; }//��������� �����������
	int GetM() { return m; }//����� ���������
	int GetN() { return n; }//����� �����������
private:
	void Canc();//���������� �����
};

