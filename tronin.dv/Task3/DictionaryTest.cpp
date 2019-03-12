#include <iostream>
#include <string>
#include <Windows.h>
#include "Dictionary.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string path; //Имя файла
	Dictionary d;

	bool success = false; //Переменная успешной загрузки базы или ее создания

	do {
		std::cout << "Введите имя существуещего файла или оставте это поле пустым, если хотите создать новый файл: ";
		std::getline(std::cin, path);
		if (path.empty()) //Проверяем имя на пустоту
		{
			std::cout << "Создается новый словарь" << std::endl;
			std::cout << "Введите его размер и буфер (>0)" << std::endl;
			int length, buf;
			std::cin >> length >> buf;
			Dictionary tmp(length, buf);
			d = tmp;
			success = true;
		}
		else
		{
			try
			{
				Dictionary tmp(path); //Используется буфер по умолчанию, но можно отдлеьно задать свой 
				d = tmp;
				success = true;
			}
			catch (ExceptionType e)
			{
				if (e == FileNotFound)
				{
					std::cout << "Файл " << path << " не найден" << std::endl;
				}
				else
				{
					std::cout << "Произошла непредвиденная ошибка. Завершение работы." << std::endl;
					exit(1);
				}
			}
		}
	} while (!success);
	std::cout << "Словарь готов к работе" << std::endl;
	bool isExit = false;	//Истина, если выбран выход из программы,
							//если ложь, то будет снова показано меню
	do
	{
		int answer;

		std::cout << "<1> Посмотреть перевод слова" << std::endl;
		std::cout << "<2> Посмотреть наличие слова в словаре" << std::endl;
		std::cout << "<3> Изменить перевод слова" << std::endl;
		std::cout << "<4> Добавить пару" << std::endl;
		std::cout << "<5> Число слов в словаре" << std::endl;
		std::cout << "<6> Вывести весь словарь" << std::endl;
		std::cout << "<7> Сохранить словарь" << std::endl;
		std::cout << "<8> Выйти без сохранения" << std::endl;
		std::cout << "Ваш выбор: ";
		std::cin >> answer;

		std::string EngWord, RusWord;

		switch (answer)
		{
		case 1:
			std::cout << "Введите слово: ";
			std::cin >> EngWord;
			if (!(RusWord = d.FindTranslation(EngWord)).empty()) //Запрашиваем перевод, сразу его присваиваем (чтобы не прохождить по массиву дважды) и проверяем на пустоту
			{
				std::cout << "Перевод слова: " << RusWord << std::endl;
			}
			else
			{
				std::cout << "Слово отсутствует в словаре." << std::endl;
			}
			break;

		case 2:
			std::cout << "Введите слово: ";
			std::cin >> EngWord;
			if (!(d.FindTranslation(EngWord)).empty())std::cout << "Слово есть в словаре" << std::endl;
			else std::cout << "Слово отсутствует в словаре" << std::endl;
			break;

		case 3:
			std::cout << "Введите слово: ";
			std::cin >> EngWord;
			if (!(d.FindTranslation(EngWord)).empty())
			{
				std::cout << "Введите новый перевод: ";
				std::cin >> RusWord;
				d.ChangeTranslation(EngWord, RusWord);
			}
			else
			{
				std::cout << "Слово отсутствует в словаре." << std::endl;
			}
			break;

		case 4:
			std::cout << "Введите слово: ";
			std::cin >> EngWord;
			std::cout << "Введите новый перевод: ";
			std::cin >> RusWord;
			d.Add(EngWord, RusWord);
			break;

		case 5:
			std::cout << "Всего слов в словаре: " << d.GetRLength() << std::endl;
			break;

		case 6:
			std::cout << "Словарь " << path << std::endl;
			std::cout << d;
			break;

		case 7:
			if (!path.empty()) //Используется тоже имя, что было введено в начале работы программы ...
			{
				std::string name;
				std::cout << "Если хотите сохранить с другим именем (оставьте пустым, если сохранить с тем же именем): ";
				std::cin.ignore();
				std::getline(std::cin, name);
				if (name.empty()) //Если оставили пустым, то удаляем предыдущий файл	
				{
					remove(path.c_str());
					name = path;
				}		
				std::ofstream o(name);
				o << d;
				o.close();
			}
			else 
			{
				std::cout << "Введите имя файла "; //... или оно запрашивается
				std::cin >> path;
				std::ofstream o(path);
				o << d;
				o.close();
			}
			break;

		case 8:
			return;


		default:
			std::cout << "Неверный ввод. Повторите." << std::endl;
			break;
		}

	} while (!isExit);
}

/*
Пример вывода (меню убрано, для краткости, в скобках к каждому выбрану пунку его название в меню)

Введите имя существуещего файла или оставте это поле пустым, если хотите создать новый файл: Test.txt
Словарь готов к работе

Ваш выбор: 4 (<4> Добавить пару)
Введите слово: Phone
Введите новый перевод: Телефон

Ваш выбор: 3 (<3> Изменить перевод слова)
Введите слово: Button
Введите новый перевод: Пуговица

Ваш выбор: 1 (<1> Посмотреть перевод слова)
Введите слово: Cat
Перевод слова: Кошка

Ваш выбор: 2 (<2> Посмотреть наличие слова в словаре)
Введите слово: Plant
Слово есть в словаре

Ваш выбор: 6 (<6> Вывести весь словарь)
Словарь Test.txt
7
Cat Кошка
Dog Собака
Plant Растение
Button Пуговицы
Mouse Мышь
Window Окно
Phone Телефон

Ваш выбор: 5 (<5> Число слов в словаре)
Всего слов в словаре: 7

Ваш выбор: 7 (<7> Сохранить словарь)
Если хотите сохранить с другим именем (оставьте пустым, если сохранить с тем же именем):
Test_1.txt

*/