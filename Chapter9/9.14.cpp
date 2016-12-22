#include <vector>
#include <list>
#include <iostream>
using namespace std;

void print(const vector<string>& vec)
{
	for (auto v : vec)
	{
		cout << v << endl;
	}
}

int main()
{
	list<const char*> lc = {"Hush,","baby's", "sleeping"};
	vector<string> vstr;
	vstr.assign(lc.cbegin(), lc.cend());
	print(vstr);
	return 0;
}