#include <iostream>

using namespace std;

string& process(string& name, const string& prefix, const string& postfix)
{
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(postfix);
	return name;
}

int main()
{
	string n = "Lanmon";
	cout << n << endl;
	cout << process(n, "Mr.", "Jr.") << endl;
}