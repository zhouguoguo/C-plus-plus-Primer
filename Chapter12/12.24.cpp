#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string str;
	char* cstr = new char[10]();
	while (cin >> str) {
		strcpy(cstr, str.c_str());
		cout << cstr << endl;
	}
	delete[] cstr;
}