#include <vector>
#include <iostream>
using namespace std;

vector<int>::iterator find(vector<int>::iterator b, 
						   vector<int>::iterator e, 
						   int value)
{
	while (b != e) {
		if (*b == value) return b;
		++b;
	}
	return e;
}

int main()
{
	vector<int> vec = {0,2,4,6,8,10};

	int value = 10;
	
	vector<int>::iterator r = find(vec.begin(), vec.end(), value);

	if (r == vec.end()) {
		cout << "no data " << value;
	}
	else {
		cout << "Found " << *r << endl;
	}
	
	return 0;
}