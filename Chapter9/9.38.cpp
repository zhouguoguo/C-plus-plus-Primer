#include <iostream>
#include <vector>

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
	print(vec);
	vec.push_back(1);
	print(vec);
	vec.resize(11, 2);
	print(vec);
	vec.resize(6);
	print(vec);
	vec.resize(12);
	print(vec);
	vec.resize(50);
	print(vec);
	vec.push_back(1);
	print(vec);
	vec.shrink_to_fit();
	print(vec);
	vec.push_back(1);
	print(vec);
	return 0;
}