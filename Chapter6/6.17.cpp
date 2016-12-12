#include <iostream>
#include <string>

using namespace std;

bool containUppercase(const string& str)
{
	for (auto c : str) {
		if (isupper(c)) {
			return true;
		}
	}
	return false;
}

void toLowercase(string& str)
{
	for (auto &c : str) {
		c = tolower(c);
	}
}

int main()
{
	string s;
	cin >> s;
	if (containUppercase(s)) {
		toLowercase(s);
		cout << s << endl;
	}
	
	return 0;
}