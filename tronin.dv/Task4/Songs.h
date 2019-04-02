#pragma once
#include "SongElement.h"

class Songs
{
private:
	int length; //Длина массива
	int rlength; //реальная длина массива
	int buf; //Буфер для добадвения новых элементов 
	SongElement* base;


public:
	Songs(); //Конструктор по-умолчанию
	Songs(int count, int buf = 10); //Констурктор инициализатор
	Songs(std::istream& stream, int buf = 10); //Конструктор инициализатор из потока
	Songs(const Songs& _c); //Констурктор копирования 
	~Songs();

	//Добавление записи в песенник
	void Add(const std::string& songTitle, const std::string& lyricsAuthor, const std::string& musicAuthor, const std::string& perfomer, const Date &releaseDate, const std::string& albumTitle = nullptr);
	void Add(const SongElement& _c);

	bool Change(const std::string& songTitle, const std::string& lyricsAuthor, const std::string& musicAuthor, const std::string& perfomer, const Date &releaseDate, const std::string& albumTitle = nullptr); //Изменение данных песни, выбранной по названию

	void Find(std::ostream&, const std::string& songTitle, const std::string &perfomer); //Поиск композиции по названию и композитору

	void AllByPerfomer(std::ostream& stream, const std::string& perfomer) const; //Все композиции исполнителя 
	void AllByLyricsAuthor(std::ostream& stream, const std::string& lyricsAuthor) const; //Все композиции поэта 
	void AllByMusicAuthor(std::ostream& stream, const std::string& musicAuthor) const; //Все композиции композитора 

	bool DeleteBySongTitle(const std::string& songTitle);

	int Count() const { return rlength; }

	SongElement& operator[](int index);

	friend std::ostream& operator<<(std::ostream&, const Songs& _c);
	friend std::istream& operator>>(std::istream&, Songs& _c);

};

enum Exeption {OutOfRange};



