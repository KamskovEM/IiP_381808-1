#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Phonebook.h"
#include "Contact.h"
using namespace std;

Phonebook::Phonebook() {
    size = 0;
    // Считаем кол-во строк в файле
    ifstream fin;
    fin.open("phonebook.csv");
    string s;
    while (!fin.eof()) {
        getline(fin, s);
        size++;
    } size--; // Вычитаем header
    fin.close();

    phonebook = new Contact[size];
    // Считываем данные из файла
    fin.open("phonebook.csv");
    int index = 0;
    while (!fin.eof()) {
        string str;
        string buf[8];
        getline(fin, str);
        if (str == "Фамилия,Имя,Отчество,Телефон,День Рождения,Избранный") continue;
        int i = 0, j = 0;
        while (i < str.length()) {
            if (str[i] != ',') {
                if (str[i] == ':') {
                    i++;
                    j++;
                }
                buf[j] += str[i];
            } else {
                j++;
            }
            i++;
        }
        bool el = false;
        if (buf[7] == "1") {
            el = true;
        }
        phonebook[index] = Contact(buf[0], buf[1], buf[2], stoull(buf[3].empty() ? "0" : buf[3]),
                                   static_cast<short>(stoi(buf[4].empty() ? "0" : buf[4])),
                                   static_cast<short>(stoi(buf[5].empty() ? "0" : buf[5])),
                                   static_cast<short>(stoi(buf[6].empty() ? "0" : buf[6])), el);
        index++;
    }
    fin.close();
};

Phonebook::~Phonebook() {
    ofstream fout;
    fout.open("phonebook.csv");
    int i = 0;
    fout << "Фамилия,Имя,Отчество,Телефон,День Рождения,Избранный" << endl;
    while(i < size) {
        if (i == size-1) {
            fout << phonebook[i];
        } else {
            fout << phonebook[i] << endl;
        }
        i++;
    }
    fout.close();
    delete[] phonebook;
}

void Phonebook::addcontact() {
    string s, n, p;
    cout << "Введите фамилию: ";
    cin >> s;
    cout << "Введите имя: ";
    cin >> n;
    cout << "Введите отчество: ";
    cin >> p;
    for (int i = 0; i < size; i++) {
        if (phonebook[i].findname(s, n, p)) {
            cout << "Такой контакт уже существует!" << endl;
            return;
        }
    }

    Contact* tmp;
    tmp = new Contact[size+1];
    for (int i = 0; i < size; i++) {
        tmp[i] = phonebook[i];
    }
    tmp[size-1] = Contact(s, n, p);
    delete[] phonebook;

    size++;
    phonebook = new Contact[size];
    for (int i = 0; i < size; i++) {
        phonebook[i] = tmp[i];
    }
    delete[] tmp;

    cout << "Контакт успешно создан.\n";
}

void Phonebook::edit() {
    string s, n, p;
    cout << "Введите фамилию: ";
    cin >> s;
    cout << "Введите имя: ";
    cin >> n;
    cout << "Введите отчество: ";
    cin >> p;
    int i = 0;
    while (i < size) {
        if (phonebook[i].findname(s, n, p)) {
            phonebook[i].edit();
            break;
        }
        i++;
    }
    if (i == size) {
        cout << "Контакт не найден.\n";
    }
}

void Phonebook::findname() {
    string s, n, p;
    cout << "Введите фамилию: ";
    cin >> s;
    cout << "Введите имя: ";
    cin >> n;
    cout << "Введите отчество: ";
    cin >> p;
    int i = 0;
    while (i < size) {
        if (phonebook[i].findname(s, n, p)) {
            cout << phonebook[i] << endl;
            break;
        }
        i++;
    }
    if (i == size) {
        cout << "Контакт не найден.\n";
    }
}

void Phonebook::findphone() {
    unsigned long long int phone;
    cout << "Введите номер: ";
    cin >> phone;
    int i = 0;
    while (i < size) {
        if (phonebook[i].findphone(phone)) {
            cout << phonebook[i] << endl;
            break;
        }
        i++;
    }
    if (i == size) {
        cout << "Контакт не найден.\n";
    }
}

void Phonebook::findletter() {
    char letter;
    cout << "Введите букву: ";
    cin >> letter;
    int i = 0;
    int count = 0;
    while (i < size) {
        if (phonebook[i].findletter(letter)) {
            cout << phonebook[i] << endl;
            count++;
        }
        i++;
    }
    if (i == size && count == 0) {
        cout << "Контакты не найдены.\n";
    }
}

void Phonebook::getcount() {
    cout << "Количество контактов: " << size << endl;
}

void Phonebook::addelected() {
    string s, n, p;
    cout << "Введите фамилию: ";
    cin >> s;
    cout << "Введите имя: ";
    cin >> n;
    cout << "Введите отчество: ";
    cin >> p;
    int i = 0;
    while (i < size) {
        if (phonebook[i].findname(s, n, p)) {
            phonebook[i].addelected();
            break;
        }
        i++;
    }
    if (i == size) {
        cout << "Контакт не найден.\n";
    }
}

void Phonebook::delelected() {
    string s, n, p;
    cout << "Введите фамилию: ";
    cin >> s;
    cout << "Введите имя: ";
    cin >> n;
    cout << "Введите отчество: ";
    cin >> p;
    int i = 0;
    while (i < size) {
        if (phonebook[i].findname(s, n, p)) {
            phonebook[i].delelected();
            break;
        }
        i++;
    }
    if (i == size) {
        cout << "Контакт не найден.\n";
    }
}

void Phonebook::showelected() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (phonebook[i].iselected()) {
            cout << phonebook[i] << endl;
            count++;
        }
    }
    if (count == 0) {
        cout << "Избранных контактов нет." << endl;
    }
}

void Phonebook::delcontact() {
    string s, n, p;
    cout << "Введите фамилию: ";
    cin >> s;
    cout << "Введите имя: ";
    cin >> n;
    cout << "Введите отчество: ";
    cin >> p;
    int i = 0;
    while (i < size) {
        if (phonebook[i].findname(s, n, p)) {
            for (int j = i; j < size-1; j++) {
                phonebook[j] = phonebook[j+1];
            }
            size--;
            break;
        }
        i++;
    }
    if (i == size) {
        cout << "Контакт не найден.\n";
    } else {
        cout << "Контакт успешно удалён!\n";
    }
}
