#include "CTime.h"

namespace
{

	bool IsInRange(int value, std::pair<int, int> range)
	{
		return ((range.first <= value) && (value <= range.second));
	}

	std::string FormatNumber(int num)
	{
		return (num < 10) ? ("0" + std::to_string(num)) : std::to_string(num);
	}

	const std::pair<int, int> SECOND_RANGE(0, 59);
	const std::pair<int, int> MINUTE_RANGE(0, 59);
	const std::pair<int, int> HOUR_RANGE(0, 23);

	int FormatString(std::string str)
	{
		int counter = 0;
		int hours = 0;
		int minutes = 0;
		int seconds = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ':')
			{
				switch (counter)
				{
				case 0:
				{
					hours = std::stoi(str.substr(0, 2)) * 3600;
					counter++;
					break;
				}
				case 1:
				{
					minutes = std::stoi(str.substr(i - 2, 2)) * 60;
					counter++;
					break;
				}

				default:
					throw std::invalid_argument("incorrect string were given");
					break;
				}

			}
			seconds = std::stoi(str.substr(str.size() - 2, 2));
		};

		return hours + minutes + seconds;
	}

}

CTime::CTime(int time)
	:m_timeStamp(time)
{

}

CTime::CTime(int hours, int minutes, int seconds)
{
	if (!IsInRange(hours, HOUR_RANGE))
	{
		throw std::invalid_argument("hours must be in 0..23");
	}
	if (!IsInRange(minutes, MINUTE_RANGE))
	{
		throw std::invalid_argument("minutes must be in 0..59");
	}
	if (!IsInRange(seconds, SECOND_RANGE))
	{
		throw std::invalid_argument("seconds must be in 0..59");
	}
	m_timeStamp = 3600 * hours + 60 * minutes + seconds;
}

CTime::CTime(std::string str)
{
	m_timeStamp = FormatString(str);
}

int CTime::GetHours() const
{
	return (m_timeStamp / 3600) % 24;
}

int CTime::GetMinutes() const
{
	return (m_timeStamp / 60) % 60;
}

int CTime::GetSeconds() const
{
	return m_timeStamp % 60;
}

std::string CTime::ToString() const
{
	std::string hours = FormatNumber(GetHours());
	std::string minutes = FormatNumber(GetMinutes());
	std::string seconds = FormatNumber(GetSeconds());
	return {
		hours + ":" + minutes + ":" + seconds
	};
}

int CTime::GetTimeStamp() const
{
	return m_timeStamp;
}

std::ostream & operator<<(std::ostream & stream, const CTime & time)
{
	stream << time.ToString();
	return stream;
}

std::istream & operator >> (std::istream& stream, CTime& time)
{
	char str[9];
	stream.getline(str, 9);
	time.m_timeStamp = FormatString(str);
	return stream;
}

const CTime operator+(const CTime & lhs, const CTime & rhs)
{
	return CTime((lhs.GetTimeStamp() + rhs.GetTimeStamp()) % (24 * 60 * 60));
}

const CTime operator-(const CTime & lhs, const CTime & rhs)
{
	return CTime((lhs.GetTimeStamp() - rhs.GetTimeStamp() + (24 * 60 * 60)) % (24 * 60 * 60));
}

bool CTime::operator > (const CTime& time) const
{
	return (m_timeStamp > time.GetTimeStamp()) ? true : false;
}

bool CTime::operator < (const CTime& time) const
{
	return (m_timeStamp < time.GetTimeStamp()) ? true : false;
}

bool CTime::operator == (const CTime& time) const
{
	return (m_timeStamp == time.GetTimeStamp()) ? true : false;
}

bool CTime::operator != (const CTime& time) const
{
	return (m_timeStamp != time.GetTimeStamp()) ? true : false;
}

CTime& CTime::operator = (const CTime& time)
{
	m_timeStamp = time.GetTimeStamp();
	return *this;
}


