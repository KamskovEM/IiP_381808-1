#include <iostream>
#include <fstream>
#include <clocale>
#include "Decimal.h"
using namespace std;

Decimal::Decimal(int size) {
    length = size;
    number = new unsigned char[length];
}

Decimal::~Decimal() {
    length = 0;
    delete [] number;
}

Decimal& Decimal::operator=(const Decimal& D) {
    if (D.length > length) {
        length = D.length;
        delete [] number;
        number = new unsigned char [length];
    }
    int i = 0;
    while (D.number[i]) {
        number[i] = D.number[i];
        i++;
    }
    return *this;
}

Decimal Decimal::operator+(const Decimal& D) {
    int l = 0;
    if (length > D.length) {
        l = length;
    } else if (length < D.length) {
        l = D.length;
    } else {
        if (number[length-1] + D.number[D.length-1] > 9) {
            l = length + 1;
        } else {
            l = length;
        }
    }
    Decimal Res(l);
    int tmp = 0;
    for (int i = 0; i < Res.length; i++) {
        if (i < D.length) {
            Res.number[i] = (number[i] + D.number[i] + tmp) % 10;
            tmp = (number[i] + D.number[i] + tmp) / 10;
        } else {
            Res.number[i] = (number[i] + tmp) % 10;
            tmp = (number[i] + tmp) / 10;
        }
    }
    return Res;
}

Decimal Decimal::operator-(const Decimal& D) {
    Decimal Res(length);
    for (int i = 0; i < length; i++) {
        Res.number[i] = number[i];
    }

    if (length == D.length) {
        for (int i = 0; i < length; i++) {
            if (number[i] != D.number[i]) {
                break;
            } else if (i == length-1 && number[i] == D.number[i]) {
                Res.length = 1;
                Res.number[0] = 0;
            }
        }
    } else {
        for (int i = 0; i < Res.length; i++) {
            if (i < Res.length - 1) {
                Res.number[i + 1] -= 1;
                Res.number[i] += 10;
            }
            Res.number[i] -= D.number[i];
            if ((Res.number[i] / 10) > 0) {
                Res.number[i + 1] += 1;
                Res.number[i] %= 10;
            }
        }
        if (Res.number[length - 1] == 0) {
            Res.length = length - 1;
        }
    }
    return Res;
}

bool Decimal::operator>(const Decimal& D) {
    if (length > D.length) {
        return true;
    } else if (length < D.length) {
        return false;
    } else {
        int i = length;
        while (i >= 0) {
            if (number[i] > D.number[i]) {
                return true;
            } else if (number[i] < D.number[i]) {
                return false;
            } else {
                i -= 1;
            }
        }
        return false;
    }
}

bool Decimal::operator<(const Decimal& D) {
    if (length < D.length) {
        return true;
    } else if (length > D.length) {
        return false;
    } else {
        int i = length;
        while (i >= 0) {
            if (number[i] < D.number[i]) {
                return true;
            } else if (number[i] > D.number[i]) {
                return false;
            } else {
                i -= 1;
            }
        }
        return false;
    }
}

bool Decimal::operator>=(const Decimal& D) {
    if (length > D.length) {
        return true;
    } else if (length < D.length) {
        return false;
    } else {
        int i = length;
        while (i >= 0) {
            if (number[i] > D.number[i]) {
                return true;
            } else if (number[i] < D.number[i]) {
                return false;
            } else {
                i -= 1;
            }
        }
        return true;
    }
}

bool Decimal::operator<=(const Decimal& D) {
    if (length < D.length) {
        return true;
    } else if (length > D.length) {
        return false;
    } else {
        int i = length;
        while (i >= 0) {
            if (number[i] < D.number[i]) {
                return true;
            } else if (number[i] > D.number[i]) {
                return false;
            } else {
                i -= 1;
            }
        }
        return true;
    }
}

bool Decimal::operator==(const Decimal& D) {
    if (length == D.length) {
        int i = length;
        while (i >= 0) {
            if (number[i] != D.number[i]) {
                return false;
            } else {
                i -= 1;
            }
        }
        return true;
    } else {
        return false;
    }
}

bool Decimal::operator!=(const Decimal& D) {
    if (length == D.length) {
        int i = length;
        while (i >= 0) {
            if (number[i] != D.number[i]) {
                return true;
            } else {
                i -= 1;
            }
        }
        return false;
    } else {
        return true;
    }
}

ostream& operator<<(ostream& stream, const Decimal& D) {
    for (int i = D.length-1; i >= 0; i--) {
        stream << (int)D.number[i];
    }
    return stream;
}

istream& operator>>(istream& stream, Decimal& D) {
    char* str = new char[D.length+1];
    cin.ignore();
    stream.getline(str, D.length+1);
    for (int i = 0; i < D.length; i++) {
        D.number[D.length - i - 1] = str[i] - '0';
    }
    return stream;
}