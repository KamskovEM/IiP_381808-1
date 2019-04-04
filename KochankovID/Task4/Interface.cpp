#include "Interface.h"
#include <fstream>
#include <iostream>
#include <bass.h>
#include <Windows.h>
#include <id3v2lib.h>
#include <boost_1_69_0/boost/lexical_cast.hpp>
#include "..\Task3\ClassMenu.h"

using namespace std;
Interface::Interface(): Archive(new ClassSongs("Saved.txt")), Menu(new ClassMenu())
{
	// ��������� ������� ������ �������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX cfie;
	ZeroMemory(&cfie, sizeof(cfie));
	cfie.cbSize = 16;
	lstrcpyW(cfie.FaceName, L"Lucida Console");

	SetCurrentConsoleFontEx(hStdOut, false, &cfie);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BASS_Init(-1, 44100, 0, 0, NULL);

}

void Interface::StartMenu()
{
	while (true) {
		Menu->setKol(7);
		(*Menu)[0] = "�����";
		(*Menu)[1] = "�����������";
		(*Menu)[2] = "�����������";
		(*Menu)[3] = "�����";
		(*Menu)[4] = "�����";
		(*Menu)[5] = "�������� �����";
		(*Menu)[6] = "�����";
		string title[] = { "Ilya_Player Version 1" };
		int a[] = { 0 };
		(*Menu).DrawCMenu(1, a, title, 0, 0, 2, 2);

		switch ((*Menu).getLastClause()) {
		case 1: MenuWAP();
			break;
		case 2: MenuWAC();
			break;
		case 3: MenuWAE();
			break;
		case 4: MenuWAS();
			break;
		case 5: SearchMenu();
			break;
		case 6: try {
			AddSong();
		}
				catch (std::runtime_error e) {
					cout << e.what();
					getchar();
		}
			break;
		case 7: (*Archive).saveArchive();
			return;
			break;
		}
	}
}

void Interface::MenuWAP()
{
	Collection<string> titles;
	titles.Add("�����������");
	Collection<int> nums;
	nums.Add(0);
	Collection<Person*> Poets = (*Archive).getPoets();
	(*Menu).setKol(Poets.Count()+1);
	for (int i = 0; i < Poets.Count(); i++) {
		(*Menu)[i] = "���: " + Poets[i]->Name() + " �������: " + Poets[i]->Female() + " �������: " + std::to_string(Poets[i]->Age());
	}
	if (Poets.Count() == 0) {
		(*Menu).setKol(1);
		(*Menu)[0] = "����� �� �������!";
	}
	else {
		titles.Add("--------------------------------------------");
		nums.Add(Poets.Count());
		(*Menu)[Poets.Count()] = "�����";
	}
	(*Menu).DrawCMenu(nums.Count(), nums.AsArray(), titles.AsArray(),0,0,1,2);
	if ((*Menu).getLastClause() != (Poets.Count()+1)) {
		OptionsPersonMenu(Poets[(*Menu).getLastClause()-1], &ClassSongs::getAllPoetSongs, &ClassSongs::ChangeAllPoets);
		return;
	}
}

void Interface::MenuWAC()
{
	Collection<string> titles;
	titles.Add("����������� ");
	Collection<int> nums;
	nums.Add(0);
	Collection<Person*> Compositers = (*Archive).getComositers();
	(*Menu).setKol(Compositers.Count() + 1);
	for (int i = 0; i < Compositers.Count(); i++) {
		(*Menu)[i] ="���: " + Compositers[i]->Name() + " �������: " + Compositers[i]->Female() + " �������: " + std::to_string(Compositers[i]->Age());
	}
	if (Compositers.Count() == 0) {
		(*Menu).setKol(1);
		(*Menu)[0] = "����������� �� �������!";
	}
	else {
		(*Menu)[Compositers.Count()] = "�����";
		titles.Add("--------------------------------------------");
		nums.Add(Compositers.Count());
	}
	(*Menu).DrawCMenu(nums.Count(), nums.AsArray(), titles.AsArray(), 0, 0, 1, 2);
	if ((*Menu).getLastClause() != (Compositers.Count() + 1)) {
		OptionsPersonMenu(Compositers[(*Menu).getLastClause()-1], &ClassSongs::getAllCompositerSongs, &ClassSongs::ChangeAllCompositers);
		return;
	}
}

