#include <iostream>
#include <clocale>
#include "Calendar.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Calendar cal(30);	// Sozdaiom kalendar
	cal.add(2, 9, 1945, "Конец Второй мировой войны");			// Dobavlaem sobitie
	cout << cal << endl;										// Vivodim calendar
	cout << cal.getDate("Конец Второй мировой войны") << endl;	// Vivodim daty opredelennogo sobitiya
	cout << cal.getDifference(17, 03, 2019, "Конец Второй мировой войны");	// Vivodim raznicy megdy datoi i sobitiem
	cal.dateShift("Начало Второй мировой войны", 2192);			// Sdvigem sobitie
	cout << cal << endl;
	getchar();
	return 0;
}