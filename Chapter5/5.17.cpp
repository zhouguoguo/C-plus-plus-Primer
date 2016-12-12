#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a = {1,2,3,4};
	vector<int> b = {1};
	decltype(a.size()) a_size = a.size(), b_size = b.size();
	cout << a_size << endl;
	cout << b_size << endl;

	decltype(a_size) len = a_size >= b_size ? b_size : a_size;
	for (; len > 0 ; --len)
	{
		if (a[len-1] != b[len-1]) {
			break;
		}
	}
	if (len == 0) {
		cout << "True" << endl;
	}
	else
		cout << "False" << endl;
	return 0;
}