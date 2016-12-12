#include <iostream>
#include <vector>

using namespace std;

int main()
{
	constexpr int size = 5;
	int ia[size] = {1,2,3,4,5};

	for (int *ptr = ia, ix = 0; 
		ix != size && ptr != ia + size; 
		++ix, ++ptr) {
		cout << *ptr << endl;
		cout << ia[ix] << endl;
	}

	int x = 1;
	int y = 3;
	bool someValue = false;
	int e = (someValue ? ++x, ++y : --x, --y);
	cout << e << endl;
	return 0;
}