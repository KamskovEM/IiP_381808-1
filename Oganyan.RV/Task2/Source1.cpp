#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <string>
#define MAX 13;
using namespace std;
enum PolynomialExeption { coeffINDOUTOFRANGE }; // тип исключения
class Polynomial {
private:
	int size;
	double* coeff;
public:
	Polynomial(); // Конструктор
	Polynomial(int _size); // Конструктор
	~Polynomial(); // Деструктор
	Polynomial(const Polynomial& _Poly); // Конструктор копирования
	Polynomial& operator= (const Polynomial& _Poly); // перегрузка присваивания
	friend istream& operator>>(istream & stream, Polynomial & _Poly);
	friend ostream& operator<<(ostream & stream, const Polynomial & _Poly);
	double& operator[] (int); // перегрузка индексикации с контролем выхода за предел массива
	const double& operator[] (int) const; // перегрузка индексикации с контролем выхода за предел массива
	//
	void SetPolydegree(int); // Установить степень полинома
	//int Polydegree(); // Узнать степениь полинома
	int GetPolydegree(); // Узнать степениь полинома
	double Polycoef(int); // Узнать коэффицент монома
	double Polyfunvalue(double); // Посчитать значение в точке
	Polynomial Polydifferential(); // Производная 
};
Polynomial::Polynomial()
{
	coeff = NULL;
	size = 0;
}
Polynomial::Polynomial(int _size) {
	size = _size;
	coeff = new double[size + 1];
	int i;
	for (i = 0; i < size + 1; i++)
		coeff[i] = 0.0;
}
Polynomial::~Polynomial() {
	size = 0;
	coeff = NULL;
}
Polynomial::Polynomial(const Polynomial& _Poly)
{
	coeff = new double[_Poly.size];
	for (int i = 0; i < _Poly.size; i++)
	{
		coeff[i] = _Poly.coeff[i];
	}
	size = _Poly.size;
}
Polynomial& Polynomial::operator= (const Polynomial& _Poly)
{
	if (this != &_Poly) {
		if (size < _Poly.size)
		{
			delete[] coeff;
			size = _Poly.size;
			coeff = new double[size + 1];
		}
		for (int i = 0; i <= size; i++)
		{
			coeff[i] = _Poly.coeff[i];
		}
	}
	return *this;
}
istream& operator>>(istream & stream, Polynomial & _Poly)
{

	for (int i = 0; i <= _Poly.size; i++)
	{
		stream >> _Poly.coeff[i];
	}
	return stream;
}
void Polynomial::SetPolydegree(int degree)
{
	size = degree;
	int i;
	for (i = 0; i < size + 1; i++)
		coeff[i] = 0.0;

}
/*int Polynomial::Polydegree() {
	int degree = 0;
	for (int i = 0; i <=size; i++) {
		if (coeff[i] != 0)
			degree = i;
	}
	return degree; 
} */

int Polynomial::GetPolydegree()
{
	return size;
}
double Polynomial::Polycoef(int i1) {
	return coeff[i1];
}
double Polynomial::Polyfunvalue(double d1) {
	double y = 0.0;
	int i;
	for (i = 0; i < size; i++)
		y += coeff[i] * pow(d1, i);
	return y;
}
Polynomial Polynomial::Polydifferential() {
	Polynomial pdif(size);
	for (int i = 0; i < size; i++)
	{
		pdif.coeff[i] = (i + 1)*coeff[i + 1];
	}
	return pdif;
}
ostream& operator<<(ostream & stream, const Polynomial & _Poly)
{
	int  size = 0;
	bool flag = true;
	bool firstflag = true;
	int i = 0;
	while (i <= _Poly.size && flag == true) {
		if (_Poly.coeff[i] != 0)
			flag = false;
		i++;
	}
	if (flag == false)
	{
		for (i = _Poly.size; i >= 1; i--)
		{
			if (firstflag == true)
			{
				stream << _Poly.coeff[i] << "*x^" << i;;
				firstflag = false;
			}
			else
			{
				if (_Poly.coeff[i] > 0)
				{
					stream << "+" << _Poly.coeff[i] << "*x^" << i;
				}
				if (_Poly.coeff[i] < 0)
				{
					stream << _Poly.coeff[i] << "*x^" << i;
				}
			}
		}
		if (i == 0)
		{
			if (_Poly.coeff[i] < 0)
				stream << _Poly.coeff[i];
			else if (_Poly.coeff > 0)
				stream << "+" << _Poly.coeff[i];
		}
		stream << endl;
	}
	else
	{
		stream << 0;
	}
	return stream;
}
double& Polynomial::operator[](int index) {
	if (index < 0 || index > 12) {
		PolynomialExeption expt = coeffINDOUTOFRANGE;
		throw expt;
	}
	return coeff[index];
}
const double& Polynomial::operator[](int index) const {
	if (index < 0 || index > 12) {
		PolynomialExeption expt = coeffINDOUTOFRANGE;
		throw expt;
	}
	return coeff[index];
}
void main() {
	int n1;
	cout << "Введите степень полинома: " << endl;
	cin >> n1;
	Polynomial Poly(n1);
	cout << "Введите коэффиценты: " << endl;
	cin >> Poly;
	cout << "Степень полинома: " << Poly.GetPolydegree() << endl;
	cout << "Введите номер коэффицента, значение которого хотите узнать: " << endl;
	int index2;
	cin >> index2;
	cout << "Значения коэффицента с номером" << index2 << " равно: " << Poly.Polycoef(index2) << endl;
	cout << "Введите точку, в которой хотите найти значение полинома" << endl;
	int x;
	cin >> x;
	cout << "Значение полинома в заданной точке " << x << " x = " << Poly.Polyfunvalue(x) << endl;
	cout << "Производная полинома" << Poly.Polydifferential() << endl;



}