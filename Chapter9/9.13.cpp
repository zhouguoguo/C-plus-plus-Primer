#include <vector>
#include <list>
#include <iostream>
using namespace std;

void print(const vector<double>& vec)
{
	for (auto v : vec) {
		cout << v << " ";
	}
	cout << endl;
}

void print(const vector<int>& vec)
{
	for (auto v : vec) {
		cout << v << " ";
	}
	cout << endl;
}

void print(const list<int>& vec)
{
	for (auto v : vec) {
		cout << v << " ";
	}
	cout << endl;
}

int main()
{
	list<int> lint(5,-2);
	print(lint);
	vector<double> vd(lint.begin(), lint.end());
	print(vd);

	vector<int> vint(10, -1);
	print(vint);
	vector<double> vd1(vint.begin(), vint.end());
	print(vd1);
	return 0;
}