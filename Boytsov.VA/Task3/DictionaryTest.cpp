#include "Dictionary.h"
#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	// Чтение из потока
	ifstream is;
	is.open("Words1.txt"); // файл для чтения
	Dictionary Dict1(is);
	is.close();
	is.open("Words2.txt"); // файл для чтения
	Dictionary Dict2(is);
	is.close();
	is.open("output.txt"); // файл для чтения
	Dictionary DictTogether(is);
	is.close();
	DictTogether = Dict2;
	cout << "Содержимое словаря DictTogether, после присваивания ему Dict2: " << endl;
	cout << DictTogether << endl;
	Dict1 +=  Dict2;
	cout << "Содержимое словаря Dict1, после слияния с Dict2: " << endl;
	cout << Dict1 << endl;
	int Answer;
	string Word, Translation;
	do
	{
		cout << "Введите цифру действия, которое хотите выполнить: " << endl;
		cout << "1 - Добавить в словарь слово и его перевод" << endl;
		cout << "2 - Изменить перевод указанного слова" << endl;
		cout << "3 - Узнать перевод выбранного слова" << endl;
		cout << "4 - Проверить наличие слова в словаре" << endl;
		cout << "5 - Узнать число слов в словаре" << endl;
		cout << "6 - Сохрать словарь" << endl;
		cout << "0 - Выход из программы" << endl;
		cin >> Answer;

		switch (Answer)
		{
		case 1:
			cout << "Введите слово на английском языке" << endl;
			cin.ignore(32767, '\n');
			getline(cin, Word);
			cout << "Введите перевод этого слова" << endl;
			getline(cin, Translation);
			Dict1.AddWords(Word, Translation);
			break;
		case 2:
			cout << "Введите слово, перевод которого хотите изменить" << endl;
			cin.ignore(32767, '\n');
			getline(cin, Word);
			cout << "Введите перевод данного слова" << endl;
			getline(cin, Translation);
			Dict1.EditTranslation(Word, Translation);
			break;
		case 3:
			cout << "Введите слово, перевод которого вы хотите узнать" << endl;
			cin.ignore(32767, '\n');
			getline(cin, Word);
			Dict1.LearnTranslation(Word);
			break;
		case 4:
			cout << "Введите слово, наличие которого хотите проверить" << endl;
			cin.ignore(32767, '\n');
			getline(cin, Word);
			Dict1.CheckWord(Word);
			break;
		case 5:
			Dict1.NumberWords();
			break;
		case 6:
			Dict1.FilePreparation("Words1.txt");
			break;
		case 0:
			return;
		default:
			break;
		}
	} while (Answer >=0 && Answer <=6);
}