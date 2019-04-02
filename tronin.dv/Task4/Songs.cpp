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

void Songs::Add(const std::string & songTitle, const std::string & lyricsAuthor, const std::string & musicAuthor, const std::string & perfomer, Date releaseDate, const std::string & albumTitle)
{
	
	SongElement tmp(songTitle, lyricsAuthor, musicAuthor, perfomer, releaseDate, albumTitle);
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

void Songs::Change(const std::string & songTitle)
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getSongTitle().compare(songTitle) == 0)
		{

		}
	}
}

void Songs::AllByPerfomer(std::ostream& stream, const std::string & perfomer) const
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getPerfomer().compare(perfomer) == 0)
		{
			stream << base[i];
		}
	}
}

void Songs::AllByLyricsAuthor(std::ostream & stream, const std::string & lyricsAuthor) const
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getPerfomer().compare(lyricsAuthor) == 0)
		{
			stream << base[i];
		}
	}
}

void Songs::AllByMusicAuthor(std::ostream & stream, const std::string & musicAuthor) const
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getPerfomer().compare(musicAuthor) == 0)
		{
			stream << base[i];
		}
	}

}

void Songs::DeleteBySongTitle(const std::string & songTitle)
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getSongTitle().compare(songTitle) == 0)
		{
			base[i].SetEmpty();
			return;
		}
	}
	throw SongNotExist;
}

SongElement& Songs::operator[](int index)
{
	if (index < 0 || index >= rlength) throw OutOfRange;
	return base[index];
}




