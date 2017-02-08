#include <memory>
#include <iostream>

using namespace std;

int main()
{
	allocator<string> allc;
	int n = 10;
	string* p = allc.allocate(n);
	string* q = p;
	string s;
	while (cin >> s && q != p + n) {
		allc.construct(q, s);
		cout << *q << endl;
		++q;
	}
	while (q != p) {
		allc.destroy(--q);
	}
	allc.deallocate(p, n);
}