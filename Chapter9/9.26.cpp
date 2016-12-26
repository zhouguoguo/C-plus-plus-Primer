#include <iostream>
#include <vector>
#include <list>

using namespace std;

void print(const list<int>& il)
{
	for (auto iter = il.cbegin(); iter != il.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void print(const vector<int>& il)
{
	for (auto iter = il.cbegin(); iter != il.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void rmOdd(list<int>& lst)
{
	auto iter = lst.cbegin();
	while (iter != lst.cend()) {
		if (*iter % 2 == 1) {
			iter = lst.erase(iter);
		}
		else ++iter;
	}
}

void rmEven(vector<int>& vec)
{
	auto iter = vec.cbegin();
	while (iter != vec.cend()) {
		if (*iter % 2 == 0) {
			iter = vec.erase(iter);
		}
		else ++iter;
	}
}

int main()
{
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	vector<int> vint(ia, ia+11);
	list<int> lint(ia, ia+11);
	print(vint);
	print(lint);

	rmOdd(lint);
	rmEven(vint);

	print(vint);
	print(lint);
	return 0;
}