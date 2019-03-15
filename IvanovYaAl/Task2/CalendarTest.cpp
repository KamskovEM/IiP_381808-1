#include "Calendar.h"

int main() {
	Calendar Time[30];
	ifstream is;
	is.open("Calendar.txt");
	for (int i = 0; i < 30; i++) {
		is >> Time[i];
	}
	for (int i = 0; i < 30; i++) {
		std::cout << i + 1 << ". " << Time[i] << endl;
	}
NewEvent:
	std::cout << "Hotite vvesti sobitie?\n Y(YES) or N(NO) " << endl;
	char ui;
	std::cin >> ui;
	if (ui == 'Y') {
		std::cout << "Vvedite nomer sobitiya kotoroe hotite vvesti (1-30): " << endl;
		int num;
		std::cin >> num;
		std::cout << "Vvedite sobitie ¹ " << num << endl;
		std::cin >> Time[num - 1];
		goto NewEvent;
	}
NewChange:
	std::cout << "Hotite izmenit' sobitie?\n Y(YES) or N(NO) " << endl;
	std::cin >> ui;
	if (ui == 'Y') {
		std::cout << "Choose change event(i) and choose replacement event(j)" << endl;
		std::cout << " i = ";
		int first, second;
		std::cin >> first;
		first--;
		std::cout << endl << " j = ";
		std::cin >> second;
		second--;
		Time[second] = Time[first] ^ Time[second];
		goto NewChange;
	}
	for (int i = 0; i < 30; i++) {
		std::cout << i + 1 << ". " << Time[i] << endl;
	}
	std::cout << "Enter event which u want find: " << endl;
	string search;
	std::cin >> search;
	for (int i = 0; i < 30; i++) {
		if (search == Time[i].event) {
			std::cout << Time[i] << endl;
		}
	}
	ofstream Vivod("Calendar.txt");
	for (int i = 0; i < 30; i++) {
		Vivod << Time[i] << endl;
	}
	Vivod.close();
	std::system("pause");
	return 0;
}

