#pragma once
#include <iostream>
#include <string>

class Data {
public:
	// ������������ ----------------------------------------------------------
	// ����������� �������������
	Data(const int& day_, const int& month_, const int& year_);

	// ����������� ����������� 
	Data(const Data& copy) : day(copy.day), 
		month(copy.month), year(copy.year) {}

	// ����������� �� ���������
	Data() : year(0), month(0), day(0) {}

	// ������ ������ ---------------------------------------------------------
	// ����� ���� �� �������
	void OutData(const std::string& str = "") const;

	// ������� ���� � ������
	std::string ToString() const;

	// ������ ������� � �������������� �����
	int& Day() { return day; };
	int& Month() { return month; };
	int& Year() { return year; };

	// ������ ������������ ������� 
	const int& Day() const { return day; };
	const int& Month() const { return month; };
	const int& Year() const { return year; };

	// ���������� ���������� -------------------------------------------------
	 // ���������� ��������� ������������
	Data* operator= (const Data& copy);

	// ���������� �������� ������ � �����
	friend std::ostream& operator<< (std::ostream& stream, const Data& C);

	// ����� ����������
	class InvalideData : public std::out_of_range {
	public:
		// ����������� ������ ����������
		InvalideData(const std::string& Message_);

		// ���������� ������ ����������
		~InvalideData();
	};
	// ���������� �������� ����� �� ������
	friend std::istream& operator>> (std::istream& stream, Data& C);

	// ���������� ��������� ���������
	bool operator== (const Data& p) const;

	// ���������� ------------------------------------------------------------
	~Data();

private:
	// ���� ������ -----------------------------------------------------------
	int year; // ���
	int month; // �����
	int day; // ����

	// ����� �������� ������������ ������� ��������� ������
	void IsRight() const;
};


// ��������� "������" �������
inline void Data::OutData(const std::string& str) const
{
	std::cout << str << day << '.' << month << '.' << year;
}

inline std::string Data::ToString() const
{
	return std::string(std::to_string(day) + '.' + std::to_string(month) + '.' + std::to_string(year));
}
