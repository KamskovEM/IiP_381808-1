#include <iostream>
#include <cmath>
#include "Teilor.h"
using namespace std;

int main() {
    Teilor T("cos", 5);
    cout << T.getfunction() << endl;
    cout << T.getlength() << endl;
    cout << T << endl;
    cout << T[1] << endl;
    cout << T.getrow(3) << endl;
    cout << T.deviation(3) << endl;
    return 0;
}