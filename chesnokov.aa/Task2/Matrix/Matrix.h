#pragma once
#include <iostream>
/* Класс Matrix
 * квадрантная матрица целых чисел (от 2 до 8 строк/столбоц)
 * операции: задать/узнать размер матрицы, задать/узнать элемент по его индексам,
 * проверка на обладание диагональным преобладанием, суммирование
 */

class Matrix
{
private:  // -------------внутреннее представление----------------------------------
	int mSize;        // размер матрицы (2 - 8)
	int** mMatrix;    // внутреннее представление матрицы - двумерный массив

public:  //-----------------открытый интерфейс--------------------------------------
	// получить размер матрицы
	int GetSize() { return mSize; }
	// задаёт размеры матрицы, и возвращает успешно ли
	// допустимые размеры от 2 до 8
	bool SetSize(int size);
	// имеет ли диагональное преобладание?
	bool DiagonalDom();
public:  // -------------перегруженные операторы------------------------------------
	friend std::ostream& operator<< (std::ostream& out, const Matrix& matr);
	friend std::istream& operator>> (std::istream& in, Matrix& matr);
	int& operator() (int row, int column);
	Matrix operator+ (Matrix& m);
public:  // -------------конструкторы/деструктор------------------------------------
	Matrix(int size);
	Matrix(const Matrix& m);
	~Matrix();

private:
	// запрос памяти под двумерный динамический массив
	void InitializeMatrix();
	// освобождение памяти занятой массивом
	void Release();

};
// типы исключений
enum MatrixExeptType
{
	OutOfRange = 0,
	InvalidMath = 1
};

// структра исключения матриц
struct MatrixExept
{
	MatrixExeptType type;
	const char* text;
};