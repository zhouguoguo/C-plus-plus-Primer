#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& a, vector<int>::iterator it)
{
	if (it != a.end()) {
		cout << *it << endl;
		++it;
		print(a, it);
	}
}

int main()
{
	vector<int> arr = {1,3,5,7,9,11,13};

	print(arr, arr.begin());

	return 0;
}