void Interface::MenuWAE()
{
	Collection<string> titles;
	titles.Add("�����������");
	Collection<int> nums;
	nums.Add(0);
	Collection<Person*> Executors = (*Archive).getExecutorts();
	(*Menu).setKol(Executors.Count() + 1);
	for (int i = 0; i < Executors.Count(); i++) {
		(*Menu)[i] = "���: "+Executors[i]->Name() + " �������: " + Executors[i]->Female() + " �������: " + std::to_string(Executors[i]->Age());
	}
	if (Executors.Count() == 0) {
		(*Menu).setKol(1);
		(*Menu)[0] = "����������� �� �������!";
	}
	else {
		titles.Add("--------------------------------------------");
		nums.Add(Executors.Count());
		(*Menu)[Executors.Count()] = "�����";
	}
	(*Menu).DrawCMenu(nums.Count(), nums.AsArray(), titles.AsArray(), 0, 0, 1, 2);
	if ((*Menu).getLastClause() != (Executors.Count() + 1)) {
		OptionsPersonMenu(Executors[(*Menu).getLastClause()-1], &ClassSongs::getAllExecutorSongs, &ClassSongs::ChangeAllExecutors);
		return;
	}
}

void Interface::MenuWAS()
{
	Collection<Song>& Songs = (*Archive).songs();
	Collection<string> titles;
	titles.Add("�����: " + std::to_string(Songs.Count()));
	Collection<int> nums;
	nums.Add(0);
	(*Menu).setKol(Songs.Count() + 1);

	for (int i = 0; i < Songs.Count(); i++) {
		(*Menu)[i] = Songs[i].NameSong() + " ������: " + Songs[i].Album() + " �����������: " + Songs[i].Executor().Name() +
			" ����: " + Songs[i].Poet().Name() + " ����������: " + Songs[i].Compositer().Name();
	}
	if (Songs.Count() == 0) {
		(*Menu).setKol(1);
		(*Menu)[0] = "����� �� �������!";
	}
	else {
		titles.Add("--------------------------------------------");
		nums.Add(Songs.Count());
		(*Menu)[Songs.Count()] = "�����";
	}
	(*Menu).DrawCMenu(nums.Count(), nums.AsArray(), titles.AsArray(), 0, 0, 1, 2);
	if ((*Menu).getLastClause() != (Songs.Count() + 1)) {
		OptionsSongMenu(&Songs[(*Menu).getLastClause()-1]);
		return;
	}
}

void Interface::MenuWAS(Person * peson, Collection<Song*>(ClassSongs::*songs)(const Person&))
{
	Collection<string> titles;
	titles.Add("�����");
	Collection<int> nums;
	nums.Add(0);
	Collection<Song*> Songs = (Archive._Myptr()->*songs)(*peson);
	(*Menu).setKol(Songs.Count() + 1);

	for (int i = 0; i < Songs.Count(); i++) {
		(*Menu)[i] = Songs[i]->NameSong() + " ������: " + Songs[i]->Album() + " �����������: " + Songs[i]->Executor().Name() +
			" ����: " + Songs[i]->Poet().Name() + " ����������: " + Songs[i]->Compositer().Name();
	}
	if (Songs.Count() == 0) {
		(*Menu).setKol(1);
		(*Menu)[0] = "����� �� �������!";
	}
	else {
		titles.Add("--------------------------------------------");
		nums.Add(Songs.Count());
		(*Menu)[Songs.Count()] = "�����";
	}
	(*Menu).DrawCMenu(nums.Count(), nums.AsArray(), titles.AsArray(), 0, 0, 1, 2);
	if ((*Menu).getLastClause() != (Songs.Count() + 1)) {
		PlaySong(Songs[(*Menu).getLastClause()-1]);
		return;
	}
}

