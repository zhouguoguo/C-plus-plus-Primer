#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
using namespace std;

void print_vec(const vector<int>& lst)
{
	for (auto i : lst){
		cout << i << " ";
	}
	cout << endl;
}

void print_list(const list<int>& lst)
{
	for (auto i : lst){
		cout << i << " ";
	}
	cout << endl;
}

void print_deque(const deque<int>& lst)
{
	for (auto i : lst){
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vec = {1,2,3,4,5,6,7,8,9};
	vector<int> iv;
	list<int> il;
	deque<int> id;
	copy(vec.begin(), vec.end(), inserter(il, il.begin()));
	copy(vec.begin(), vec.end(), back_inserter(iv));
	copy(vec.begin(), vec.end(), front_inserter(id));
	print_list(il);
	print_vec(iv);
	print_deque(id);
}