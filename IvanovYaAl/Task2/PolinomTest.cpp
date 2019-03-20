#include "Polinom.h"

int main() {
	int n1, n2;
	cout << "Vvedite kol-vo koef. v pervom polinome: " << endl;
	cin >> n1;
	cout << "Vvedite kol-vo koef. vo vtorom polinome: " << endl;
	cin >> n2;
	Polinom a(n1), b(n2), sum(n1 + n2);
	cout << "Vvedite periy polinom: " << endl;
	cin >> a;
	cout << a;
	cout << "Vvedite vtoroy polinom: " << endl;
	cin >> b;
	cout << b;
	double p;
	cout << "Vvedite zna4enie X dlya s4eta: " << endl;
	cin >> p;
	cout << a.s4et(p) << endl;
	cout << b.s4et(p) << endl;
	sum = a + b;
	cout << "Summa dvuh polinomov: " << sum << endl;
	Polinom dir(n1);
	cout << "Proiavodnaya ot pervogo polinoma: " << endl;
	dir = a.proizvod();

	ofstream out("Polinom.txt");
	out << a;
	out.close();
	ifstream inp("Polinom.txt");
	inp.close();

	system("pause");
}