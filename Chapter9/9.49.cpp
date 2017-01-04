#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void print(vector<string> strList)
{
	for (auto str : strList)
	{
		cout << str << endl;
	}
}

void process(const vector<string>& strList)
{
	string ascender = "bdfhiklt";
	string descender = "gjpqy";
	string::size_type max_len = 0;
	string res;
	for (auto str : strList)
	{
		if (str.find_first_of(ascender) == string::npos &&
			str.find_first_of(descender) == string::npos)
		{
			if (max_len < str.size())
			{
				max_len = str.size();
				res = str;
			}
		}

	}
	cout << "result: " << res << endl;
}

int main()
{
	vector<string> wordList;
	string str;
	ifstream ifs("word");
	while (ifs >> str)
	{
		wordList.push_back(str);
	}
	process(wordList);
//	print(wordList);
	return 0;
}