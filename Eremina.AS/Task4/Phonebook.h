#include <vector>
#include "Contact.h"
using namespace std;

class Phonebook {
    Contact *phonebook;
    int size;
public:
    Phonebook();
    ~Phonebook();
    void addcontact(); // Добавление контактов в телефонную книгу
    void edit();
    void findname(); // Имеет ли контакт ФИО s n p
    void findphone(); // Имеет ли контакт номер ph
    void findletter(); // Начинается ли фамилия контакта на букву letter
    void getcount();
    void addelected();
    void delelected();
    void showelected();
    void delcontact();
};