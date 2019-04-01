#include <clocale>
#include <iostream>
#include <fstream>
#include "integrals.h"
using namespace std;

void vyvod(double a, double b, int n,double rez,double(*function)(double))//функция для выбора метода 
{
	double I;
	int w;
	cin >> w;
	switch (w)
	{
	case 1:
	{   
		integrals c(a, b, n,rez, function);
		I =c.LeftRectangle();
		cout << "Результат:" << I << endl;
		break;
	}
	case 2:
	{
		integrals c(a, b, n, rez, function);
		I = c.RightRectangle();
		cout << "Результат:" << I << endl;
		break;
	}
	case 3:
	{
		integrals c(a, b, n, rez, function);
		I = c.CentralRectangle();
		cout << "Результат:" << I << endl;
		break;
	}
	}

}

int main()
{
	int q;
	double a, b,rez=0;
	int n;
	setlocale(LC_ALL, "Rus");
	cout << "Введите границы интеграла:" << endl;
	cin >> a >> b;
	cout << "Введите кол-во шагов:" << endl;
	cin >> n;
	cout << "Выберете вид функции:\n1)sin(x)\n2)cos(x)\n3)exp(x)" << endl;
	cin >> q;
	switch (q)
	{
	case 1:
		cout << "Выберете медот вычиления:\n1)Метод левых прямоугольников\n2)Метод правых прямоугольников\n3)Метод средних прямоугольников" << endl;
		{
		   vyvod(a,b,n,rez,sin);
		}
		break;
	case 2:
		cout << "Выберете медот вычиления:\n1)Метод левых прямоугольников\n2)Метод правых прямоугольников\n3)Метод средних прямоугольников" << endl;
		{
		   vyvod(a,b,n,rez,cos);
		}
		break;
	case 3:
		cout << "Выберете медот вычиления:\n1)Метод левых прямоугольников\n2)Метод правых прямоугольников\n3)Метод средних прямоугольников" << endl;
		{
		   vyvod(a,b,n,rez,exp);
		}
		break;

	}
}
