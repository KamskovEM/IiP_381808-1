#pragma once
#include <string>

class Octal
{
public:

	//Конструктор по-умолчанию
	Octal(); 

	//Конструктор 
	explicit Octal(unsigned int);

	//Констурктор копирования
	Octal(const Octal&);

	//Конструтор преобразования типа из строки
	Octal(std::string);

	//Перегрузка операторов
	Octal operator+(const Octal&);
	Octal operator-(const Octal&);
	Octal operator*(const Octal&) const;
	Octal& operator=(const Octal&);

	bool operator>(const Octal&);
	bool operator<(const Octal&);
	bool operator==(const Octal&);
	   
	//Деструктор
	~Octal();

	unsigned int GetLength() { return length; };

	friend std::ostream& operator<<(std::ostream&, const Octal&);
	friend std::istream& operator>>(std::istream&, Octal&);

private:
	unsigned char* number;
	int length;

	void Shift(int);//Операция сдвига влево (требуется для умножения)
	void ToZero(); //Операция обнуления
};

std::ostream& operator<<(std::ostream&, const Octal&);
std::istream& operator>>(std::istream&, Octal&);

