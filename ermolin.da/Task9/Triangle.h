#pragma once

class Triangle
{
private:
	double A, B, C;//������� ������������
public:
	//������������-----------------------------------------
	Triangle(void);//�� ���������
	Triangle(Triangle&);//�����������
	Triangle(double a, double b, double c);//��������������
	//�����������------------------------------------------
	~Triangle();
	//������-----------------------------------------------
	bool TriangleCorrect();//�������� ������������� ������������
	int Type();//����������� ���� ������������
	int Equiteral();//�������������� ��� ��������������
	double Square();//�������
	double Perimetr();//��������
	double GetA() { return A; }//���������� �������� �������
	double GetB() { return B; }
	double GetC() { return C; }
	double Cos(double a, double b, double c);//������� ���� ����� � � �
};
