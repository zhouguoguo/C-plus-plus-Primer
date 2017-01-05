#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<string>& vec)
{
	for (auto str : vec)
	{
		cout << str << endl;
	}
	cout << endl;
}

int main()
{
	vector<string> vec;
	ifstream ifs("words");
	string str;
	while (ifs >> str) {
		vec.push_back(str);
	}
	print(vec);

	sort(vec.begin(), vec.end());
	print(vec);
	auto end_unique = unique(vec.begin(), vec.end());
	print(vec);
	vec.erase(end_unique, vec.end());
	print(vec);
}