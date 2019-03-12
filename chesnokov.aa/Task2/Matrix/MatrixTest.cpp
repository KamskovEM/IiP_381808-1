#include "Matrix.h"

void DebugMsg(MatrixExept);

int main()
{
	// создаем 2 пустые матрицы
	Matrix mat(3), mat2(5);
	// и выводим их
	std::cout << "mat:\n" << mat << std::endl;
	std::cout << "mat2:\n" << mat2 << std::endl;
	// изменем первую
	mat(0, 0) = 4; mat(0, 1) = 2;  mat(0, 2) = 1;
	mat(1, 0) = 1; mat(1, 1) = 10; mat(1, 2) = 1;
	mat(2, 0) = 3; mat(2, 1) = 34; mat(2, 2) = 99;
	// выводим ее
	std::cout << "mat:\n" << mat << std::endl;
	// проверка конструктора копирования
	Matrix mat3 = mat;
	std::cout << "mat3:\n" << mat3 << std::endl;
	std::cout << "Size of mat3: " << mat3.GetSize() << std::endl;
	std::cout << "mat3 is diagonal dominant: " << mat3.DiagonalDom() << std::endl;
	// проверка на исклюения
	try
	{
		// выход за пределы 
		std::cout << mat(4, 4);
	}
	catch (MatrixExept me)
	{
		DebugMsg(me);
	}
	try
	{
		// сложение матриц разного размера
		std::cout << mat + mat2;
	}
	catch (MatrixExept me)
	{
		DebugMsg(me);
	}
	// изменяем размер mat2
	mat2.SetSize(3);
	mat2(0, 0) = 1; mat2(0, 1) = 22;  mat2(0, 2) = 11;
	mat2(1, 0) = 11; mat2(1, 1) = 1; mat2(1, 2) = 11;
	mat2(2, 0) = 22; mat2(2, 1) = 33; mat2(2, 2) = 2;
	std::cout << "mat2:\n" << mat2 << std::endl;
	std::cout << "mat2 is diagonal dominant: " << mat2.DiagonalDom() << std::endl;
	
	// проверка сложения
	std::cout << "mat + mat2:\n" << mat + mat2 << std::endl;

	// тестирование ввода
	Matrix mat4(2);
	std::cout << "Enter matrix:\n";
	std::cin >> mat4;
	std::cout << "mat4:\n" << mat4;
	char c;
	std::cin >> c;
	return 0;
}

void DebugMsg(MatrixExept me)
{
	switch (me.type)
	{
	case InvalidMath:
		std::cout << "ERROR! Math: " << me.text << std::endl;
		break;
	case OutOfRange:
		std::cout << "ERROR! Out of range: " << me.text << std::endl;
		break;
	default:
		std::cout << "ERROR! unknown";
		break;
	}
}