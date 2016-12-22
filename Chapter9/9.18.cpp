#include <deque>
#include <list>
#include <iostream>

using namespace std;

void print(const deque<string>& sd)
{
	for (auto iter = sd.cbegin(); iter != sd.cend(); ++iter)
	{
		cout << *iter << endl;
	}
}

void print(const list<string>& sl)
{
	for (auto iter = sl.cbegin(); iter != sl.cend(); ++iter)
	{
		cout << *iter << endl;
	}
}

int main()
{
	list<string> strDeq;
	string str;
	while (cin >> str) {
		strDeq.push_back(str);
	}
	print(strDeq);
	strDeq.insert(strDeq.begin(), "123");
	print(strDeq);

	return 0;
}