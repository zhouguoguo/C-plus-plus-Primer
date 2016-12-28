#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int>& vec)
{
	for (auto a : vec) {
		cout << a << " ";
	}
	cout << "\nvec.size = " << vec.size()
		 << " vec.capacity = " << vec.capacity() << endl;
}

int main()
{
	vector<int> vec;
	vec.reserve(100);
	int i = 0;
	while (i < 100) {
		vec.push_back(i);
		++i;
	}
	print(vec);
	return 0;
}