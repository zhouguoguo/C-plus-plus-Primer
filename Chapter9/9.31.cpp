#include <vector>
#include <iostream>
#include <list>

using namespace std;

void print(const vector<int>& vint)
{
	for (auto iter = vint.cbegin(); iter != vint.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void process(vector<int>& vec)
{
	auto it = vec.begin();
	while (it != vec.end())
	{
		if (*it % 2 == 1) {
			it = vec.insert(it, *it);
			it += 2;
		}
		else {
			it = vec.erase(it);
		}
	}
}

void process(list<int>& lst)
{
	auto it = lst.begin();
	while (it != lst.end())
	{
		if (*it % 2 == 1) {
			it = lst.insert(it, *it);
			++it;
			++it;
		}
		else {
			it = lst.erase(it);
		}
	}
}

int main()
{
	vector<int> vec = {1,3,5,7,9};
	print(vec);
	process(vec);
	print(vec);

	vector<int> lst = {9,9,7,5,3,1};
	print(lst);
	process(lst);
	print(lst);

	
	return 0;
}