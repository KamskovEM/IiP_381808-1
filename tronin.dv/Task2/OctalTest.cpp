#include <iostream>
#include <cstring>
#include <locale>
#include <fstream>
#include "Octal.h"


void main()
{
	setlocale(0, "");

	Octal a, b;

	std::cout << "Введите первое число и второе: ";
	std::cin >> a >> b;
	std::cout << "1е: " << a << " 2е: " << b << std::endl;
	if (a == b) std::cout << "Числа равны" << std::endl;
	else
		if (a > b) std::cout << "Первое больше второго" << std::endl;
		else
			std::cout << "Второе больше первого" << std::endl;	
	std::cout << "Их сумма равна: " << a + b << std::endl;
	std::cout << "Разность первого и второго: " << a - b; 
	std::cout << ", второго и первого: " << b - a << std::endl;
	std::cout << "Их произведение: " << a * b << std::endl;
	a = b;
	std::cout << "Первое число, после присваивания ему второго " << a << std::endl; 
	std::string str = "1523";
	a = str; //Проверка присваивания строки 
	std::cout << "Число, после присваивания строки " << a << std::endl;


	std::ofstream os("Test.txt");
	os << a << " " << b; //Запись в файл
	os.close();
	std::ifstream is("Test.txt"); //Чтение из файла
	is >> b  >> a;
	std::cout << "Прочитано из файла: " << a << " " << b << std::endl;
	std::cout << "Длина первого: " << a.GetLength() << std::endl;
}

/*
Пример вывода

Введите первое число и второе: 1000 1
1е: 1000 2е: 1
Первое больше второго
Их сумма равна: 1001
Разность первого и второго: 0777, второго и первого: 7001
Их произведение: 1000
Первое число, после присваивания ему второго 1
Число, после присваивания строки 1523
Прочитано из файла: 1 1523
Длина первого: 1

*/