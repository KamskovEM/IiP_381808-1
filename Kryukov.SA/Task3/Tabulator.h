#pragma once
#include <fstream> 
using namespace std;
typedef double(*Tfun)(double);
class Tabulator
{
private:
	Tfun fun;
	double a, b; 
	double *f;
	double *X;
	int n;
public:
	//constructors
	Tabulator();//po umolchaniu
	//inicializators
	Tabulator::Tabulator(int num, double a_, double b_);//, Tfun fun_
	/*Tabulator(int num);
	Tabulator(double a_, double b_);*/
	//Tabulator::Tabulator(Tfun fun_);
	//COPY
	Tabulator(const Tabulator &Dr);
	//Destructor
	~Tabulator();
	///////////////////////
	//������ � ��������
	friend ostream& operator<<(ostream& stream, const Tabulator &Dr); // ����� 
	friend istream& operator>>(istream& stream, Tabulator &Dr); // ���� �� ������
	//��������
	void Tabulator::INTERVAL(double _a, double _b);//������ ��������
	void Tabulator::Tochki(int _n);
	double Tabulator::INTER1();
	double Tabulator::INTER2();
	int Tabulator::Tochki1();
	void Tabulator::show(const char* name1, const char* name2);
	void Tabulator::Tabulirovanie(Tfun _fun);
	class Range//��� ��������� ����������
	{
	};
};
double ff2(double x);
double ff1(double x);
double ff3(double x);
double ff4(double x);