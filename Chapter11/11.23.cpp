#include <map>
#include <vector>
#include <iostream>

using namespace std;

void print(const multimap<string, vector<string>>& children)
{
	for (auto c : children) {
		string fn = c.first;
		for (auto n : c.second) {
			cout << n << " " << fn << endl;
		}
	}
}

int main()
{
	multimap<string, vector<string>> children;
	children.insert({"Lan", {"Xiaogu", "Shizhou"}});
	children.insert({"Lan", {"Rongyi"}});
	cout << children.size() << endl;
	print(children);
}