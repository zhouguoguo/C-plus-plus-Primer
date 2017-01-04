#include <iostream>

using namespace std;

void process(string& s, const string& oldValue, const string& newValue)
{
	auto len_o = oldValue.size();
	auto len_n = newValue.size();
	string::size_type pos = 0;

	while (pos != s.size())
	{
		pos = s.find(oldValue);
		s.replace(pos, len_o, newValue);
		pos += len_n;
	}
}

int main()
{
	string s = "Walk thru the rain.thru thru";
	cout << s << endl;
	process(s, "thru", "through");
	cout << s << endl;
}