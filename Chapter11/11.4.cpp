#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

string& process(string& word)
{
	for (char& ch : word)
	{
		if (isupper(ch)) ch = tolower(ch);
	}
	if (word[word.size()-1] == '.' || word[word.size()-1] == ',')
		word.resize(word.size()-1);
	return word;
}

int main()
{
	ifstream ifs("words");
	map<string, size_t> word_count;
	string word;
	while (ifs >> word)
	{
		++word_count[process(word)];
	}
	for (auto a_word : word_count)
	{
		cout << a_word.first << " " << a_word.second << endl;
	}
}