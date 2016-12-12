#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
	int a[] = {1,2,3,4,5};
	vector<int> va(begin(a), end(a));
	for (auto &i : va) {
		cout << i << " ";
		i = 0;
	}
	cout << endl;

	int b[5];
	for (int j = 0; j < 5; j ++) {
		b[j] = va[j];
		cout << b[j] << endl;
	}

	
}