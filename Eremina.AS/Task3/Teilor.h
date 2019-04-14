#pragma once
using namespace std;

class Teilor {
    string function;
    int length;
    string *items;
public:
    explicit Teilor(string func, int len);
    ~Teilor();
    string getfunction();
    int getlength();
    double getrow(double x);
    double deviation(double x);
    string operator[](int i);
    friend ostream& operator<<(ostream& stream, const Teilor& T);
};