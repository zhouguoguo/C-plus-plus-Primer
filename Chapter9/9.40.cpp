#include <iostream>
#include <vector>

using namespace std;

void print(const vector<string>& vec)
{
	for (auto a : vec) {
		cout << a << " ";
	}
	cout << "\nvec.size = " << vec.size()
		 << " vec.capacity = " << vec.capacity() << endl;
}

int main()
{
	vector<string> vec;
	vec.reserve(1024);

	vec.resize(1048, "h");
	print(vec);

	vec.resize(vec.size() + vec.size()/2);
	print(vec);

	return 0;
}