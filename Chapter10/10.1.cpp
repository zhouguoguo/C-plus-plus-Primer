#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	vector<int> vint;
	ifstream ifs("numbers");
	int i;
	while (ifs >> i)
	{
		vint.push_back(i);
	}
	cout << count(vint.cbegin(), vint.cend(), 100) << endl;
	return 0;
}