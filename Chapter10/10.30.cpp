#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	istream_iterator<int> is_it(cin), eof;

	vector<int> vec(is_it, eof);
	sort(vec.begin(), vec.end());

	ostream_iterator<int> os_it(cout, " ");
	unique_copy(vec.begin(), vec.end(), os_it);
}