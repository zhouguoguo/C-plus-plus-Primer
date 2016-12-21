#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

void PrintInfo(const vector<PersonInfo>& persons)
{
	for (auto person : persons) {
		cout << person.name << " ";
		for (auto phone : person.phones) {
			cout << phone << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<PersonInfo> persons;
	ifstream ifs("infile");
	if (!ifs) {
		cout << "no data";
		return 1;
	}
	string line;
	while (getline(ifs, line)) {
		PersonInfo p;
		istringstream istr(line);
		istr >> p.name;
		string phone;
		while (istr >> phone) {
			p.phones.push_back(phone);
		}
		persons.push_back(p);
	}
	PrintInfo(persons);
	return 0;
}