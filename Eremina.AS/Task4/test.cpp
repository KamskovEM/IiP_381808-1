#include <iostream>
#include <fstream>
#include "Phonebook.h"
#include "Contact.h"
using namespace std;

int main() {
    Phonebook ph;
    cout << "=========================\n"
           "Что вы хотите сделать?\n"
           "1 - Создать новый контакт\n"
           "2 - Изменить выбранный контакт\n"
           "3 - Найти контакт по ФИО\n"
           "4 - Найти контакт по телефону\n"
           "5 - Выдать все контакты на заданную букву\n"
           "6 - Узнать текущее число контактов\n"
           "7 - Внести контакт в список избранных\n"
           "8 - Удалить контакт из списка избранных\n"
           "9 - Выдать все избранные контакты\n"
           "10 - Удалить контакт\n"
           "0 - Выход\n";
    for(;;) {
        bool exit = false;
        int point = 0;
        cout << ">>> ";
        cin >> point;
        switch (point) {
            case 1: ph.addcontact(); break;
            case 2: ph.edit(); break;
            case 3: ph.findname(); break;
            case 4: ph.findphone(); break;
            case 5: ph.findletter(); break;
            case 6: ph.getcount(); break;
            case 7: ph.addelected(); break;
            case 8: ph.delelected(); break;
            case 9: ph.showelected(); break;
            case 10: ph.delcontact(); break;
            case 0: exit = true; break;
            default: cout << "Ошибка! Повторите ввод." << endl;
        }
        if (exit) break;
    }
    return 0;
}