#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
	
	ifstream ifs("numbers");
	istream_iterator<int> is_it(ifs), eof;

	vector<int> vec(is_it, eof);

	ostream_iterator<int> os_it(cout, " ");
	copy(vec.begin(), vec.end(), os_it);
}