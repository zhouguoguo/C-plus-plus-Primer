#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	vector<string> vstr;
	ifstream ifs("numbers");
	string s;
	while (ifs >> s)
	{
		vstr.push_back(s);
	}
	cout << count(vstr.cbegin(), vstr.cend(), "100") << endl;
	return 0;
}