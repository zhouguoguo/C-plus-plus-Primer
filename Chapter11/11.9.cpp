#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void read(map<string, list<unsigned>>& words)
{
	ifstream ifs("words");
	string str;
	while (getline(ifs, str)) {
		istringstream istr(str);
		string word;
		istr >> word;
		unsigned line;
		
		while (istr >> line) {
			words[word].push_back(line);
		}
	}
}

void print(const map<string, list<unsigned>>& words)
{
	for (auto record : words) {
		cout << record.first << " ";
		auto it = record.second.begin();
		for (; it != record.second.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

int main()
{
	map<string, list<unsigned>> words;
	
	read(words);
	print(words);

	return 0;
}