#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	list<int> lst = {1, 0, 3, 5, 0, 2, 5, 11,9};
	auto it = find(lst.rbegin(), lst.rend(), 0);
	cout << *it << endl;
	return 0;
}