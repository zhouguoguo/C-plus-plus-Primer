#include <map>
#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

void read(multimap<string, string>& maptt)
{
	ifstream ifs("works");
	string authod, work;
	while (ifs >> authod >> work) {
		maptt.insert({authod, work});
	}
}

void print(const multimap<string, string>& maptt)
{
	for (auto m : maptt) {
		cout << m.first << " " << m.second << endl;
	}
}

int main()
{
	multimap<string, string> maptt;
	read(maptt);
	print(maptt);
	cout << endl;

	auto p = maptt.equal_range("Mary");
	auto it = maptt.erase(p.first, p.second);
	print(maptt);
	cout << endl;

	auto p1 = maptt.equal_range("Mary");
	auto it1 = maptt.erase(p1.first, p1.second);
	print(maptt);
	cout << endl;
}