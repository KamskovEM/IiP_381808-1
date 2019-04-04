#pragma once
#include "Person.h"
#include "Data.h"

class Song
{
public:

	// ������������ ----------------------------------------------------------
	// ����������� ������������� (� ����������� �� ��������)
	Song(const std::string& Location_ = "����������", const std::string& NameSong_ = "����������", 
		const std::string& Album_ = "����������",
		const int& day_ = 0, const int& month_ = 0, const int& year_ = 0);
	// ������� ������������ ����� ���������� ����������� ����������� ����� 
	// ���������� ������������� (�.�. ����� ����� ������� �� ���� �����-���� ��� ���� ������)

	 // ����������� �����������
	Song(const Song& copy);

	// ������ ������ ---------------------------------------------------------
	// ����� ����� �� �������
	void OutSong(const std::string& str = "") const;

	// ������ ������� � �������������� �����
	Data& DataRelease() { return dataRelease; };
	std::string& Location() { return location; };
	std::string& NameSong() { return nameSong; };
	std::string& Album() { return album; };
	Person& Poet() { return poet; };
	Person& Compositer() { return compositer; };
	Person& Executor() { return executor; };

	// ������ ������������ �������
	const Data& DataRelease() const { return dataRelease; };
	const std::string& Location() const { return location; };
	const std::string& NameSong() const { return nameSong; };
	const std::string& Album() const { return album; };
	const Person& Poet() const { return poet; };
	const Person& Compositer() const { return compositer; };
	const Person& Executor() const { return executor; };

	// ���������� ���������� -------------------------------------------------
	// ���������� �������� ������ � �����
	friend std::ostream& operator<< (std::ostream& stream, const Song& C);

	// ���������� �������� ����� �� ������
	friend std::istream& operator>> (std::istream& stream, Song& C);

	// ���������� ��������� ���������
	bool operator== (const Song& p) const;

	// ���������� ��������� ������������
	Song* operator= (const Song& copy);

	// ���������� ------------------------------------------------------------
	~Song();
private:
	// ���� ������ -----------------------------------------------------------
	std::string nameSong, // ��� �����
		album, // ������
		location; // ���� � ����� (���� �� ����� ���� ������ url) 
	Data dataRelease; // ���� ������
	Person poet; // ����
	Person compositer; // ����������
	Person executor; // �����������
};

// ����������� "������" �������
inline void Song::OutSong(const std::string & str) const
{
	std::cout << str << nameSong << ' ' << album << ' ' << dataRelease;
}