void Interface::SearchMenu()
{
	Collection<string> titles;
	Collection<int> nums;
	titles.Add("�����");
	nums.Add(0);
	cout << "�����, �����������, �����������, �����... :";
	string str;
	std::getline(cin, str);
	while (0 == str.find(' '))
		str.erase(0, 1);

	Collection<Song*> Songs = (*Archive).getNameSongs(str);
	Collection<Person*> Poets = (*Archive).getPoets(str);
	Collection<Person*> Compositers = (*Archive).getComositers(str);
	Collection<Person*> Executors = (*Archive).getExecutorts(str);

	(*Menu).setKol(Songs.Count()+Poets.Count()+Compositers.Count()+Executors.Count() + 1);
	for (int i = 0; i < Songs.Count(); i++) {
		(*Menu)[i] = Songs[i] ->NameSong() + " ������: " + Songs[i] ->Album();
	}

	if (Songs.Count() != 0) {
		titles.Add("�����: ");
		nums.Add(0);
	}

	for (int i = 0; i < Poets.Count(); i++) {
		(*Menu)[Songs.Count() + i] = "���: " + (*Poets[i]).Name() + " �������: " + (*Poets[i]).Female() + " �������: " + std::to_string((*Poets[i]).Age());
	}

	if (Poets.Count() != 0) {
		titles.Add("�����: ");
		nums.Add(Songs.Count());
	}

	for (int i = 0; i < Compositers.Count(); i++) {
		(*Menu)[Songs.Count() + Poets.Count()+i] = "���: " + (*Compositers[i]).Name() + " �������: " + (*Compositers[i]).Female() + " �������: " + std::to_string((*Compositers[i]).Age());
	}

	if (Compositers.Count() != 0) {
		titles.Add("�����������: ");
		nums.Add(Songs.Count() + Poets.Count());
	}

	for (int i = 0; i < Executors.Count(); i++) {
		(*Menu)[Songs.Count()+Compositers.Count() + Poets.Count() + i] = "���: " + (*Executors[i]).Name() + " �������: " + (*Executors[i]).Female() + " �������: " + std::to_string((*Executors[i]).Age());
	}

	if (Executors.Count() != 0) {
		titles.Add("�����������: ");
		nums.Add(Compositers.Count() + Songs.Count() + Poets.Count());
	}


	if (Executors.Count() + Compositers.Count() + Songs.Count() + Poets.Count() == 0) {
		(*Menu).setKol(1);
		(*Menu)[0] = "������ �� ��������!";
	}
	else {
		titles.Add("--------------------------------------------");
		nums.Add(Compositers.Count() + Songs.Count() + Poets.Count()+Executors.Count());
		(*Menu)[Executors.Count() + Compositers.Count() + Songs.Count() + Poets.Count()] = "�����";
	}

	(*Menu).DrawCMenu(nums.Count(), nums.AsArray(), titles.AsArray(), 0, 0, 1, 1);

	if ((*Menu).getLastClause() != (Executors.Count() + Compositers.Count() + Songs.Count() + Poets.Count()+1)) {
		if ((*Menu).getLastClause() <= Songs.Count()) {
			OptionsSongMenu(Songs[(*Menu).getLastClause()-1]);
		}
		else {
			if ((*Menu).getLastClause() <= (Songs.Count() + Poets.Count())) {
				OptionsPersonMenu(Poets[(*Menu).getLastClause()-1-Songs.Count()], &ClassSongs::getAllPoetSongs, &ClassSongs::ChangeAllPoets);
			}
			else {
				if ((*Menu).getLastClause() <= (Songs.Count() + Poets.Count() + Compositers.Count())) {
					OptionsPersonMenu(Compositers[(*Menu).getLastClause()-1- Songs.Count()-Poets.Count()], &ClassSongs::getAllCompositerSongs, &ClassSongs::ChangeAllCompositers);
				}
				else {
						OptionsPersonMenu(Executors[(*Menu).getLastClause()-1 - Songs.Count() - Poets.Count()-Compositers.Count()], &ClassSongs::getAllExecutorSongs, &ClassSongs::ChangeAllExecutors);
				}
			}
		}
		return;
	}
}

void Interface::OptionsPersonMenu(Person* person, Collection<Song*>(ClassSongs::*songs)(const Person&), void(ClassSongs::*change)(const Person&, const Person&))
{
	Collection<string> titles;
	Collection<int> nums;
	titles.Add("�����");
	nums.Add(0);

	Menu->setKol(5);
	(*Menu)[0] = "���������� ����������";
	(*Menu)[1] = "������������� ����������";
	(*Menu)[2] = "�������� ��� �����";
	(*Menu)[3] = "�������";
	(*Menu)[4] = "����� � ����";
	(*Menu).DrawCMenu(1, nums.AsArray(), titles.AsArray(), 0, 0, 2, 2);

	Person copy(*person);
	Person deleter;
	switch ((*Menu).getLastClause()) {
	case 1: InfoPerson(person);
		break;
	case 2: RedactPeron(person, change);
		break;
	case 3: MenuWAS(person,songs);
		break;
	case 4: 
		(Archive._Myptr()->*change)(copy, deleter);
		Archive->saveArchive();
		break;
	case 5: return;
		break;
	}
}

