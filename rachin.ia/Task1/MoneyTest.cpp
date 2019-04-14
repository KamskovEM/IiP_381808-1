#include "Money.h"

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");
	int m = 5;   //Schetchik menu
	while (m == 5) {
		double D1,D2;  //Mnozhitel, Delitel'
		Money A1, A2;  //First Amount , Second Amount
		int rub, kop;  //Rubli i kopeiki dlya drugogo sposoba vvoda
		cout << "Enter first amount of money (Rubles  Kopecks) A1 = ";
		cin >> A1;
		cout << "Enter second amount of money (Rubles  Kopecks) A2 = ";
		cin >> rub>> kop;
		A2.WriteK(kop);  //Prisvaivanie kopeek
		A2.WriteR(rub);  //Prisvaivanie rubley
		A1.MoneyPere();  //Kopeyki v rubli
		A2.MoneyPere();  //Kopeyki v rubli

		cout << "Enter real number for multiplication * - "; cin >> D1;
		cout << "Enter real number for division / - "; cin >> D2;


		do {

			outputMenu();
			cout << "---> ";
			cin >> m;    //Выбор действия
			cout << "\n";

			switch (m) {
			case 0: {return 0; }
			case 1: {
				cout << "________________________________________________________________________________________________________________________\n\n";
				cout << "A1 = " << A1 << "A2 = " << A2 << endl;
				cout << "A1 + A2 =  " << (A1 + A2) << endl;
				cout << "A1 - A2 =  " << (A1 - A2) << endl;

				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";
				getchar();
				getchar();
				break;
			}
			case 2: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				
				cout << "A1 = " << A1 << "A2 = " << A2 << endl;
				cout << "A1 * "<<D1<<" =  " << (A1 * D1) << endl;
				cout << "A1 / "<<D2<<" =  " << (A1 / D2) << endl;

				cout << "A2 * " << D1 << " =  " << (A2 * D1) << endl;
				cout << "A2 / " << D2 << " =  " << (A2 / D2) << endl;


				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";
				getchar();
				getchar();
				break;
			}

			case 3: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				if (A1 == A2) { cout << "Amount of money №1 and Amount of money №2 equal" << endl; }
				else 
				{ 
					cout << "Amount of money №1 and Amount of money №2 not equal!" << endl;
					if (A1 < A2) { cout << "First amount less than second amount of money!" << endl; }
					else { cout << "First amount is bigger than second amount of money!" << endl; }
				}

				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "Press the button <<Enter>> to continue...\n";
				getchar();
				getchar();
				break;
			}

			case 4: {
				cout << "________________________________________________________________________________________________________________________\n\n";

				cout << "A1 = " << A1 << "A2 = " << A2 << endl;
				cout << "A1 + A2 =  " << (A1 + A2) << endl;
				cout << "A1 - A2 =  " << (A1 - A2) << endl;

				cout << "A1 * " << D1 << " =  " << (A1 * D1) << endl;
				cout << "A1 / " << D2 << " =  " << (A1 / D2) << endl;

				cout << "A2 * " << D1 << " =  " << (A2 * D1) << endl;
				cout << "A2 / " << D2 << " =  " << (A2 / D2) << endl;

				if (A1 == A2) { cout << "Amount of money №1 and Amount of money №2 equal" << endl; }
				else
				{
					cout << "Amount of money №1 and Amount of money №2 not equal!" << endl;
					if (A1 < A2) { cout << "First amount less than second amount of money!" << endl; }
					else { cout << "First amount is bigger than second amount of money!" << endl; }
				}


				

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
		//End of while Menu
	}
	getchar();
	return 0;
}