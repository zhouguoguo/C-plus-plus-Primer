#include <vector>
#include <iostream>

using namespace std;

vector<int>& alloc()
{
	vector<int> *vec = new vector<int>();
	return *vec;
}

void read(istream& cin, vector<int>& vec)
{
	int i;
	while (cin >> i)
	{
		vec.push_back(i);
	}
}

void print(const vector<int>& vec)
{
	for (auto v : vec)
	{
		cout << v << endl;
	}
}

int main()
{
	vector<int>& p = alloc();
	read(cin, p);
	print(p);
	delete &p;
}