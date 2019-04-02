#pragma once
#include "SongElement.h"
#include <string>

struct Date
{
	unsigned char day;
	unsigned char month;
	unsigned int year;

	Date(unsigned char day, unsigned char month, unsigned int year)
		: day(day), month(month), year(year) {}

	friend std::ostream& operator<<(std::ostream& stream, const Date& _c);
	friend std::istream& operator>>(std::istream& stream, Date& _c);
};

class SongElement
{
private:
	Date releaseDate; // Дата выпуска
	std::string songTitle; // Название песни 
	std::string lyricsAuthor; // Автор слов
	std::string musicAuthor; // Автор мелодии
	std::string perfomer; // Исполнитель
	std::string albumTitle; // Навание альбома
	
public:
	SongElement();// Конструктор по-умолчанию
	SongElement(const std::string& songTitle, const std::string& lyricsAuthor, const std::string& musicAuthor, const std::string& perfomer, Date releaseDate, const std::string& albumTitle = nullptr); // Конструктор инициализации (поле "название альбома" по умолчанию пустое)
	~SongElement();

	//Геттеры и сеттеры
	std::string getSongTitle() const { return songTitle; }
	void setSongTitle(const std::string& _c) { songTitle = _c; }

	std::string getLyricsAuthor() const { return lyricsAuthor; }
	void setLyricsAuthor(const std::string& _c) { lyricsAuthor = _c; }

	std::string getMusicAuthor() const { return musicAuthor; }
	void setMusicAuthor(const std::string& _c) { musicAuthor = _c; }

	std::string getPerfomer() const { return perfomer; }
	void setPerfomer(const std::string& _c) { perfomer = _c; }

	std::string getAlbumTitle() const { return albumTitle; }
	void setAlbumTitle(const std::string& _c) { albumTitle = _c; }
		
	void SetEmpty();

	friend std::ostream& operator<<(std::ostream& stream, const SongElement& _c);
	friend std::istream& operator>>(std::istream&, SongElement&);
};
 


