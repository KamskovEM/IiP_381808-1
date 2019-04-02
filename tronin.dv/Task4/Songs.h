﻿#pragma once
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
	Songs(const Songs& _c); //Констурктор копирования 
	~Songs();

	//Добавление записи в песенник
	void Add(const std::string& songTitle, const std::string& lyricsAuthor, const std::string& musicAuthor, const std::string& perfomer, Date releaseDate, const std::string& albumTitle = nullptr);
	void Add(const SongElement& _c);

	void Change(const std::string& songTitle); //Изменение данных песни, выбранной по названию

	void Find(std::ostream&, const std::string& songTitle); //Поиск композиции по названию

	void AllByPerfomer(std::ostream& stream, const std::string& perfomer) const; //Все композиции исполнителя 
	void AllByLyricsAuthor(std::ostream& stream, const std::string& lyricsAuthor) const; //Все композиции поэта 
	void AllByMusicAuthor(std::ostream& stream, const std::string& musicAuthor) const; //Все композиции композитора 

	void DeleteBySongTitle(const std::string& songTitle);

	int Count() const { return rlength; }

	SongElement& operator[](int index);

	friend std::ostream& operator<<(std::ostream&, const Songs& _c);
	friend std::istream& operator>>(std::istream&, Songs& _c);

};

enum Exeption {SongNotExist, OutOfRange};



