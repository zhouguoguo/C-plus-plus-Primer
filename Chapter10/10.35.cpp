#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	vector<int> vec = {0,1,3,5,6,7,8,100};
	vector<int>::const_iterator it = vec.cend();
	while (it != vec.cbegin()) {
		--it;
		cout << *it << " ";
	}
	return 0;
}