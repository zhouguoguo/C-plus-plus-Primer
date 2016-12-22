#include <vector>
#include <iostream>
using namespace std;

bool find(vector<int>::iterator b, vector<int>::iterator e, int value)
{
	while (b != e) {
		if (*b == value) return true;
		++b;
	}
}

int main()
{
	vector<int> vec = {0,2,4,6,8,10};
	bool found = false;
	found = find(vec.begin(), vec.end(), 5);
	cout << found << endl;
	return 0;
}