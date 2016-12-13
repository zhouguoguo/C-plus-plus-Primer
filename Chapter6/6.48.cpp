#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	string s;
	string sought = "ok";

	// keep input string until input "ok"
	while (cin >> s && s != sought) {}

	// if invalid input
	assert(cin);

	return 0;
}