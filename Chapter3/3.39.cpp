#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 > s2) {
		cout << "s1 is larger" << endl;
	}
	else if (s1 < s2) {
		cout << "s2 is larger" << endl;
	}
	else {
		cout << "s1 and s2 are the same" << endl;
	}

	const char str1[] = "Hello";
	const char str2[] = "Hello";
	if (strcmp(str1, str2) > 0) {
		cout << "str1 is larger" << endl;
	}
	else if (strcmp(str1, str2) < 0) {
		cout << "str2 is larger" << endl;
	}
	else {
		cout << "str1 and str2 are the same" << endl;
	}
}