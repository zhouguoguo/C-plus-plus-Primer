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
//		++words[str];
		auto ret = words.insert(make_pair(str, 1));
		
//		cout << ret.first->first << endl;
		if (!ret.second) {
			++ret.first->second;
		}
	}
	print_map(words);
}