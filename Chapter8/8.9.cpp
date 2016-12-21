#include <iostream>
#include <sstream>
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
	istringstream istr("Hello Hi");
	input(istr);

	return 0;
}