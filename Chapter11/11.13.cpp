#include <utility>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream ifs("12.input");
	vector<pair<string, int>> vec;

	/*1
	pair<string, int> p;
	while (ifs >> p.first >> p.second)
	{
		vec.push_back(p);
	}
*/

	/*2
	string str;
	int i;
	while (ifs >> str >> i)
	{
		vec.push_back(make_pair(str, i));
	}
*/
	string str;
	int i;
	while (ifs >> str >> i)
	{
		pair<string, int> p = {str, i};
		vec.push_back(make_pair(str, i));
	}

	for (auto v : vec) {
		cout << v.first << " " << v.second << endl;
	}
}