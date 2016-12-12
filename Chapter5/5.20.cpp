#include <iostream>
#include <string>
using namespace std;

int main()
{
	string cur;
	string last;
	while (cin >> cur) {
		if (!isupper(cur[0])) continue;
		if (last == cur) {
			cout << "redundant " << last << endl;
			break;
		}
		else {
			last = cur;
		}
	}
	return 0;
}