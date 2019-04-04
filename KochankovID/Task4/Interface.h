#pragma once
#include "ClassSongs.h"
#include "..\Task3\ClassMenu.h"
class Interface
{
public:
	// ������������ ----------------------------------------------------------
	// ����������� �� ���������
	Interface();

	// ����������� ����������� (������ �������� �����)
	Interface(const Interface& copy) = delete;

	// ������ ������ ---------------------------------------------------------
	// ������ ������ � ����������� �������� ���������� ���� 
	void StartMenu();

	// ����� ���� ���� ������
	void MenuWAP();

	// ����� ���� ���� ������������
	void MenuWAC();

	// ����� ���� ���� ������������
	void MenuWAE();

	// ����� ���� ���� �����
	void MenuWAS();
	void MenuWAS(Person* peson, Collection<Song*>(ClassSongs::*songs)(const Person&));

	// ����� ���� ������
	void SearchMenu();

	// ���� ������ �������� ��� ���������
	void OptionsPersonMenu(Person* person, Collection<Song*>(ClassSongs::*songs)(const Person&), void(ClassSongs::*change)(const Person&, const Person&));

	// ���� ������ �������� ��� ������
	void OptionsSongMenu(Song* song);

	// ���� ���������� � �����
	void InfoPerson(Person* person);

	// ���� ���������� � �����
	void InfoSong(const Song* song);

	// ���� �������������� �����
	void RedactSong(Song* song);

	// ���� �������������� ���������� � �����
	void RedactPeron(Person* person, void(ClassSongs::*change)(const Person&, const Person&));

	// �������������
	void PlaySong(const Song* song);

	//���� ���������� �����
	void AddSong();

	// ���������� ------------------------------------------------------------
	~Interface();

private:
	// ���� ������ -----------------------------------------------------------
	std::unique_ptr<ClassSongs> Archive; // ���������
	std::unique_ptr<ClassMenu> Menu; // ��������� �� ����
	

};

