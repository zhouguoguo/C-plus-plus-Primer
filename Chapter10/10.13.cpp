#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<string>::iterator iter1, 
		   vector<string>::iterator iter2)
{
	while (iter1 != iter2) {
		cout << *iter1 << endl;
		++iter1;
	}
	cout << endl;
}

void input(vector<string>& vec)
{
	ifstream ifs("words");
	string str;
	while (ifs >> str) {
		vec.push_back(str);
	}
}

bool moreThanFive(const string& str)
{
	return str.size() >= 5 ? true : false;
}

int main()
{
	vector<string> vec;
	input(vec);
	print(vec.begin(), vec.end());

	auto it = partition(vec.begin(), vec.end(), moreThanFive);
	print(vec.begin(), vec.end());
	print(vec.begin(), it);

}