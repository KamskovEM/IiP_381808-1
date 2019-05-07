
#include "Triangle.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");
	int m = 5;   //������� ��� ����
	while (m == 5) {
		double a, b, c;   //������� ������������
		do {
			cout << "Vvedite tri storoni: ";

			InputSides(&a, &b, &c);  //���� ������
			if (a + b > c && a + c > b && b + c > a) {}
			else{ cout << "Takogo treugolnika ne sush'estvuet\n"; }  //�������� �������������
		}
		while (a + b < c || c + a < b || b + c < a);	//�������� �������������


		Triangle Sid;
		Sid.Sides(a, b, c);  //���������� ������ ������
		
		do {

			outputMenu();
			cout << "---> ";
			cin >> m;    //����� ��������
			cout << "\n";

			switch (m) {
			case 0: {return 0; }
			case 1: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				Sid.TestT();    //��� ������������
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";
				getchar();
				getchar();
				break;
			}
			case 2: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout <<"Perimetr = "<<Sid.Perm()<<endl;   //��������
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";
				getchar();
				getchar();
				break;
			}

			case 3: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout<<"Plosh'ad = "<<Sid.Area()<<endl;   //�������
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";
				getchar();
				getchar();
				break;
			}

			case 4: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				Sid.TestT();     //��� ������������
				cout << "Perimetr = " << Sid.Perm() << endl;   //��������
				cout << "Plosh'ad = " << Sid.Area() << endl;   //�������

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
		//����� ����� ����


	}







	getchar();
	return 0;
}