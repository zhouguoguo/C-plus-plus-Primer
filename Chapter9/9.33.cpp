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
	vector<int> vec = {1,2,3,4,5};
	print(vec);
	auto iter = vec.cbegin();
	while (iter != vec.cend()) {
		iter = vec.insert(iter+1, *iter);
		++iter;
		cout<<*iter<<endl;
	}
	print(vec);
	return 0;
}