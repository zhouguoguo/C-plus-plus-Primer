#include <vector>
#include <list>
#include <iostream>
using namespace std;

void print(const vector<int>& vec)
{
	for (auto v : vec)
	{
		cout << v << endl;
	}
}

void compare(const vector<int>& a1, const vector<int>& a2)
{
	if (a1 < a2) cout << "a1 < a2\n";
	else if (a1 == a2) cout << "a1 == a2\n";
	else cout << "a1 > a2\n";
}

int main()
{
	vector<int> a1(5, 1), a2(6, 0);
	compare(a1, a2);

	list<int> b1(5, 1);
	a2.assign(b1.cbegin(), b1.cend());
	compare(a1, a2);

	return 0;
}