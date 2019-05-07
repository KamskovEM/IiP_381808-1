#include "Tabulator.h"

double func_sin(double);
double func_cos(double);
double func_exp(double);
double func_sinXcos(double);
double func_tgXexp(double);

int main() {
	double a, b;
	int k;
	cout << "Vvedite levuu granicu funkcii: " << endl;
	cin >> a;
	cout << "Vvedite pravuu granicu funkcii: " << endl;
	cin >> b;
	cout << "Vvedite kol-vo to4ek funkcii: " << endl;
	cin >> k;
	Tabulator TUTU(k, a, b);
	cout << "Vibirite funkciu: " << endl;
	cout << "1. sin\n2. cos\n3. exp\n4. sin*cos\n5. tg*exp" << endl;
	int l;
	cin >> l;
	switch (l)
	{
	case 1:
		TUTU.Tabulirovanie(func_sin);
		break;
	case 2:
		TUTU.Tabulirovanie(func_cos);
		break;
	case 3:
		TUTU.Tabulirovanie(func_exp);
		break;
	case 4:
		TUTU.Tabulirovanie(func_sinXcos);
		break;
	case 5:
		TUTU.Tabulirovanie(func_tgXexp);
		break;
	default:
		cout << "Vvedite verniy nomer funkcii!!" << endl;
		break;
	}
	TUTU.TabShow();

	Tabulator Test(k, a, b);
	ofstream os("Tabulator.txt");
	os << Test;
	os.close();

	ifstream is("Tabulator.txt");
	is >> Test;
	is.close();

	Test.TabShow();
	system("pause");
	return 0;
}

double func_sin(double x) {
	return sin(x);
}
double func_cos(double x) {
	return cos(x);
}
double func_exp(double x) {
	return exp(x);
}
double func_sinXcos(double x) {
	return sin(x)*cos(x);
}
double func_tgXexp(double x) {
	return tan(x)*exp(x);
}