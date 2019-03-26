#include "Contact.h"
#include <string>
#include <iostream>

using namespace std;

Contact::Contact() {
    fullname.surname = "";
    fullname.name = "";
    fullname.patronymic = "";
    phone = 0;
    birthday.day = 0;
    birthday.month = 0;
    birthday.year = 0;
    elected = false;
}

Contact::Contact(string s, string n, string p) {
    fullname.surname = s;
    fullname.name = n;
    fullname.patronymic = p;
    phone = 0;
    birthday.day = 0;
    birthday.month = 0;
    birthday.year = 0;
    elected = false;
}

Contact::Contact(string s, string n, string p, unsigned long long ph, short d, short m, short y, bool el) {
    fullname.surname = s;
    fullname.name = n;
    fullname.patronymic = p;
    phone = ph;
    birthday.day = d;
    birthday.month = m;
    birthday.year = y;
    elected = el;
}

Contact::~Contact() {
    fullname.surname = "";
    fullname.name = "";
    fullname.patronymic = "";
    phone = 0;
    birthday.day = 0;
    birthday.month = 0;
    birthday.year = 0;
    elected = false;
}

void Contact::edit() {
    for(;;) {
        cout << "Что вы хотите изменить?\n"
                "1 - Фамилию\n"
                "2 - Имя\n"
                "3 - Отчество\n"
                "4 - Номер телефона\n"
                "5 - Дату рождения\n"
                "0 - Выход\n"
                ">>> ";
        int point;
        cin >> point;
        if (point == 1) {
            cout << "Введите новую фамилию: ";
            cin >> this->fullname.surname;
        } else if (point == 2) {
            cout << "Введите новое имя: ";
            cin >> this->fullname.name;
        } else if (point == 3) {
            cout << "Введите новое отчество: ";
            cin >> this->fullname.patronymic;
        } else if (point == 4) {
            cout << "Введите новый номер телефона: ";
            cin >> this->phone;
        } else if (point == 5) {
            cout << "Введите новую дату рождения в формате ДД ММ ГГГГ: ";
            cin >> this->birthday.day >> this->birthday.month >> this->birthday.year;
        } else if (point == 0) {
            return;
        }
        string p;
        cout << "Продолжить редактирование? (Д/Н): ";
        cin >> p;
        if (p == "Д") continue; else break;
    }
    cout << "Контакт успешно изменён!\n";
}

bool Contact::findname(string s, string n, string p) {
    return fullname.surname == s && fullname.name == n && fullname.patronymic == p;
}

bool Contact::findphone(unsigned long long int ph) {
    return phone == ph;
}

bool Contact::findletter(char letter) {
    return fullname.surname[0] == letter;
}

bool Contact::iselected() {
    return elected;
}

void Contact::addelected() {
    if (elected) {
        cout << "Контакт уже в избранный.\n";
    } else {
        elected = !elected;
        cout << "Контакт успешно добавлен в избранные.\n";
    }
}

void Contact::delelected() {
    if (!elected) {
        cout << "Контакт уже не в избранный.\n";
    } else {
        elected = !elected;
        cout << "Контакт успешно удалён из избранных.\n";
    }
}

ostream &operator<<(ostream& stream, const Contact& C) {
    stream << C.fullname.surname << "," << C.fullname.name << "," << C.fullname.patronymic << ","
           << C.phone << "," << C.birthday.day << ":" << C.birthday.month << ":" << C.birthday.year << ","
           << C.elected;
    return stream;
}