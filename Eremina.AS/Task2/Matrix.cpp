#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int s) {
    size = s;
    items = new int* [size];
    for (int i = 0; i < size; i++){
        items[i] = new int [size];
    }
}

Matrix::Matrix(const Matrix & Mat) {
    size = Mat.size;
    items = new int*[size];
    for (int i = 0; i < size; i++) {
        items[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            items[i][j] = Mat.items[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < size; i++){
        delete[] items[i];
    }
    delete[] items;
    size = 0;
}

int Matrix::getsize() {
    return size;
}

int *Matrix::operator[](int index) {
    return items[index];
}

bool Matrix::diagdom() {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++){
            if (i != j) {
                sum += items[i][j];
            }
        }
        if (items[i][i] <= sum) {
            return false;
        }
    }
    return true;
}

Matrix Matrix::operator+(const Matrix& M) {
    Matrix Res(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Res.items[i][j] = items[i][j] + M.items[i][j];
        }
    }
    return Res;
}

Matrix &Matrix::operator=(const Matrix &M) {
    if (size != M.size) {
        size = M.size;
        for (int i = 0; i < size; i++){
            delete[] items[i];
        }
        delete[] items;
        items = new int* [size];
        for (int i = 0; i < size; i++){
            items[i] = new int [size];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            items[i][j] = M.items[i][j];
        }
    }
    return *this;
}

ostream &operator<<(ostream &stream, const Matrix &M) {
    for (int i = 0; i < M.size; i++) {
        for (int j = 0; j < M.size; j++) {
            stream << M.items[i][j] << " ";
        }
        stream << endl;
    }
    return stream;
}

istream &operator>>(istream &stream, Matrix &M) {
    for (int i = 0; i < M.size; i++){
        for (int j = 0; j < M.size; j++) {
            cin >> M.items[i][j];
        }
    }
    return stream;
}
