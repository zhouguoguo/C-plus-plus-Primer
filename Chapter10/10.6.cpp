#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

void print(const vector<int>& vint)
{
	for (auto i : vint) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vint(10,1);
	fill_n(vint.begin(), vint.size(), 0);
	print(vint);

	vector<int> vec;
	vec.reserve(10);
	list<int> lst;
	int i;
	while(cin >> i) {
		lst.push_back(i);
	}
	copy(lst.begin(), lst.end(), vec.begin());
	print(vec);
}