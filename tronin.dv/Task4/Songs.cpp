#include "Songs.h"



Songs::Songs()
{
	length = rlength = buf = 0;
	base = nullptr;
}

Songs::Songs(int count, int buf)
{
	rlength = count;
	length = rlength + buf;
	base = new SongElement[length];
}

Songs::Songs(std::istream &stream, int buf) ??
{
	
	Songs tmp(stream);
	_c = tmp;
}

Songs::Songs(const Songs & _c)
{
	length = _c.length;
	buf = _c.buf;
	rlength = _c.rlength;
	base = new SongElement[length];
	for (int i = 0; i < rlength; i++)
	{
		base[i] = _c.base[i];
	}
}


Songs::~Songs()
{
	length = rlength = buf = 0;
	delete[] base;
	base = nullptr;
}

void Songs::Add(const std::string &songTitle, const std::string &lyricsAuthor, const std::string &musicAuthor, const std::string &perfomer, const Date &releaseDate, const std::string &albumTitle)
{
	SongElement tmp(songTitle, lyricsAuthor, musicAuthor, perfomer, releaseDate, albumTitle);
	Add(tmp);
}

void Songs::Add(const SongElement& _c)
{
	if (length - rlength > 0) //Если осталось место 
	{
		base[rlength] = _c;
		rlength++;
	}
	else
	{
		Songs tmp(length + buf, buf);
		tmp.rlength = length;
		for (int i = 0; i < length; i++)
		{
			tmp.base[i] = this->base[i];
		}
		tmp.base[tmp.rlength] = _c;
		tmp.rlength++;
		*this = tmp;
	}
}

bool Songs::Change(const std::string & songTitle, const std::string & lyricsAuthor, const std::string & musicAuthor, const std::string & perfomer, const Date & releaseDate, const std::string & albumTitle)
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getSongTitle().compare(songTitle) == 0)
		{
			base[i] = SongElement(songTitle, lyricsAuthor, musicAuthor, perfomer, releaseDate, albumTitle);
			return true;
		}
	}
	return false;
}

void Songs::Find(std::ostream & stream, const std::string & songTitle, const std::string & perfomer)
{
	int i = 0;
	for (int i = 0; i < rlength; i++)
	{
		if ((base[i].getSongTitle().compare(songTitle) == 0) && (base[i].getPerfomer().compare(perfomer) == 0))
		{
			i++;
			stream << base[i];			
		}
	}
	if (i == 0) stream << "Композиции с названием \"" << songTitle << "\" и исполнителем \"" << perfomer << "\" отсутвует в базе" << std::endl;
}

void Songs::AllByPerfomer(std::ostream& stream, const std::string & perfomer) const
{
	int i = 0;
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getPerfomer().compare(perfomer) == 0)
		{
			stream << base[i];
			i++;
		}
	}
	if (i == 0) stream << "Композиции исполнителя \"" << perfomer << "\" отсутвуют в базе" << std::endl;
}

void Songs::AllByLyricsAuthor(std::ostream & stream, const std::string & lyricsAuthor) const
{
	int i = 0;
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getPerfomer().compare(lyricsAuthor) == 0)
		{
			stream << base[i];
			i++;
		}
	}
	if (i == 0) stream << "Композиции поэта \"" << lyricsAuthor << "\" отсутвуют в базе" << std::endl;
}


void Songs::AllByMusicAuthor(std::ostream & stream, const std::string & musicAuthor) const
{
	int i = 0;
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getPerfomer().compare(musicAuthor) == 0)
		{
			stream << base[i];
			i++;
		}
	}
	if (i == 0) stream << "Композиции композитора \"" << musicAuthor << "\" отсутвуют в базе" << std::endl;

}

bool Songs::DeleteBySongTitle(const std::string & songTitle)
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getSongTitle().compare(songTitle) == 0)
		{
			base[i].SetEmpty();
			return true;
		}
	}
	return false;
}

SongElement& Songs::operator[](int index)
{
	if (index < 0 || index >= rlength) throw OutOfRange;
	return base[index];
}

std::ostream & operator<<(std::ostream &, const Songs & _c)
{

	// TODO: вставьте здесь оператор return
}

std::istream & operator>>(std::istream &stream, Songs& _c)
{
	stream >> _c.rlength;
	_c.length = _c.rlength + _c.buf;
	_c.base = new SongElement[_c.length];
	for (int i = 0; i < rlength; i++)
	{
		stream >> _c.base[i];
	}

	
	return stream;
}
