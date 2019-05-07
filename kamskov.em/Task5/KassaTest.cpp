#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Kassa.h"
using namespace std;
int main() {
	int t, c;
	bool f = true;
	Kassa T;
	ifstream in;
	in.open("Sklad.txt");
	in >> T;
	in.close();
	cout << "Tovary so sklada: " << T << endl;
	cout << "1 - Dobavit tovar v korziny" << endl;
	cout << "2 - Ybrat tovar iz korziny" << endl;
	cout << "3 - Yznat informaciyu o tovare" << endl;
	cout << "4 - Vivesti check" << endl;
	cout << "5 - Exit" << endl;
	while (f) {
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Vvedite kod tovara - ";
			cin >> t;
			if (!T.Add(t)) 
			{
				cout << "Kod nedejstvitelen" << endl;
			}
			break;
		case 2:
			cout << "Vvedite kod tovara - ";
			cin >> t;
			if (!T.Delete(t))
			{
				cout << "Kod nedejstvitelen" << endl;
			}
			break;
		case 3:
			cout << "Vvedite kod tovara - ";
			cin >> t;
			if (T.Scan(t) != -1) { cout << T.Info(t); }
			else cout << "Kod nedejstvitelen" << endl;
			break;
		case 4:
			T.CreateCheck();
			break;
		case 5:
			f = false;
			break;
		default:
			cout << "Viberite cifru iz predstavlennogo vishe spiska: ";
		}
	}
	getchar();
	getchar();
	return 0;
}