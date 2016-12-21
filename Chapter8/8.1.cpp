#include <iostream>

using namespace std;

istream& input(istream& is)
{
	string s;
	while (is >> s) {
		cout << s << endl;
	}
	cout << is.rdstate() << endl;
	is.clear();
	cout << is.rdstate() << endl;
	return is;
}

int main()
{
	input(cin);
	return 0;
}