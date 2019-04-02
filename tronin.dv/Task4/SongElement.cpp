#include "SongElement.h"


SongElement::SongElement()
{
	//releaseDate.day = releaseDate.month = releaseDate.year = 0;
	songTitle = lyricsAuthor = musicAuthor = perfomer = albumTitle = std::string(); // Присваиваем пустую строку	
}

SongElement::SongElement(const std::string& songTitle, const std::string& lyricsAuthor, const std::string& musicAuthor, const std::string& perfomer, Date releaseDate, const std::string& albumTitle) 
	: songTitle(songTitle), lyricsAuthor(lyricsAuthor), musicAuthor(musicAuthor), perfomer(perfomer), releaseDate(releaseDate)
{
	if (&albumTitle == nullptr)
		this->albumTitle = std::string();
	else
		this->albumTitle = albumTitle;
}


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
	stream << _c.day << '.' << _c.month << '.' << _c.year;
	return stream;
}

std::istream& operator>>(std::istream& stream, Date& _c)
{
	stream >> _c.day;
	char c;
	stream >> c; //Забираем точку 
	stream >> _c.month;
	stream >> c;
	stream >> _c.year;	
}

std::ostream& operator<<(std::ostream& stream, const SongElement& _c)
{
	stream << _c.songTitle << ' ' << _c.lyricsAuthor << ' ' << _c.musicAuthor << ' ' << _c.perfomer << ' ' << _c.releaseDate << ' ' << _c.albumTitle << '\n';
	return stream;
}

std::istream & operator>>(std::istream& stream, SongElement& _c)
{
	stream >> _c.songTitle;
	stream >> _c.lyricsAuthor;
	stream >> _c.musicAuthor;
	stream >> _c.perfomer;
	stream >> _c.releaseDate;
	char c;	
	std::string tmp;
	stream >> c; //Забираем пробел 
	std::getline(stream, tmp);
	if (!(tmp.length == 1)) //Если в строке не только символ перехода на новую строку
		_c.albumTitle = tmp;
	return stream;
}


