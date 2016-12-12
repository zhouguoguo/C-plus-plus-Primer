#include <iostream>

using namespace std;

int sum_li(initializer_list<int> li)
{
	int res = 0;
	for (auto be = li.begin(); be != li.end(); ++be)
	{
		res += *be;
	}
	return res;
}

int main()
{
	initializer_list<int> li = {1,2,3,4,5,6,7,8,9};

	cout << sum_li(li) << endl;

	for (const auto& i : li) {
		cout << i << endl;
		//i = 5;
	}

	return 0;
}