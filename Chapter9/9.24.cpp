#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vint = {2,3,4,5,6,7,8,9};
	cout << vint[0] << endl;
	cout << vint.at(0) << endl;
	cout << *vint.begin() << endl;
	cout << vint.front() << endl;
	return 0;
}