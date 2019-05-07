#include <iostream>
#include <cmath>
#include "Teilor.h"
using namespace std;

int factorial(int i);

Teilor::Teilor(string func, int len) {
    function = move(func);
    length = len;
    items = new string [length];
    if (function == "exp") {
        for (int i = 0; i < length; i++) {
            items[i] = "x^" + to_string(i) + "/" + to_string(i) + "!";
        }
    } else if (function == "sin") {
        for (int i = 1; i < length+1; i++) {
            items[i-1] = to_string(int(pow(-1, i+1))) + "*x^" + to_string(2*i-1) + "/" + to_string(2*i-1) + "!";
        }
    } else if (function == "cos") {
        for (int i = 0; i < length; i++) {
            items[i] = to_string(int(pow(-1, i))) + "*x^" + to_string(2*i) + "/" + to_string(2*i) + "!";
        }
    }
}

Teilor::~Teilor() {
    function = "";
    length = 0;
}

string Teilor::getfunction() {
    return function;
}

int Teilor::getlength() {
    return length;
}

string Teilor::operator[] (int i) {
    return items[i];
}

double Teilor::getrow(double x) {
    double n = 0;
    if (function == "exp") {
        for (int i = 0; i < length; i++) {
            n += pow(x, i) / factorial(i);
        }
        return n;
    } else if (function == "sin") {
        for (int i = 1; i < length+1; i++) {
            n = int(pow(-1, i + 1)) * pow(x, 2 * i - 1) / factorial(2 * i - 1);
        }
        return n;
    } else if (function == "cos") {
        for (int i = 0; i < length; i++) {
            n = int(pow(-1, i)) * pow(x, 2 * i) / factorial(2 * i);
        }
        return n;
    } else
        return -1;
}

ostream& operator<<(ostream& stream, const Teilor& T) {
    string formula;
    for (int i = 0; i < T.length - 1; i++) {
        formula += T.items[i] + " + ";
    }
    formula += T.items[T.length - 1];
    stream << formula;
    return stream;
}

int factorial(int i) {
    if (i == 1 or i == 0) {
        return 1;
    } else {
        return i*factorial(i-1);
    }
}

double Teilor::deviation(double x) {
    if (function == "exp") {
        return abs(exp(x) - this->getrow(x));
    } else if (function == "sin") {
        return abs(sin(x) - this->getrow(x));
    } else if (function == "cos") {
        return abs(cos(x) - this->getrow(x));
    }
    return -1;
}
