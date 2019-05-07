
#include "Triangle.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");
	int m = 5;   //Счетчик для меню
	while (m == 5) {
		double a, b, c;   //Стороны треугольника
		do {
			cout << "Vvedite tri storoni: ";

			InputSides(&a, &b, &c);  //Ввод сторон
			if (a + b > c && a + c > b && b + c > a) {}
			else{ cout << "Takogo treugolnika ne sush'estvuet\n"; }  //Проверка существования
		}
		while (a + b < c || c + a < b || b + c < a);	//Проверка существования


		Triangle Sid;
		Sid.Sides(a, b, c);  //Присвоение классу сторон
		
		do {

			outputMenu();
			cout << "---> ";
			cin >> m;    //Выбор действия
			cout << "\n";

			switch (m) {
			case 0: {return 0; }
			case 1: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				Sid.TestT();    //Тип треугольника
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";
				getchar();
				getchar();
				break;
			}
			case 2: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout <<"Perimetr = "<<Sid.Perm()<<endl;   //Периметр
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";
				getchar();
				getchar();
				break;
			}

			case 3: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout<<"Plosh'ad = "<<Sid.Area()<<endl;   //Площадь
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";
				getchar();
				getchar();
				break;
			}

			case 4: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				Sid.TestT();     //Тип треугольника
				cout << "Perimetr = " << Sid.Perm() << endl;   //Периметр
				cout << "Plosh'ad = " << Sid.Area() << endl;   //Площадь

				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";

				getchar();
				getchar();
				break; }


			case 5: {cout << "______________________________________________________  New Task  ______________________________________________________\n\n";
				break;
			}
			default:cout << "Wrong data, try input again!\n\n";
			}

		} while (m != 0 && m != 5);
		//Конец вайла меню


	}







	getchar();
	return 0;
}