void Interface::OptionsSongMenu(Song* song)
{
	Collection<string> titles;
	Collection<int> nums;
	titles.Add("�����");
	nums.Add(0);

	Menu->setKol(5);
	(*Menu)[0] = "������������";
	(*Menu)[1] = "���������� ����������";
	(*Menu)[2] = "������������� ����������";
	(*Menu)[3] = "�������";
	(*Menu)[4] = "����� � ����";
	(*Menu).DrawCMenu(1, nums.AsArray(), titles.AsArray(), 0, 0, 2, 2);

	switch ((*Menu).getLastClause()) {
	case 1: PlaySong(song);
		break;
	case 2: InfoSong(song);
		break;
	case 3: RedactSong(song);
		break;
	case 4:
		(*Archive).songs().Remove(*song);
		Archive->saveArchive();
		break;
	case 5: return;
		break;
	}
}

void Interface::InfoPerson(Person * person)
{
	Collection<string> titles;
	Collection<int> nums;
	titles.Add("����������");
	nums.Add(0);
	(*Menu).setKol(1);
	(*Menu)[0] = "���: " + person->Name() + "\n�������: "+ person->Female()
		+ "\n�������: " + std::to_string(person->Age())+"\n���������: " + person->Biography();
	(*Menu).DrawCMenu(1, nums.AsArray(), titles.AsArray(), 0, 0, 2, 2);
	return;
}

void Interface::InfoSong(const Song * song)
{
	Collection<string> titles;
	Collection<int> nums;
	titles.Add("����������");
	nums.Add(0);
	(*Menu).setKol(1);
	(*Menu)[0] = "��� �����: " + song->NameSong() + "\n������: " + song->Album()
		+ "\n���� ������: " + song->DataRelease().ToString() + "\n���� �� �����: " + song->Location();
	(*Menu).DrawCMenu(1, nums.AsArray(), titles.AsArray(), 0, 0, 2, 2);
	return;
}

void Interface::RedactSong(Song * song)
{
	Collection<string> titles;
	Collection<int> nums;
	titles.Add("�������������� ����������");
	nums.Add(0);
	while (true) {

		Menu->setKol(8);
		(*Menu)[0] = "��� �����: " + song->NameSong();
		(*Menu)[1] = "������: " + song->Album();
		(*Menu)[2] = "���� ������: " + song->DataRelease().ToString();
		(*Menu)[3] = "����: " + song->Location();
		(*Menu)[4] = "����: " + song->Poet().Name() + " " + song->Poet().Female();
		(*Menu)[5] = "����������: " + song->Compositer().Name() + " " + song->Compositer().Female();
		(*Menu)[6] = "�����������: " + song->Executor().Name() + " " + song->Executor().Female();
		(*Menu)[7] = "����� � ����";
		(*Menu).DrawCMenu(1, nums.AsArray(), titles.AsArray(), 0, 0, 2, 2);

		switch ((*Menu).getLastClause()) {
		case 1: cout << "������� ��� �����: ";
			std::getline(cin, song->NameSong());

			break;
		case 2: cout << "������� ������: ";
			std::getline(cin, song->Album());
			
			break;
		case 3: cout << "������� ���� ������: ";
			try {
				cin >> song->DataRelease();
			}
			catch (Data::InvalideData e) {
				cout << e.what();
				
			}
			break;
			
		case 4: cout << "������� ����: ";
			std::getline(cin, song->Location());
			
			break;
		case 5: RedactPeron(&song->Poet(), &ClassSongs::ChangeAllPoets);
			break;
		case 6: RedactPeron(&song->Compositer(), &ClassSongs::ChangeAllCompositers);
			break;
		case 7: RedactPeron(&song->Executor(), &ClassSongs::ChangeAllExecutors);
			break;
		case 8:
			Archive->sort();
			Archive->saveArchive();
			return;
			break;
		}
	}
}

