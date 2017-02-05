#include <vector>
#include <iostream>
#include <memory>

using namespace std;

shared_ptr<vector<int>> alloc()
{
	shared_ptr<vector<int>> vec = make_shared<vector<int>>();
	return vec;
}

void read(istream& cin, shared_ptr<vector<int>> vec)
{
	int i;
	while (cin >> i)
	{
		vec->push_back(i);
	}
}

void print(shared_ptr<vector<int>> vec)
{
	for (auto v : *vec)
	{
		cout << v << endl;
	}
}

int main()
{
	shared_ptr<vector<int>> sp = alloc();
	read(cin, sp);
	print(sp);
}