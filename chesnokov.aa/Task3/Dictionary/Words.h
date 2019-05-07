#pragma once
// вспомогательные классы для словаря

// класс представляющий слово
class Word
{
private://----------внтуреннее представление------
	// динамический массив символов
	char* mWord;
	// длина массива
	int mLen;
public:
	// изменить слово
	void ChangeWord(const Word& word);
	void ChangeWord(const char* word);
	bool operator==(const Word& word) const;
	bool operator!=(const Word& word) const;
	// перевести в си-строку
	const char* ToCStr();
private://---------закрытый интерфейс-------------
	// освобождение занимаемой памяти
	void Release();
public:
	// конструктор по уолчанию
	Word();
	//конструкторы копирования
	Word(const char* word);
	Word(const Word& word);
	// деструктор
	~Word();
};

// класс для представления пары слов
class PairWord
{
public:
	Word first;   // первое слово в паре
	Word second;  // второе слово в паре
public:
	PairWord();   // конструктор по умолчанию
	PairWord(const Word& firtsWord, const Word& secondWord);   // конструктор инициализатор
	~PairWord();   // деструктор
};