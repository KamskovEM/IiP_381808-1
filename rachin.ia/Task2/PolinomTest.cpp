#include "Polinom.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	double x;  //Точка в которой нужно найти полином
	int d;	//Степень полинома

		cout << "Введите степень полинома от 0 до бесконечности: ";
		cin >> d;
		Polinom T(d);
	

	cout << "Введите 1 - " << d + 1 << " коэффициенты полинома ( от нулевой степени до старшей): ";
	for (int j = 0; j < d + 1; j++)cin >> T[j];
	cout << "Введенный полином: ";
	T.Output();
	cout << endl;
	cout << "Производная полинома: ";
	T.devar().Output();
	cout << endl;
	cout << "Введите x, чтобы найти значение полинома в точке: ";
	cin >> x;
	cout << "Значение полинома в точке " << x << " - ";
	cout<<T.FuncVal(x)<<endl;
	int b;   //Степень для ввода пользователем
	cout << "Введите степень члена полинома, коэффициент которого хотите узнать: ";
	cin >> b;
	cout << "Коэффициент "<<b<<" степени = ";
	cout << T.CheckCoef(b)<<endl;
	cout << "Степень полинома с которым проводилась работа - ";
	cout << T.Checkn()<<endl;
	
	ofstream output;
	output.open("output1.txt");
	output << T;
	output.close();
	ifstream input;
	int m; //Ввод из файла степени полинома  также можно input>>T;
	input.open("input.txt");
	input >> m;
	Polinom D(m);
	for (int j = 0; j < m + 1; j++)input >> D[j];
	input.close();
	cout << " Записано из 'input.txt': " << D << endl;
	
	Polinom S = T + D;
	cout << "Сумма двух полиномов(из консоли и из файла): " << endl;
	S.Output();
	output.open("output2.txt");
	output<<S;
	output.close();

	system("pause");
	return 0;
}