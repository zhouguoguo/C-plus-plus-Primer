#include <map>
#include <iostream>
#include <fstream>

using namespace std;

void print_map(const map<string, unsigned>& words)
{
	for (auto w : words)
	{
		cout << w.first << " " << w.second << endl;
	}
}

int main()
{
	map<string, unsigned> words;
	ifstream ifs("words");
	string str;
	int i = 1;
	while (ifs >> str) {
		++words.insert({str, 0}).first->second;
	}
	print_map(words);
}