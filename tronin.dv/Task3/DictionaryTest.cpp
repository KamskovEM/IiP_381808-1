#include <iostream>
#include <string>
#include <Windows.h>
#include "Dictionary.h"


void main()
{
	//setlocale(0, "");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string path;
	Dictionary d;
	std::string eword, rword, ans;

	//Сделать меню

	bool success = false;


	do {
		std::cout << "Введите имя существуещего файла или оставте это поле пустым, если хотите создать новый файл: ";
		std::getline(std::cin, path);
		if (path.empty())
		{
			std::cout << "Создается новый словарь" << std::endl;
			std::cout << "Введите его размер и буфер" << std::endl;
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
				Dictionary tmp(path);
				d = tmp;
				success = true;
			}
			catch (Exception e)
			{
				std::cout << "Файл " << path << "не найден" << std::endl;
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
		std::cout << "<5> Сохранить словарь" << std::endl;
		std::cout << "<6> Выйти без сохранения" << std::endl;
		std::cin >> answer;

		std::string EngWord, RusWord;

		switch (answer)
		{
		case 1:
			std::cout << "Введите слово: ";
			std::cin >> EngWord;
			if (!(RusWord = d.FindTranslation(EngWord)).empty())
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
			if (!path.empty())
			{
				remove(path.c_str());
				std::ofstream o(path);
				o << d;
				o.close();
			}
			else
			{
				std::cout << "Введите имя файла";
				std::cin >> path;
				std::ofstream o(path);
				o << d;
				o.close();
			}
			break;

		case 6:
			return;


		default:
			std::cout << "Неверный ввод. Повторите." << std::endl;
			break;
		}

	} while (!isExit);

	return;
}

	/*

	bool answer = true;

	do
	{
		std::cout << "Введите слово: ";
		std::cin >> eword;
		if (!(rword = d.FindTranslation(eword)).empty())
		{
			std::cout << "Перевод слова: " << rword;
			std::cout << "Хотите изменить перевод слова? [Y/N] ";
			std::cin >> ans;
			//std::cout << ans.compare("Y") + "";
			if (!ans.compare("Y")) //Функция "compare" возвращает 0, если строки совпадают 
			{
				std::cout << "Введите перевод: ";
				std::cin >> rword;
				//d.Change(eword, rword);
			}
		}
		else
		{
			std::cout << "Слово отсутствует в словаре. Хотите добавить его словарь? [Y/N] ";
			std::cin >> ans;
			if (!ans.compare("Y"))
			{
				std::cout << "Введите перевод: ";
				std::cin >> rword;
				//d.Set(eword, rword);
			}
		}
	} while (answer);
	//std::ifstream is("Test.txt");
}

*/