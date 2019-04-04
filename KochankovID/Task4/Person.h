#pragma once
#include <string>
#include <iostream>


class Person
{
public:
	// ������������ ----------------------------------------------------------
	// ����������� ������������� (� ��� �� �� ���������)
	Person(const std::string& Name_ = "����������", 
		const std::string& Female_ = "����������", 
		const std::string& Biography_ = "����������", 
		const int& Age_ = 0);
	// �������� ����� �������, ��� �� �� ������ 5 ����� ���������� �������������

	// ����������� �����������
	Person(const Person& copy);

	// ������ ������ ---------------------------------------------------------
	// ������ ������� � �������������� �����
	std::string& Name() { return name; };
	std::string& Female() { return female; };
	std::string& Biography() { return biography; };
	int& Age() { return age; };

	// ������ ������������ ������� 
	const std::string& Name() const { return name; };
	const std::string& Female() const { return female; };
	const std::string& Biography() const { return biography; };
	const int& Age() const { return age; };

	// ����� ���������� � �������� �� �������
	void OutPerson(const std::string& str = "") const;

	// ���������� ���������� -------------------------------------------------
	 // ���������� �������� ������ � �����
	friend std::ostream& operator<< (std::ostream& stream, const Person& C);

	// ���������� �������� ����� �� ������
	friend std::istream& operator>> (std::istream& stream, Person& C);

	// ���������� ��������� ������������
	Person* operator= (const Person& copy);

	// ���������� ��������� ���������
	bool operator== (const Person& p) const;

	// ����� ���������� ------------------------------------------------------
	class AgeError : public std::out_of_range { // ������ �������� (��������� �������� ���������� ������� ������)
	public:

		// ����������� ������ ����������
		AgeError(const std::string& Message_);

		// ���������� ������ ����������
		~AgeError();
	};

	// ���������� ------------------------------------------------------------
	~Person();
private:
	// ������� ���� ������ ---------------------------------------------------
	std::string name, // ���
		female, // �������
		biography; // ���������
	int age; // �������
};

// ��������� "������" �������
inline void Person::OutPerson(const std::string & str) const
{
	std::cout << str << name << ' ' << female << ' ' << age;
}