#include <iostream>

using namespace std;

int main()
{
	char ch;
	unsigned int cnt = 0;
	while (cin >> ch) {
		if (ch == 'a') ++cnt;
		else if (ch == 'e') ++cnt;
		else if (ch == 'i') ++cnt;
		else if (ch == 'o') ++cnt;
		else if (ch == 'u') ++cnt;
	}
	cout << cnt << endl;
	return 0;
}