void Interface::RedactPeron(Person * person, void(ClassSongs::*change)(const Person&, const Person&))
{
	Person copy = *person;
	while (true) {
		Collection<string> titles;
		Collection<int> nums;
		titles.Add("�������������� ����������");
		nums.Add(0);

		Menu->setKol(5);
		(*Menu)[0] = "���: " + person->Name();
		(*Menu)[1] = "�������: " + person->Female();
		(*Menu)[2] = "�������: " + std::to_string(person->Age());
		(*Menu)[3] = "���������: " + person->Biography();
		(*Menu)[4] = "�����";
		(*Menu).DrawCMenu(1, nums.AsArray(), titles.AsArray(), 0, 0, 2, 2);

		switch ((*Menu).getLastClause()) {
		case 1: cout << "������� ���: ";
			std::getline(cin,person->Name());
			
			break;
		case 2: cout << "������� �������: ";
			std::getline(cin, person->Female());
			
			break;
		case 3: cout << "������� �������: ";
			try {
				cin >> person->Age();
			}
			catch (Person::AgeError e) {
				cout << e.what();
				
			}
			cin.ignore(cin.rdbuf()->in_avail());
			break;
		case 4:cout << "������� ���������: ";
			std::getline(cin, person->Biography());
			
			break;
		case 5: 	
			(Archive._Myptr()->*change)(copy, *person);
			Archive->saveArchive();
			return;
			break;
		}
	}
}

void Interface::PlaySong(const Song * song)
{

	HSTREAM stream;	/* ���������� ������ */
	stream = BASS_StreamCreateFile(FALSE, song->Location().c_str(), 0, 0, 0);
	if (!stream) {
		stream = BASS_StreamCreateURL(song->Location().c_str(), 0, 0, NULL, 0);
		if (!stream) {
			throw std::runtime_error("�� ���������� ���� �� ������� ����� ����!");
		}
	}
	/* ������������� ���� */
	BASS_ChannelPlay(stream, TRUE);
	string butt = "||";
	while (true) {
		(*Menu).setKol(2);
		(*Menu)[0] = butt;
		(*Menu)[1] = "�����";
		(*Menu).DrawMenuH(3, 10, 5);
		switch ((*Menu).getLastClause()) {
		case 1: butt == "||" ? butt = "|>" : butt = "||";
			if (butt == "|>") {
				/* ������������� �������� */
				BASS_ChannelPause(stream);
			}
			else {
				/* ������������ �������� */
				BASS_ChannelPlay(stream, false);
			}
			break;
		case 2: 
			/* ������������� �������� */
			BASS_ChannelStop(stream);
			/* ����������� ������� */
			BASS_StreamFree(stream);
			return;
			break;
		}
	}
}

void Interface::AddSong()
{
	Song newSong;
	cout << "������� ����� / ������ �� �����: ";
	std::getline(cin,newSong.Location());

	ID3v2_tag* tag = load_tag(newSong.Location().c_str()); // Load the full tag from the file
	if (tag == NULL)
	{
		throw std::runtime_error("����, �������� ������������� ����� �������� ������!");
	}
	string o;

	ID3v2_frame* NameSong = tag_get_title(tag);
	if (NameSong != NULL) {
		ID3v2_frame_text_content* Namesongs = parse_text_frame_content(NameSong);
		o = Namesongs->data;
		o = o.substr(0, Namesongs->size);
		newSong.NameSong() = o;
	}


	ID3v2_frame* artist_frame = tag_get_artist(tag); 
	ID3v2_frame_text_content* Executor = parse_text_frame_content(artist_frame);
	o = Executor->data;
	if (Executor != NULL) {
		o = o.substr(0, Executor->size);
		newSong.Executor().Name() = o;
	}

	ID3v2_frame* Album = tag_get_album(tag);
	if (Album != NULL) {
		ID3v2_frame_text_content* Album_ = parse_text_frame_content(Album);
		o = Album_->data;
		o = o.substr(0, Album_->size);
		newSong.Album() = o;
	}

	ID3v2_frame* Compositer = tag_get_composer(tag);
	if (Compositer != NULL) {
		ID3v2_frame_text_content* Compositer_ = parse_text_frame_content(Compositer);
		o = Compositer_->data;
		o = o.substr(0, Compositer_->size);
		newSong.Compositer().Name() = o;
	}
	Archive->songs().Add(newSong);
	RedactSong(&Archive->songs()[Archive->songs().Find(newSong)]);
}


Interface::~Interface()
{
	(*Archive).saveArchive();
	Menu.reset();
	Archive.reset();
}
