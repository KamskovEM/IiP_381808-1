#pragma once
#include "Song.h"
#include "Collection.h"
#include <iostream>

class ClassSongs
{
public:
	// ������������ ----------------------------------------------------------
	// ����������� �� ���������
	ClassSongs();

	// ����������� �������������
	explicit ClassSongs(const std::string& file);

	// ����������� ����������� (��������)
	ClassSongs(const ClassSongs& copy) = delete;

	// ������ ������ ---------------------------------------------------------
	// ����� ������� � �������������� ��������� �����
	Collection<Song>& songs() { return Songs; };

	// ����� ������ ����� �� �������� (� ������������ ��������������)
	Collection<Song*> getNameSongs(std::string name);

	// ����� ������ ����� �� �������� (� ������������ ��������������)
	Collection<Person*> getPoets(std::string name);
	Collection<Person*> getPoets();

	// ����� ������ ����������� �� �������� (� ������������ ��������������)
	Collection<Person*> getComositers(std::string name);
	Collection<Person*> getComositers();

	// ����� ������ ����������� �� �������� (� ������������ ��������������)
	Collection<Person*> getExecutorts(std::string name);
	Collection<Person*> getExecutorts();

	//--------------------------------------------------------------------
	// ����� ������ ���� ����� ����� (� ������������ ��������������)
	Collection<Song*> getAllPoetSongs(const Person& poet);

	// ����� ������ ���� ����� ����������� (� ������������ ��������������)
	Collection<Song*> getAllCompositerSongs(const Person& compositer);

	// ����� ������ ���� ����� ����������� (� ������������ ��������������)
	Collection<Song*> getAllExecutorSongs(const Person& executor);
	//--------------------------------------------------------------------

	// ����� ��������� �����
	void ChangeAllPoets(const Person& poet, const Person& poet1);

	// ����� ��������� �����������
	void ChangeAllCompositers(const Person& compositer, const Person& compositer1);

	// ����� ��������� �����������
	void ChangeAllExecutors(const Person& executor, const Person& executor1);

	// ���������� ����� �� ��������
	void sort();

	// ����� ����������� ����� ����� � ���� ��������
	void saveArchive();

	// ���������� ���������� --------------------------------------------------------
	friend std::ostream& operator<< (std::ostream& stream, const ClassSongs& C); // ���������� �������� ������ � �����
	friend std::istream& operator>> (std::istream& stream, ClassSongs& C); // ���������� �������� ����� �� ������

	// ���������� ---------------------------------------------------------------------
	~ClassSongs();
private:
	// ������� ���� ������ ------------------------------------------------------------

	// ��������� ����� � ���������� � ���
	Collection<Song> Songs; // ��������� �����
	std::string file; // ��� ����� � ����� ����������� ����������
};
