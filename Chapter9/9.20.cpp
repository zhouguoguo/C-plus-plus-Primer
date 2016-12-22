#include <deque>
#include <list>
#include <iostream>

using namespace std;

void print(const deque<int>& id)
{
	for (auto iter = id.cbegin(); iter != id.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}


void print(const list<int>& il)
{
	for (auto iter = il.cbegin(); iter != il.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}
int main()
{
	list<int> itlst{0,1,2,3,4,5,6,7,8,9,10};
	print(itlst);

	deque<int> iteven, itodd;

	for (auto iter = itlst.cbegin(); iter != itlst.cend(); ++iter)
	{
		if (*iter % 2 == 0) {
			iteven.push_back(*iter);
		}
		else {
			itodd.push_back(*iter);
		}
	}
	print(iteven);
	print(itodd);
	return 0;
}