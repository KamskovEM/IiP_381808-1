#include <iostream>
#include <fstream>
#include <cstdbool>
#include "Decimal.h"
using namespace std;

int main() {
    int n;
    cout << "Enter the length of the first number: ";
    cin >> n;
    Decimal Dec1(n);
    cout << "Enter the first number: ";
    cin >> Dec1;

    int m;
    cout << "Enter the length of the second number: ";
    cin >> m;
    Decimal Dec2(m);
    cout << "Enter the second number: ";
    cin >> Dec2;

    Decimal Dec3(n);

    Dec3 = Dec1 + Dec2;
    cout << "Their sum: " << Dec3 << endl;

    Dec3 = Dec1 - Dec2;
    cout << "Their difference: " << Dec3 << endl;

    cout << "First > Second? ";
    if (Dec1 > Dec2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "First < Second? ";
    if (Dec1 < Dec2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "First >= Second? ";
    if (Dec1 >= Dec2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "First <= Second? ";
    if (Dec1 <= Dec2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "First == Second? ";
    if (Dec1 == Dec2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "First != Second? ";
    if (Dec1 != Dec2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}