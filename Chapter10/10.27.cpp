#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

void print(const list<string>& lst)
{
	for (auto str : lst){
		cout << str << endl;
	}
}

int main()
{
	vector<string> vec = {"hush", "hush", "baby", "is", "sleeping"};
	list<string> lst;
	unique_copy(vec.begin(), vec.end(), inserter(lst, lst.begin()));
	print(lst);
}