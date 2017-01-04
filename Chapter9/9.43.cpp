#include <iostream>

using namespace std;

void process(string& s, const string& oldValue, const string& newValue)
{
	auto len = oldValue.size();
	auto it = s.begin();
	int flag = 0;
	while (it != s.end())
	{
		string sub(it, it+len);
		if (sub == oldValue) {
			it = s.erase(it, it+len);
			s.insert(it, newValue.cbegin(), newValue.cend());
			it = s.begin();

		}
		else {
			++it;
		}
	}
}

int main()
{
	string s = "Walk thru the rain.thru";
	cout << s << endl;
	process(s, "thru", "through");
	cout << s << endl;
}