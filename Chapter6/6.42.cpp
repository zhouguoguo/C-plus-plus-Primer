#include <iostream>

using namespace std;

string make_plural(size_t str, const string &word, const string &ending = "s")
{
	return (str > 1) ? word + ending : word;
}

int main()
{
	cout << make_plural(1, "success") << endl;
	cout << make_plural(2, "success", "es") << endl;
	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "failure") << endl;
	return 0;
}