#include <iostream>
#include "Time.h"


int main()
{
	//proverka konstruktorov:
	Time time0; //konstruktor po ymolchaniuy
	cout << time0 << endl; 
	int a, b, c;
	cout << "vvedite kolichestvo chasov minut i sekund v time1:" << endl;
	cout << "chasov - "; cin >> a;
	cout << "minut - "; cin >> b;
	cout << "secund - "; cin >> c;
	Time time1 = Time(a, b, c); // konstruktor inicializacii
	Time timetest = Time(1, 30, 30);
	time1.Check(time1); // proverka dannih
	cout << "time1 - " << time1 << endl;
	Time time2(timetest); // konstruktor kopirovaniya
	cout << "time2(test konstruktora kopirovaniya) - " << time2 << endl;
	string vremya;
	cout << "vvedite tochnoe vremya time3 cherez ':'" << endl;
	cin >> vremya;
	Time time3 = Time(vremya); // konstruktor pr.tipa iz stroki
	cout << "time3 - " << time3 << endl;
	Time time4("12.24.35"); // konstruktor pr.tipa iz stroki
	cout << "time4(test konstruktora pr.tipa) - " << time4 << endl;

	cout << time1 << " + " << timetest << " = " << time1 + timetest << endl; // slojenie vremeni 'time1' i 'timetest'
	cout << time1 << " - " << timetest << " = " << time1 - timetest << endl; // slojenie vremeni 'time1' i 'timetest'

	if (time1 > time2 && time1 != time2) // operatori sravneniya
	{
		cout << time1 << " > " << time2 << endl;
	}
	else 
	{
		if (time1 != time2) 
		{
			cout << time1 << " < " << time2 << endl;
		}
		else cout << time1 << " = " << time2 << endl;
	}
	getchar();
	getchar();
	return 0;
}