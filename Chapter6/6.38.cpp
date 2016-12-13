#include <iostream>

using namespace std;

int odd[5] = {1,3,5,7,9};
int even[5] = {0,2,4,6,8};

decltype(odd) &arrPtr(int i)
{
	return (i % 2) ? odd : even;
}

int main()
{
	int val = 2;
	cout << arrPtr(val)[0] << endl;
	cout << arrPtr(val)[1] << endl;
	cout << arrPtr(val)[2] << endl;
	cout << arrPtr(val)[3] << endl;
	cout << arrPtr(val)[4] << endl;
	return 0;
}