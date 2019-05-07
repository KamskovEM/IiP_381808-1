#include "Matrix.h"
#include <iomanip>

void Matrix::InitializeMatrix()
{
	mMatrix = new int*[mSize];
	for (int i = 0; i < mSize; i++)
	{
		mMatrix[i] = new int[mSize]();
	}
}

void Matrix::Release()
{
	for (int i = 0; i < mSize; i++)
	{
		if (mMatrix[i] != nullptr)
		delete[] mMatrix[i];
	}
	if (mMatrix != nullptr)
	delete[] mMatrix;

}

bool Matrix::SetSize(int size)
{
	// удаляем предыдущую матрицу
	Release();
	// проверка на корректный размер
	if (size < 2)
	{
		mSize = 2;
	}
	else if (size > 8)
	{
		mSize = 8;
	}
	else 
	{
		mSize = size;
	}
	
	// создаем новую
	InitializeMatrix();
	return (mSize == size);  // была создана матрица указанных размеров?
}

bool Matrix::DiagonalDom() const
{
	int sum = 0;
	for (int i = 0; i < mSize; i++)
	{
		sum = 0;
		for (int j = 0; j < mSize; j++)
		{
			if (i != j) sum += mMatrix[i][j];
		}
		if (mMatrix[i][i] < sum) return false;
	}
	return true;
}

Matrix & Matrix::operator=(const Matrix & matr)
{
	if (this != &matr)
	{
		Release();
		Matrix::Matrix(matr);
	}
	return *this;
}

int & Matrix::operator()(int row, int column)
{
	if ((row < 0) || (row > mSize) || (column < 0) || (column > mSize))
	{
		MatrixExept me;
		me.type = OutOfRange;
		me.text = "Out of matrix range";
		throw me;
	}
	return mMatrix[row][column];
}

Matrix Matrix::operator+(Matrix & m)
{
	if (mSize != m.GetSize())
	{
		MatrixExept me;
		me.type = InvalidMath;
		me.text = "Sum is defined only for matrix with the same size";
		throw me;
	}
	Matrix res(mSize);
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			res.mMatrix[i][j] = mMatrix[i][j] + m.mMatrix[i][j];
		}
	}
	return res;
}

Matrix::Matrix(int size = 2)
{
	mSize = size;
	InitializeMatrix();  // инициализация матрицы
}

Matrix::Matrix(const Matrix & m)
{
	mSize = m.mSize;
	InitializeMatrix();
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			mMatrix[i][j] = m.mMatrix[i][j];
		}
	}
}


Matrix::~Matrix()
{
	Release();
	mSize = 0;
	mMatrix = nullptr;
}

std::ostream & operator<<(std::ostream & out, const Matrix & matr)
{
	out << matr.GetSize() << std::endl;
	out << std::left;
	for (int i = 0; i < matr.GetSize(); i++)
	{
		for (int j = 0; j < matr.GetSize(); j++)
		{
			//out << matr.mMatrix[i][j] << " ";
			out << std::setw(5) << matr.mMatrix[i][j];
		}
		out << std::endl;
	}
	return out;
}

std::istream & operator>>(std::istream & in, Matrix & matr)
{
	// освобождаем предыдущую матрицу
	matr.Release();
	in >> matr.mSize;
	// заказ памяти под матрицу нового размера
	matr.InitializeMatrix();
	for (int i = 0; i < matr.mSize; i++)
	{
		for (int j = 0; j < matr.mSize; j++)
		{
			in >> matr(i, j);
		}
	}
	return in;
}
