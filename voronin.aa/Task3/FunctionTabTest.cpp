#include "FunctionTab.h"
#include<locale>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "russian");
	//--------------------------
	//Тест методов

	// Тест инициализатора
	FunctionTab test(1,10,10);
	FunctionTab test2;
	// Тест установки значений
	test2.setinterval(10,100);
	test2.setcount(10);
	test2.showcount();
	test2.showinterval_a();
	test2.showinterval_b();
		
	// Тест табулирования
	test2.do_tab(function4);
	test.do_tab(function4);
	// Тест вывода в файл
	ofstream fo;
	fo.open("test.txt");
	fo << test;
	fo.close();

	// Тест ввода из файла
	ifstream fi;
	fi.open("test.txt");
	FunctionTab testin;
	fi >> testin;
	fi.close();
  //----------------------------
	double a, b;
	int n;
	cout << "Введите интервал функции для табулирования" << endl;
	cin >> a >> b;
	cout <<endl << "Введите количество точек табуляции" << endl;
	cin >> n;
	FunctionTab ft(a, b, n);
	int choose;
	cout << "Выберите функцию для табуляции"
		<< endl << "1-Синус"
		<< endl << "2-Косинус"
		<< endl << "3-Экспонента"
		<< endl << "4-Возведение в квадрат"
		<< endl << "5-Возведение в куб"
		<< endl << "6-Квадратный корень из модуля"
		<< endl << "7-Тангенс" << endl;
	
	cin >> choose;
	switch (choose)
	{ 
	case 1:
	{ft.do_tab(function1);
		break; }
	case 2:
	{ft.do_tab(function2);
	break; }
	case 3:
	{ft.do_tab(function3);
	break; }
	case 4:
	{ft.do_tab(function4);
	break; }
	case 5:
	{ft.do_tab(function5);
	break; }
	case 6:
	{ft.do_tab(function6);
	break; }
	case 7:
	{ft.do_tab(function7);
	break; }
	}
	ft.get_tab();
	system("pause");
	return 0;
}
