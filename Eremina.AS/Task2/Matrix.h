#pragma once
using namespace std;

class Matrix {
    int size;
    int** items;
public:
    // Constructors
    explicit Matrix(int s);
    Matrix(const Matrix& Mat);
    ~Matrix(); // Destructor
    int getsize();
    int *operator[] (int index);
    bool diagdom(); // Diagonal dominance
    Matrix operator+(const Matrix& M);
    Matrix &operator=(const Matrix& M);
    friend ostream& operator<<(ostream& stream, const Matrix& M);
    friend istream& operator>>(istream& stream, Matrix& M);
};