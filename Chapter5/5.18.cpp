#include <iostream>
#include <vector>
using namespace std;

int getIntPlusOne(int a)
{
	return a + 1;
}

int main()
{
	do {
		int v1, v2;
		cout << "pls input two integers:\n";
		if (cin >> v1 >> v2)
		{
			cout << v1 + v2 << endl;
		}
	}
	while (cin);

	int t = -5;
	int a;
	do {
		a = getIntPlusOne(t);
		++t;
		cout << "One";
	} while(a);
	return 0;
}