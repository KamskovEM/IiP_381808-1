#include <iostream>
#include <string>


class CTime
{
public:
	//konstruiruet  vremya  chch - mm - ss
	//esli chasy, minuty ili sekundy vyhodyat za predely 23.59.59 - brosaet
	//isklyuchenie invalid_argument
	CTime() = default;
	CTime(int time);
	CTime(int hours, int minutes, int seconds);
	CTime(std::string str);

	//vozvrashchaet kolichestvo chasov (0..23)

	int GetHours() const;

	//vozvrashchaet kolichestvo minut (0..59)
	int GetMinutes() const;

	//vozvrashaet kolichestvo secund (0..59)
	int GetSeconds() const;

	//vozvrashchaet strokovoe predstavlenie vremeni v formate chch:mm:ss
	std::string ToString() const;

	CTime & operator = (const CTime&);
	bool operator == (const CTime&) const;
	bool operator != (const CTime&) const;
	bool operator > (const CTime&) const;
	bool operator < (const CTime&) const;

	friend std::ostream & operator << (std::ostream & stream, const CTime & time);
	friend std::istream & operator >> (std::istream& stream, CTime& time);

	int GetTimeStamp() const;

private:
	int m_timeStamp = 0;
};

std::ostream & operator << (std::ostream & stream, const CTime & time);
std::istream & operator >> (std::istream& stream, CTime& time);
const CTime operator+(const CTime & lhs, const CTime & rhs);
const CTime operator-(const CTime & lhs, const CTime & rhs);
