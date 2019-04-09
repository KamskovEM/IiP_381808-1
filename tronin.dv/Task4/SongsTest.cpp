#include <string>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Songs.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string path; //Имя файла
	Songs s;

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
			s = Songs(length, buf);
			success = true;
		}
		else
		{
			std::ifstream is(path);
			if (!is.fail())
			{
				s = Songs(is);
				success = true;
			}
			else
			{
				std::cout << "Файл " << path << " не найден" << std::endl;
			}
			is.close();
		}
	} while (!success);

	std::cout << "Песенник готов к работе" << std::endl;
	bool isExit = false;	//Истина, если выбран выход из программы,
							//если ложь, то будет снова показано меню

	do
	{
		int answer;

		std::cout << "<1> Добавить песню" << std::endl;
		std::cout << "<2> Изменить данные песни по названию (первой в списке)" << std::endl;
		std::cout << "<3> Найти песню по наванию и композитору" << std::endl;
		std::cout << "<4> Выдать все песни заданного поэта" << std::endl;
		std::cout << "<5> Выдать все песни заданного композитора" << std::endl;
		std::cout << "<6> Выдать все песни заданного исполнителя" << std::endl;
		std::cout << "<7> Число песен в песеннике" << std::endl;
		std::cout << "<8> Удалить песню по названию (первую в списке)" << std::endl;
		std::cout << "<9> Сохранить словарь" << std::endl;
		std::cout << "<10> Выйти без сохранения" << std::endl;
		std::cout << "Ваш выбор: ";
		std::cin >> answer;

		switch (answer)
		{
		case 1:
		{
			std::string songTitle, lyricsAuthor, musicAuthor, perfomer, albumTitle;
			std::cin.ignore();
			std::cout << "Введите название композиции: ";
			std::getline(std::cin, songTitle);
			std::cout << "Введите альбом (может быть пустым): ";
			std::getline(std::cin, albumTitle);
			std::cout << "Введите автора текста: ";
			std::getline(std::cin, lyricsAuthor);
			std::cout << "Введите автора музыки: ";
			std::getline(std::cin, musicAuthor);
			std::cout << "Введите исполнителя: ";
			std::getline(std::cin, perfomer);
			std::cout << "Введите дату выхода (дд мм гггг): ";
			int d, m, y;
			std::cin >> d >> m >> y;
			s.Add(songTitle, lyricsAuthor, musicAuthor, perfomer, d, m, y, albumTitle);
			break;
		}

		case 2:
		{			
			std::string songTitle;
			std::cout << "Введите название необходимой песни: ";
			std::cin.ignore();
			std::getline(std::cin, songTitle);
			if (s.Search(songTitle))
			{
				std::string lyricsAuthor, musicAuthor, perfomer, albumTitle;
				int d, m, y;
				std::cout << "Введите альбом (может быть пустым): ";
				std::getline(std::cin, albumTitle);
				std::cout << "Введите автора текста: ";
				std::getline(std::cin, lyricsAuthor);
				std::cout << "Введите автора музыки: ";
				std::getline(std::cin, musicAuthor);
				std::cout << "Введите исполнителя: ";
				std::getline(std::cin, perfomer);
				std::cout << "Введите дату выхода (дд мм гггг): ";
				std::cin >> d >> m >> y;
				s.Change(songTitle, lyricsAuthor, musicAuthor, perfomer, d, m, y, albumTitle);
			}
			else
			{
				std::cout << "Песня отсутвует в песеннике" << std::endl;
			}
			break;
		}

		case 3:
		{
			std::string songTitle, musicAuthor;
			std::cin.ignore();
			std::cout << "Введите название композиции: ";			
			std::getline(std::cin, songTitle);
			std::cout << "Введите автора музыки: ";
			std::getline(std::cin, musicAuthor);
			s.Find(std::cout, songTitle, musicAuthor);
			break;
		}

		case 4:
		{
			std::string lyricsAuthor;
			std::cout << "Введите имя поэта: ";
			std::cin.ignore();
			std::getline(std::cin, lyricsAuthor);
			s.AllByLyricsAuthor(std::cout, lyricsAuthor);
			break;
		}

		case 5:
		{
			std::string musicAuthor;
			std::cout << "Введите имя поэта: ";
			std::cin.ignore();
			std::getline(std::cin, musicAuthor);
			s.AllByMusicAuthor(std::cout, musicAuthor);
			break;
		}

		case 6:
		{
			std::string perfomer;
			std::cout << "Введите исполнителя: ";
			std::cin.ignore();
			std::getline(std::cin, perfomer);
			s.AllByPerfomer(std::cout, perfomer);
			break;
		}

		case 7:
		{
			std::cout << "Всего песен в песеннике: " << s.Count() << std::endl;
			break;
		}

		case 8:
		{
			std::string songTitle;
			std::cout << "Введите название необходимой песни: ";
			std::cin.ignore();
			std::getline(std::cin, songTitle);
			if (!s.DeleteBySongTitle(songTitle))
				std::cout << "Песня отсутвует в песеннике" << std::endl;
			else
				std::cout << "Удаление успешно" << std::endl;
			break;
		}

		case 9:
		{
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
				std::ofstream os(name);
				os << s;
				os.close();
			}
			else
			{
				std::cout << "Введите имя файла "; //... или оно запрашивается
				std::cin >> path;
				std::ofstream os(path);
				os << s;
				os.close();
			}
			break;
		}

		case 10:
			isExit = true;
			break;

		default:
			std::cout << "Неверный ввод. Повторите." << std::endl;
			break;
		}

	} while (!isExit);
	return;
}