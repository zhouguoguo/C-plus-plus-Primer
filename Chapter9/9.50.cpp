#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> ivec = {"123","123","100000"};
	int i = 0;
	for (auto str : ivec)
	{
		i += stoi(str);
	}
	cout << i << endl;

	vector<string> dvec = {"0.123","123.1","1000.99"};
	double d = 0.0;
	for (auto str : dvec)
	{
		d += stod(str);
	}
	cout << d << endl;
}