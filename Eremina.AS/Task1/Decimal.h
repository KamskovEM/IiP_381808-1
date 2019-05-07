#pragma once
using namespace std;

class Decimal {
    unsigned char* number;
    int length;
public:
    // Constructor
    Decimal(int size);
    // Destructor
    ~Decimal();
    // Operation overload
    Decimal& operator=(const Decimal& D);
    Decimal operator+(const Decimal& D);
    Decimal operator-(const Decimal& D);
    bool operator>(const Decimal& D);
    bool operator<(const Decimal& D);
    bool operator==(const Decimal& D);
    bool operator>=(const Decimal& D);
    bool operator<=(const Decimal& D);
    bool operator!=(const Decimal& D);
    friend ostream& operator<<(ostream& stream, const Decimal& D);
    friend istream& operator>>(istream& stream, Decimal& D);
};
