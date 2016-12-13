#include <iostream>
#include <vector>
using namespace std;

void PrintV(vector<int>& a, vector<int>::iterator it)
{
#ifndef NDEBUG
	static int cnt = 0;
	++cnt;
	cout << "Current cnt : " << cnt << endl;
	if (cnt > 30) return;
#endif
	if (it != a.end())
	{
		cout << *it++ << endl;
		PrintV(a, it);
	}
}

void PrintV2(vector<int> a)
{
#ifndef NDEBUG
	static int cnt = 0;
	++cnt;
	cout << "Call " << __FUNCTION__ << " " << cnt << " times" << endl; 
	cout << "Size of vector:" << a.size() << endl;
#endif
	if (a.size() == 1) {
		cout << a[0] << endl;
		return;
	}
	if (a.size() > 1) {
		int tail = a.back();
		a.pop_back();
		PrintV2(a);
		cout << tail << endl;
	}
}

int main()
{
	vector<int> intV = {1,2,3,4,5,6,7};
	PrintV(intV, intV.begin());
	PrintV2(intV);
	return 0;
}