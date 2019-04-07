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

Songs::Songs(std::istream &stream, int buf) 
{
	this->buf = buf;
	length = rlength = 0;
	base = nullptr;
	stream >> *this;
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

void Songs::Add(const std::string &songTitle, const std::string &lyricsAuthor, const std::string &musicAuthor, const std::string &perfomer, int d, int m, int y , const std::string &albumTitle)
{	
	Add(SongElement(songTitle, lyricsAuthor, musicAuthor, perfomer, Date(d, m, y), albumTitle));
}

void Songs::Add(const SongElement& _c)
{
	if (length - rlength > 0) //Если осталось место 
	{
		int i = 0;
		while ((_c.getSongTitle().compare(base[i].getSongTitle()) > 0) && i < rlength) i++; //Ищем место для вставки
		for (int k = rlength; k > i; k--)
		{
			base[k] = base[k - 1];
		}
		base[i] = _c;
		rlength++;
	}
	else
	{
		Songs tmp(length + buf, buf);
		tmp.rlength = length;

		int i = 0;
		while (_c.getSongTitle().compare(base[i].getSongTitle()) > 0) i++; //Ищем место для вставки

		for (int k = 0; k < i; k++)
		{
			tmp.base[k] = this->base[k];
		}
		tmp.base[i] = _c;
		for (int k = i + 1; k < rlength + 1; k++)
		{
			tmp.base[k] = this->base[k];
		}
		tmp.rlength++;
		*this = tmp;
	}
}



bool Songs::Change(const std::string & songTitle, const std::string & lyricsAuthor, const std::string & musicAuthor, const std::string & perfomer, int d, int m, int y, const std::string & albumTitle)
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getSongTitle() == songTitle)
		{
			base[i] = SongElement(songTitle, lyricsAuthor, musicAuthor, perfomer, Date(d, m, y), albumTitle);
			return true;
		}
	}
	return false;
}

bool Songs::Search(std::string songTitle)
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getSongTitle() == songTitle)
		{
			return true;
		}
	}
	return false;
}

void Songs::Find(std::ostream & stream, const std::string & songTitle, const std::string & perfomer)
{
	int f = 0;
	for (int i = 0; i < rlength; i++)
	{
		if ((base[i].getSongTitle() == songTitle) && (base[i].getPerfomer() == perfomer))
		{			
			stream << base[i];	//Может быть несколько композиции
			f++;
		}
	}
	if (f == 0) stream << "Композиции с названием \"" << songTitle << "\" и исполнителем \"" << perfomer << "\" отсутвует в базе" << std::endl;
}

void Songs::AllByPerfomer(std::ostream& stream, const std::string & perfomer) const
{
	int f = 0;
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getPerfomer()== perfomer)
		{
			stream << base[i] << std::endl;
			f++;
		}
	}
	if (f == 0) stream << "Композиции исполнителя \"" << perfomer << "\" отсутвуют в базе" << std::endl;
}

void Songs::AllByLyricsAuthor(std::ostream& stream, const std::string & lyricsAuthor) const
{
	int f = 0;
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getLyricsAuthor() == lyricsAuthor)
		{
			stream << base[i] << std::endl;
			f++;
		}
	}
	if (f == 0) stream << "Композиции поэта \"" << lyricsAuthor << "\" отсутвуют в базе" << std::endl;
}


void Songs::AllByMusicAuthor(std::ostream & stream, const std::string & musicAuthor) const
{
	int f = 0;
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getMusicAuthor() == musicAuthor)
		{
			stream << base[i] << std::endl;
			f++;
		}
	}
	if (f == 0) stream << "Композиции композитора \"" << musicAuthor << "\" отсутвуют в базе" << std::endl;

}

bool Songs::DeleteBySongTitle(const std::string & songTitle)
{
	for (int i = 0; i < rlength; i++)
	{
		if (base[i].getSongTitle() == songTitle)
		{
			for (int k = i; k < rlength; k++) //Смещаем все песни на 1 назад, чтобы переместить удяляемую в самый конец
			{
				base[k] = base[k + 1];
			}
			base[rlength - 1].SetEmpty();
			rlength--;
			return true; // Удаление успешно
		}
	}
	return false; // Песня отсутствует в базе
}

Songs & Songs::operator=(const Songs& _c)
{
	if (this != &_c)
	{
		if (length != _c.length)
		{
			length = _c.length;
			delete[] base;
			base = new SongElement[length];
		}
		buf = _c.buf;
		rlength = _c.rlength;
		for (int i = 0; i < length; i++) //Продолжаем дальше реальной длины, так как там может остаться "мусор" 
		{
			base[i] = _c.base[i];
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream &stream, const Songs & _c)
{
	stream << _c.rlength << '\n';
	for (int i = 0; i < _c.rlength; i++)
	{
		stream << _c.base[i];
		stream << '\n';
	}
	return stream;
}

std::istream & operator>>(std::istream &stream, Songs& _c)
{
	int tmplength;
	stream >> tmplength;
	stream.ignore();
	if (tmplength != _c.rlength)
	{
		if (_c.base != nullptr)	delete[] _c.base;
		_c.rlength = tmplength;
		_c.length = _c.rlength + _c.buf;
		_c.base = new SongElement[_c.length];
	}
	for (int i = 0; i < _c.rlength; i++)
	{
		stream >> _c.base[i];
	}	
	return stream;
}