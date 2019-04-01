#include <clocale>
#include <iostream>
#include <fstream>
#include "integrals.h"
using namespace std;

void vyvod(double a, double b, int n,double rez,double(*function)(double))//functia dlia vybora metoda
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
	cout << "Vvedite granitsy integrala:" << endl;
	cin >> a >> b;
	cout << "vvedite kol-vo razbieniy:" << endl;
	cin >> n;
	cout << "vyberite vid:\n1)sin(x)\n2)cos(x)\n3)exp(x)" << endl;
	cin >> q;
	switch (q)
	{
	case 1:
		cout << "vyberite metod vichisleniya:\n1)Metod levih priamougolnikov\n2)Metod pravih priamougolnikov\n3)Metod srednih priamougolnikov" << endl;
		{
		   vyvod(a,b,n,rez,sin);
		}
		break;
	case 2:
		cout << "vyberite metod vichisleniya:\n1)Metod levih priamougolnikov\n2)Metod pravih priamougolnikov\n3)Metod srednih priamougolnikov" << endl;
		{
		   vyvod(a,b,n,rez,cos);
		}
		break;
	case 3:
		cout << "vyberite metod vichisleniya:\n1)Metod levih priamougolnikov\n2)Metod pravih priamougolnikov\n3)Metod srednih priamougolnikov" << endl;
		{
		   vyvod(a,b,n,rez,exp);
		}
		break;

	}
}
