#pragma once
#include <memory>
#include <iostream>

template<typename T>
class Collection
{
public:
	// ������������ ----------------------------------------------------------
	// ����������� �������������
	explicit Collection(const int& Count_);

	// ����������� �� ���������
	Collection();

	// ����������� �����������
	Collection(const Collection& copy);

	// ������ ������ ---------------------------------------------------------
	// ��������� ���������� ��������� ���������
	const int& Count() const { return count; };

	// ����� ������� ��������
	int Find(T& element) const;

	// ���������� �������� � ���������
	void Add(const T& element);

	// ���������� �������� � ���������
	void AddAt(const T& element, const int& pos);

	// �������� �������� �� ��������� 
	void Remove(T& element); 

	// �������� �������� �� ��������� �� �������
	void RemoveAt(const int& index);

	// ���������� ���������� ���������� ���������
	int Koll(const T& element) const;

	// ���������� ������ ��������� ���� �
	T* AsArray() { return sbornik._Myptr(); };

	// ���������� ���������� -------------------------------------------------
	// ���������� ��������� ��������������
	T& operator[](const int& i);

	// ���������� ��������� �������������� ��� ��������
	const T& operator[](const int& i) const;

	// ���������� ��������� ������������
	Collection<T>* operator= (const Collection<T>& copy);
	
	// ���������� �������� ������ � �����
	template <typename T1> friend std::ostream& operator<< (std::ostream& stream, const Collection<T1>& C);

	// ���������� �������� ����� �� ������
	template <typename T1> friend std::istream& operator>> (std::istream& stream, Collection<T1>& C); 

	// ���������� ------------------------------------------------------------
	~Collection<T>();

private:
	// ���� ������ -----------------------------------------------------------
	static const int BufPlace = 20; // ������ ������� ����������� ������
	int count; // ���������� ��������� � ��������
	int bufSize; // ������ ������ ������������� ������� ����������
	std::unique_ptr<T[]> sbornik; // "�����" ��������� �� ������������ ������ 
	//(�������� ����� �������� ������ ������ ��� ������ ���������� �� ������������ �)
	void IsInRange(const int& i) const; // �������� �� ��������� � ��������
	void bufAdd(); // ���������� ������ ���������
	void buffree(); // ���������� ������ ���������

};
// ���������� "������" �������

template<typename T>
Collection<T>::Collection(const int & Count_) :
	count(Count_),
	bufSize(count + BufPlace),
	sbornik(new T[bufSize])
{
}

template<typename T>
Collection<T>::Collection() :
	count(0),
	bufSize(BufPlace),
	sbornik(new T[BufPlace])
{
}

template<typename T>
Collection<T>::Collection(const Collection & copy): count(copy.count), 
	bufSize(copy.bufSize),
	sbornik(new T[bufSize])
{
	for (int i = 0; i < copy.Count(); i++) {
		sbornik[i] = copy.sbornik[i];
	}
}

template<typename T>
int Collection<T>::Find(T & element) const
{
	for (int i = 0; i < count; i++) {
		if (sbornik[i] == element) {
			return i;
		}
	}
	return -1;
}


template<typename T>
void Collection<T>::Add(const T & element)
{
	if (count == bufSize) {
		bufAdd();
	}
	sbornik[count] = element;
	count++;
}

template<typename T>
inline void Collection<T>::AddAt(const T & element, const int & pos)
{
	if (count == bufSize) {
		bufAdd();
	}
	for (int i = count; i > pos; i--) {
		sbornik[i] = sbornik[i - 1];
	}
	count++;
	sbornik[pos] = element;
}

template<typename T>
void Collection<T>::Remove(T & element)
{
	int pos = Find(element);
	for (int i = pos; i < count - 1; i++) {
		sbornik[i] = sbornik[i + 1];
	}
	count--;
	if ((bufSize - count) >= (2 * BufPlace)) {
		buffree();
	}
}

template<typename T>
inline void Collection<T>::RemoveAt(const int & index)
{
	for (int i = index; i < count - 1; i++) {
		sbornik[i] = sbornik[i + 1];
	}
	count--;
	if ((bufSize - count) >= (2 * BufPlace)) {
		buffree();
	}
}

template<typename T>
int Collection<T>::Koll(const T & element) const
{
	int kol = 0;
	for (int i = 0; i < count; i++) {
		if (sbornik[i] == element) {
			kol++;
		}
	}
	return kol;
}

template<typename T>
T & Collection<T>::operator[](const int & i)
{
	IsInRange(i);
	return sbornik[i];
}

template<typename T>
const T & Collection<T>::operator[](const int & i) const
{
	IsInRange(i);
	return sbornik[i];
}

template<typename T>
Collection<T>* Collection<T>::operator=(const Collection<T>& copy)
{
	count = copy.count;
	bufSize = copy.bufSize;
	sbornik.reset(new T[bufSize]);
	for (int i = 0; i < count; i++) {
		sbornik[i] = copy.sbornik[i];
	}
	return this;
}

template<typename T>
Collection<T>::~Collection()
{
	sbornik.reset();
}

template<typename T>
void Collection<T>::IsInRange(const int & i) const
{
	if ((i < 0) || (i >= count)) {
		throw std::out_of_range("������ ��������� ��� ������ �������!");
	}
}

template<typename T>
void Collection<T>::bufAdd()
{
	bufSize += BufPlace;
	std::unique_ptr<T[]> copy(new T[bufSize]);

	for (int i = 0; i < count; i++) {
		copy[i] = sbornik[i];
	}
	sbornik = std::move(copy);
}

template<typename T>
inline void Collection<T>::buffree()
{
	bufSize -= BufPlace;
	std::unique_ptr<T[]> copy(new T[bufSize]);

	for (int i = 0; i < count; i++) {
		copy[i] = sbornik[i];
	}
	sbornik = std::move(copy);
}


template<typename T>
std::ostream & operator<<(std::ostream & stream, const Collection<T> & C)
{
	stream << C.count << ' ' << C.bufSize << std::endl;
	for (int i = 0; i < C.count; i++) {
		stream << C.sbornik[i] << std::endl;
	}
	return stream;
}

template<typename T>
std::istream & operator>>(std::istream & stream, Collection<T> & C)
{
	stream >> C.count;
	stream >> C.bufSize;
	C.sbornik.reset(new T[C.bufSize]);
	for (int i = 0; i < C.count; i++) {
		stream >> C.sbornik[i];
	}
	return stream;
}

