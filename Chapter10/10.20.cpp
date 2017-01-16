#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

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

void elimDups(vector<string>& words)
{
	sort(words.begin(), words.end());
	auto it = unique(words.begin(), words.end());
	words.erase(it, words.end());
}

void biggest(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(),
				[] (const string& a, const string &b) 
				{return a.size() < b.size();});
	auto it = find_if(words.begin(), words.end(), 
					  [sz](const string& str)
					  {return str.size() >= sz;});
//	auto count = words.end() - it;
	auto count = count_if(words.begin(), words.end(),
						  [sz](const string& str) 
						  {return str.size() >= sz;});
	cout << count << endl;
	for_each(it, words.end(), 
			 [](const string& str)
			 {cout << str << endl;});
}

int main()
{
	vector<string> words;
	input(words);
// 	output(words);
	biggest(words, 6);
	return 0;
}