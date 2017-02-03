#include <utility>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	vector<pair<string, int>> vec;
	pair<string, int> p;
	ifstream ifs("12.input");
	while (ifs >> p.first >> p.second)
	{
		vec.push_back(p);
	}
	for (auto v : vec) {
		cout << v.first << " " << v.second << endl;
	}
}