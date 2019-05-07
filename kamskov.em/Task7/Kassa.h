#pragma once
using namespace std;
class Tovar {
private:
	int code; // Shtrih kod
	string name; // Nazvanie
	int price; // Cena 
	int skidka; // Skidka
	int count; // Kolichestvo
public:
	//konstruktori ---------------------------------
	Tovar(void); // konstruktor po ymolchaniuy
	Tovar(int, string, int, int, int); // konstruktor inicializacii
	~Tovar(); // destruktor
	//----------------------------------------------
	bool Codecheck(int); // 
	// operacii vvoda/vivoda v potok ---------------
	friend ostream & operator << (ostream & stream, const Tovar &);
	friend istream & operator >> (istream & stream, Tovar &);
	//----------------------------------------------
	friend class Kassa;
};
class Kassa {
private:
	int buf; // massiv s zapasom
	static const int del = 10; // delta
	int size; // kol-vo tovarov
	Tovar* tovar; // massiv tovarov
public:
	//konstruktori ---------------------------------
	Kassa(void); // konstruktor po ymolchaniuy
	Kassa(int); // konstruktor inicializacii
	~Kassa(); // destruktor
	//----------------------------------------------
	Tovar Info(int); // informaciya o tovare (polychaet shtrih kod tovara)
	int Scan(int); // skanirovanie tovara (polychenie ego indeksa d massive cherez ego shtrih kod)
	bool Delete(int); // ydalenie tovara iz korziny (polychaet shtrih kod tovara)
	void CreateCheck(); // sozdanie checka 
	bool Add(int); // dobavlenie tovara v korziny (polychaet shtrih kod tovara)
	// operacii vvoda/vivoda v potok ---------------
	friend ostream & operator << (ostream & stream, Kassa const &);
	friend istream & operator >> (istream & stream, Kassa &);
};