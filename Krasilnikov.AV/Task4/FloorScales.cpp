#include "FloorScales.h"


//  онструктор
FloorScales::FloorScales(string _start)
{
	start = _start;
	count_people = 0;

}

//  онструктор копировани¤
FloorScales::FloorScales(const FloorScales & fs)
{
	start = fs.start;
	count_people = fs.count_people;
	people = fs.people;
	name = fs.name;
}

// ћетод добавл¤ющий человека
void FloorScales::add_person(string _name)
{
	for (int i = 0; i < name.size(); i++) {	// ѕровер¤м, не добвлен ли человек уже
		if (name[i] == _name) {
			throw exception("„еловек уже добавлен");
		}
	}
	name.push_back(_name);	// ƒобавл¤ем человека
	people.push_back(MyVector<Event>(0));
	count_people++;
}

// ‘ункци¤ возвращает начальную дату
string FloorScales::get_start()
{
	return start;
}

// ‘ункци¤ задаЄт взвешивание по имени и дате
void FloorScales::add_event(string _name, int day, int month, int year, int weight)
{
	int it = -1;
	for (int i = 0; i < name.size(); i++) {		// »щем человека в векторе
		if (_name == name[i]) {
			it = i;
		}
	}
	if (it == -1) {
		throw exception("„еловек не найден");
	}
	for (int i = 0; i < people[it].size(); i++) {	// ѕровер¤м, не добавленна ли дата ранее
		if (people[it][i].check_time(day, month, year) == true) {
			people[it][i].set_weight(weight);	// ≈сли была добавленна, то обновл¤ем
			return;
		}
	}
	people[it].push_back(Event(day, month, year, weight));	// ≈сли взвешивани¤ с такой датой нет, то добавл¤ем
}

// ‘ункци¤ возвращает вес по дате
double FloorScales::get_event(string _name, int day, int month, int year)
{
	int it = -1;
	for (int i = 0; i < name.size(); i++) {	// »щем человека в векторе
		if (_name == name[i]) {
			it = i;
		}
	}
	if (it == -1) {
		throw exception("„еловек не найден");
	}
	for (int i = 0; i < people[it].size(); i++) {	// »щем событие
		if (people[it][i].check_time(day, month, year) == true) {
			return people[it][i].get_weight();
		}
	}
	throw exception("—обытие на найдено");
}

// ‘ункци¤ возвращает средний вес дл¤ определЄнного человека за указынй мес¤ц и год
double FloorScales::average_weight(string _name, int month, int year)
{
	int q = -1;
	for (int i = 0; i < count_people; i++) {
		if (name[i] == _name) {
			q = i;
			break;
		}
	}
	if (q == -1) {
		throw exception("„еловек не найден");
	}
	double ans = 0;
	int count = 0;
	for (int i = 0; i < people[q].size(); i++) {
		if (people[q][i].check_month(month, year) == true) {
			ans += people[q][i].get_weight();
			count++;
		}
	}
	ans /= count;
	return ans;
}

// ‘ункци¤ возвращает средний вес дл¤ определЄнного человека за всЄ врем¤
double FloorScales::average_weight(string _name)
{
	int q = -1;
	for (int i = 0; i < count_people; i++) {
		if (name[i] == _name) {
			q = i;
			break;
		}
	}
	if (q == -1) {
		throw exception("„еловек не найден");
	}
	double ans = 0;
	int count = 0;
	for (int i = 0; i < people[q].size(); i++) {
		ans += people[q][i].get_weight();
		count++;
	}
	ans /= count;
	return ans;
}

// ‘ункци¤ возвращает максимальный вес дл¤ определЄнного человека за указынй мес¤ц и год и дату
pair<double, string> FloorScales::max_weight(string _name, int month, int year)
{
	int q = -1;
	for (int i = 0; i < count_people; i++) {
		if (name[i] == _name) {
			q = i;
			break;
		}
	}
	if (q == -1) {
		throw exception("„еловек не найден");
	}
	pair<double, string> ans({ 0, "NULL" });
	for (int i = 0; i < people[q].size(); i++) {
		if (people[q][i].get_weight() >= ans.first && people[q][i].check_month(month, year) == true) {
			ans.first = people[q][i].get_weight();
			ans.second = people[q][i].get_date();
		}
	}
	return ans;
}

// ‘ункци¤ возвращает максимальный вес дл¤ определЄнного человека за всЄ врем¤ и дату
pair<double, string> FloorScales::max_weight(string _name)
{
	int q = -1;
	for (int i = 0; i < count_people; i++) {
		if (name[i] == _name) {
			q = i;
			break;
		}
	}
	if (q == -1) {
		throw exception("„еловек не найден");
	}
	pair<double, string> ans({ 0, "NULL" });
	for (int i = 0; i < people[q].size(); i++) {
		if (people[q][i].get_weight() >= ans.first) {
			ans.first = people[q][i].get_weight();
			ans.second = people[q][i].get_date();
		}
	}
	return ans;
}

// ‘ункци¤ возвращает минимальный вес дл¤ определЄнного человека за указынй мес¤ц и год и дату
pair<double, string> FloorScales::min_weight(string _name, int month, int year)
{
	int q = -1;
	for (int i = 0; i < count_people; i++) {
		if (name[i] == _name) {
			q = i;
			break;
		}
	}
	if (q == -1) {
		throw exception("„еловек не найден");
	}
	pair<double, string> ans({ 1000000000.0, "NULL" });
	for (int i = 0; i < people[q].size(); i++) {
		if (people[q][i].get_weight() <= ans.first && people[q][i].check_month(month, year) == true) {
			ans.first = people[q][i].get_weight();
			ans.second = people[q][i].get_date();
		}
	}
	return ans;
}

// ‘ункци¤ возвращает минимальный вес дл¤ определЄнного человека за всЄ врем¤ и дату
pair<double, string> FloorScales::min_weight(string _name)
{
	int q = -1;
	for (int i = 0; i < count_people; i++) {
		if (name[i] == _name) {
			q = i;
			break;
		}
	}
	if (q == -1) {
		throw exception("„еловек не найден");
	}
	pair<double, string> ans({ 1000000000.0, "NULL" });
	for (int i = 0; i < people[q].size(); i++) {
		if (people[q][i].get_weight() <= ans.first) {
			ans.first = people[q][i].get_weight();
			ans.second = people[q][i].get_date();
		}
	}
	return ans;
}

// ¬ывод в поток
ostream& operator<<(ostream& stream, const FloorScales& fs)
{
	stream << fs.start << endl << fs.count_people;
	for (int i = 0; i < fs.count_people; i++) {
		stream << fs.name[i] << endl << fs.people[i].size();
		for (int j = 0; j < fs.people[i].size(); j++) {
			stream << fs.people[i][j] << ' ';
		}
	}
	return stream;
}

// ¬вод в поток
istream& operator>>(istream& stream, FloorScales& fs)
{
	stream >> fs.start >> fs.count_people;
	fs.name.resize(fs.count_people);
	for (int i = 0; i < fs.count_people; i++) {
		int s;
		stream >> fs.name[i] >> s;
		fs.people[i].resize(s);
		for (int j = 0; j < fs.people[i].size(); j++) {
			stream >> fs.people[i][j];
		}
	}
	return stream;
}

// ƒеструктор
FloorScales::~FloorScales()
{
	start = nullptr;
	count_people = NULL;
}
