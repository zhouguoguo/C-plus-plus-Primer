#include <iostream>

using namespace std;

string& process(string& name, const string& prefix, const string& postfix)
{
	name.insert(0, prefix);
	name.insert(name.size(), postfix);
	return name;
}

int main()
{
	string n = "Lanmon";
	cout << n << endl;
	cout << process(n, "Mr.", "Jr.") << endl;
}