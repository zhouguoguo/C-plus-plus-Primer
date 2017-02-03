#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void print_set(const multiset<string>& s)
{
	for (auto p : s)
	{
		cout << p << " ";
	}
	cout << endl;
}

void print_vec(const vector<string>& s)
{
	for (auto p : s)
	{
		cout << p << " ";
	}
	cout << endl;
}

int main()
{
	multiset<string> mt_set = {"pen", "apple", "pineapplepen"};
	vector<string> vec = {"good", "nice", "zoo", "app"};
	copy(vec.begin(), vec.end(), inserter(mt_set, mt_set.end()));
	print_set(mt_set);

//	copy(vec.begin(), vec.end(), back_inserter(mt_set));
	copy(mt_set.begin(), mt_set.end(), inserter(vec, vec.end()));
	print_vec(vec);

	copy(mt_set.begin(), mt_set.end(), back_inserter(vec));
	print_vec(vec);
}