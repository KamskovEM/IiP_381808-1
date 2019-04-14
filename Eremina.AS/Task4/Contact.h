#pragma once

#include <string>

using namespace std;

class Contact {
    struct {
        string surname;
        string name;
        string patronymic;
    } fullname;
    unsigned long long phone;
    struct {
        short day;
        short month;
        short year;
    } birthday;
    bool elected;
public:
    Contact();
    Contact(string s, string n, string p); // Конструктор инициализации
    Contact(string s, string n, string p, unsigned long long ph, short d, short m, short y, bool el); // Констуктор для копирования из файла
    ~Contact(); // Деструктор
    void edit(); // Редактирование
    bool findname(string s, string n, string p); // Имеет ли контакт ФИО s n p
    bool findphone(unsigned long long int ph); // Имеет ли контакт номер ph
    bool findletter(char letter); // Начинается ли фамилия контакта на букву letter
    bool iselected();
    void addelected(); // Добавить контакт в избранные
    void delelected(); // Удалить контакт из избранных
    friend ostream&operator<<(ostream& stream, const Contact&); // Вывод
};
