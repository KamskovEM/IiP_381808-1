#include <iostream>
#include "Matrix.h"
using namespace std;


int main() {
    int n1;
    cout << "Enter the size of the matrix: ";
    cin >> n1;
    Matrix M1(n1);
    cout << "Enter the matrix: " << endl;
    cin >> M1;

    int n2;
    cout << "Enter the size of the matrix: ";
    cin >> n2;
    Matrix M2(n2);
    cout << "Enter the matrix: " << endl;
    cin >> M2;

    Matrix Res(n1);
    Res = M1 + M2;

    cout << "Their summa: \n" << Res << endl;
    cout << "Size of the matrix: " << Res.getsize() << endl;
    cout << "Diagonal dominance: " << Res.diagdom() << endl;
    return 0;
}