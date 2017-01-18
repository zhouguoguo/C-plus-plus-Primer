#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
	vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
	list<int> lst;
	lst.resize(5);
	auto b = vec.rbegin() + 3, e = vec.rend() - 2;
	copy(b, e, lst.begin());
	ostream_iterator<int> osit(cout, " ");
	copy(lst.begin(), lst.end(), osit);
}