#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
	ifstream ifs("words");
	map<string, size_t> word_count;
	string word;
	while (ifs >> word)
	{
		++word_count[word];
	}
	for (auto a_word : word_count)
	{
		cout << a_word.first << " " << a_word.second << endl;
	}
}