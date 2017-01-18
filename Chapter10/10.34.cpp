#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	vector<int> vec = {0,1,3,5,6,7,8,100};
	vector<int>::const_reverse_iterator rit = vec.crbegin();
	ostream_iterator<int> ost(cout, " ");
	copy(rit, vec.crend(), ost);
	return 0;
}