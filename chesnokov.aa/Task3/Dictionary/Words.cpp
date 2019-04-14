#include "Words.h"



void Word::ChangeWord(const Word & word)
{
	// уничтожаем предыдущее слово 
	Release();
	// конструируем новое
	int i;
	for (i = 0; i < word.mLen; i++) {} // вычисляем длину слова
	mLen = i;
	mWord = new char[mLen + 1]();
	// копируем символы
	for (i = 0; word.mWord[i] != '\0'; i++)
	{
		mWord[i] = word.mWord[i];
	}
	mWord[i] = '\0';
}

void Word::ChangeWord(const char * word)
{
	// уничтожаем предыдущее слово
	Release();
	// конструируем новое
	int i;
	for (i = 0; word[i] != '\0'; i++) {} // вычисляем длину слова
	mLen = i;
	mWord = new char[mLen + 1]();
	// копируем символы
	for (i = 0; word[i] != '\0'; i++)
	{
		mWord[i] = word[i];
	}
	mWord[i] = '\0';
}

bool Word::operator==(const Word & word) const
{
	if (mLen != word.mLen)
	return false;
	for (int i = 0; i < mLen; i++)
	{
		if (mWord[i] != word.mWord[i]) return false;
	}
	return true;
}

bool Word::operator!=(const Word & word) const
{
	return !(*this == word);
}

const char * Word::ToCStr()
{
	return mWord;
}

void Word::Release()
{
	if (mWord != nullptr) 
	{
		delete[] mWord;
		mWord = nullptr;
	}
}

Word::Word()
{
	// создает пустое слово
	mLen = 0;
	mWord = new char[mLen + 1];
	mWord[0] = '\0';
}

Word::Word(const char * word)
{
	int i;
	for (i = 0; word[i] != '\0'; i++) {} // вычисляем длину слова
	mLen = i;
	mWord = new char[mLen + 1]();
	// копируем символы
	for (i = 0; word[i] != '\0'; i++)
	{
		mWord[i] = word[i];
	}
	mWord[i] = '\0';
}

Word::Word(const Word & word)
{
	int i;
	for (i = 0; i < word.mLen; i++) {} // вычисляем длину слова
	mLen = i;
	mWord = new char[mLen + 1]();
	// копируем символы
	for (i = 0; word.mWord[i] != '\0'; i++)
	{
		mWord[i] = word.mWord[i];
	}
	mWord[i] = '\0';
}

Word::~Word()
{
	Release();
	mWord = nullptr;
	mLen = 0;
}

PairWord::PairWord() : first(), second()
{
}

PairWord::PairWord(const Word & firstWord, const Word & secondWord) : first(firstWord), second(secondWord)
{
}

PairWord::~PairWord()
{
}