#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> words;
	ifstream ifs("words");
	string str;
	while (ifs >> str) {
		words.push_back(str);
	}
	ostream_iterator<string> osit(cout, "\n");

	set<string> words_set(words.begin(), words.end());
	copy(words_set.begin(), words_set.end(), osit);

	cout << endl;

	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
	copy(words.begin(), words.end(), osit);
}