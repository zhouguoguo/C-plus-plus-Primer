#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_size(const string& str, const string& obj)
{
	return str.size() >= obj.size();
}

int main()
{
	vector<string> vec = {"Hi", "Hello", "A", "Timestogo" ,"Timestogooo", "Ti"};
	string str = "TimesToGo";
	auto it = find_if(vec.begin(), vec.end(), 
					  bind(check_size, _1, str));
	cout << *it << endl;
}