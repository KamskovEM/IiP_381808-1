#include "SongElement.h"


SongElement::SongElement()
{
	//У структуры Date имеется свой констуруктор по-умолчанию
	songTitle = lyricsAuthor = musicAuthor = perfomer = albumTitle = std::string(); // Присваиваем пустую строку	
}

SongElement::SongElement(const std::string& songTitle, const std::string& lyricsAuthor, const std::string& musicAuthor, const std::string& perfomer, Date releaseDate, const std::string& albumTitle)
	: songTitle(songTitle), lyricsAuthor(lyricsAuthor), musicAuthor(musicAuthor), perfomer(perfomer), releaseDate(releaseDate), albumTitle(albumTitle) {}


SongElement::~SongElement()
{
	releaseDate.day = releaseDate.month = releaseDate.year = 0;
}

void SongElement::SetEmpty()
{
	songTitle = lyricsAuthor = musicAuthor = perfomer = albumTitle = std::string(); // Присваиваем пустую строку
	releaseDate.day = releaseDate.month = releaseDate.year = 0;
}


std::ostream& operator<<(std::ostream& stream, const Date& _c)
{
	stream << std::setw(2) << (int)_c.day << '.' << std::setw(2) << (int)_c.month << '.' << (int)_c.year; //setw - форматирвоанный вывод в 2 символа
	return stream;
}

std::istream& operator>>(std::istream& stream, Date& _c)
{
	int tmp;
	stream >> tmp;
	_c.day = tmp;
	char c;
	stream >> c; //Забираем точку 
	stream >> tmp;
	_c.month = tmp;
	stream >> c;
	stream >> tmp;
	_c.year = tmp;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const SongElement& _c)
{
	stream << _c.songTitle << '\t' << _c.lyricsAuthor << '\t' << _c.musicAuthor << '\t' << _c.perfomer << '\t' << _c.releaseDate << '\t' << _c.albumTitle; //Для удобства ручного просмотра файла
	return stream;
}

std::istream & operator>>(std::istream& stream, SongElement& _c)
{
	//Для удобства записываем все поля в одну строку, разделяя символом табуляции 
	std::getline(stream, _c.songTitle, '\t');
	std::getline(stream, _c.lyricsAuthor, '\t');
	std::getline(stream, _c.musicAuthor, '\t');
	std::getline(stream, _c.perfomer, '\t');
	stream >> _c.releaseDate;
	std::string tmp;
	std::getline(stream, _c.albumTitle);
	return stream;
}


