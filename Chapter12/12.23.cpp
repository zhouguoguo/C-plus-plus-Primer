#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char a[6] = "apple";
	char b[5] = "pens";

	char* c = new char[strlen(a) + strlen(b) + 1]();
	strcat(c, a);
	strcat(c, b);
	cout << c << endl;

	delete[] c;

	string a1 = "pineapple";
	string b1 = "pen";

	char* c1 = new char[a1.size() + b1.size() + 1]();
	strcat(c1, a1.c_str());
	strcat(c1, b1.c_str());
	cout << c1 << endl;

	delete[] c1;
}