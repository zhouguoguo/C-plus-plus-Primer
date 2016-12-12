#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i;
	double d;
	i = d = 3.5;
	cout << i << " " << d << endl;
	d = i = 3.5;
	cout << i << " " << d << endl;

	vector<string> s{"aaa","bbbb"};

	vector<string>::iterator it = s.begin();

	cout << it++->size() << endl;
	cout << (*it).size() << endl;

	return 0;
}