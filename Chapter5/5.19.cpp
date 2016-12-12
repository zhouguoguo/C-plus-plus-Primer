#include <iostream>

using namespace std;

int main()
{
	string s, t;
	do {
		cout << "Input two strings:\n";
		cin >> s >> t;
		if (s.size() < t.size()) {
			cout << s << endl;
		}
		else {
			cout << t << endl;
		}
	} while (cin) ;
	return 0;
}