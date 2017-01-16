#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

void input(vector<string>& words)
{
	ifstream ifs("words");
	string str;
	while (ifs >> str)
	{
		words.push_back(str);
	}
}

void output(const vector<string>& words)
{
	for (auto str : words)
	{
		cout << str << endl;
	}
}

bool isShorter (const string& a, const string &b) 
{
	return a.size() < b.size();
}

bool partit(const string& str, vector<string>::size_type sz)
{
	return str.size() < sz;
}

void each_print(const string& str)
{
	cout << str << endl;
}

void biggest(vector<string>& words, vector<string>::size_type sz)
{
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());

	stable_sort(words.begin(), words.end(),
				bind(isShorter, _1, _2));
	it = stable_partition(words.begin(), words.end(), 
			  bind(partit, _1, sz));
	auto count = words.end() - it;
	cout << count << endl;
	for_each(it, words.end(), each_print);
}

int main()
{
	vector<string> words;
	input(words);
// 	output(words);
	biggest(words, 5);
	return 0;
}