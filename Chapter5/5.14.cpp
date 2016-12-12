#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	string cur;
	unsigned cnt = 0;
	unsigned max = 1;
	string max_str;
	while (cin >> cur) {
		if (str == cur) {
			++cnt;
		}
		else {
			if (max < cnt) {
				max = cnt;
				max_str = str;
			}
			str = cur;
			cnt = 1;
		}
	}
	if (max > 1) {
		cout << max_str << endl;
		cout << max << endl;
	}
	else {
		cout << "No redundant data" << endl;
	}
	return 0;
}