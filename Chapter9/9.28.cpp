#include <iostream>
#include <forward_list>

using namespace std;

void print(const forward_list<string>& il)
{
	for (auto iter = il.cbegin(); iter != il.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void insert(forward_list<string>& fl, const string& s1, const string& s2)
{
	auto curr = fl.begin();
	auto pre = curr;
	while (curr != fl.end())
	{
		if (*curr == s1) {
			pre = curr;
			curr = fl.insert_after(curr, s2);
			return;
		}
		else {
			pre = curr;
			++curr;
		}
	}
	fl.insert_after(pre, s2);
}

int main()
{
	forward_list<string> flstr = {"Baby", "is", "sleeping!"};
	print(flstr);
	insert(flstr, "is", "now");
	print(flstr);
	insert(flstr, "sleep", "Shut up!");
	print(flstr);
	insert(flstr, "Baby", "Dolphin");
	print(flstr);
	return 0;
}