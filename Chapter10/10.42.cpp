#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

bool compare(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

int main()
{
	list<string> words;
	ifstream ifs("words");
	string str;
	while (ifs >> str)
	{
		words.push_back(str);
	}
	ostream_iterator<string> osit(cout, "\n");
	copy(words.begin(), words.end(), osit);
	cout << "\nafter sort:" << endl;
	words.sort();
	copy(words.begin(), words.end(), osit);

	cout << "\nafter unique:" << endl;
	words.unique();
	copy(words.begin(), words.end(), osit);

	cout << "\nafter sort by length:" << endl;
	words.sort(compare);
	copy(words.begin(), words.end(), osit);
}