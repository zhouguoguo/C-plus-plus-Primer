#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int>& vint)
{
	for (auto iter = vint.cbegin(); iter != vint.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vec = {2,4,6,8,0,1};
	// infinit loop when met the first odd number
	print(vec);
	auto iter = vec.cbegin();
	while (iter != vec.cend()) {
		if (*iter % 2)
			iter = vec.insert(iter, *iter);
		++iter;
	}
	print(vec);
	return 0;
}