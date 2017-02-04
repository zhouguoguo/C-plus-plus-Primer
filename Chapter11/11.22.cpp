#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	map<string, vector<int>> maptt;
	const string name = "lanshizhou";
	vector<int> birthday = {2016, 5, 26};
	pair<map<string, vector<int>>::iterator, bool> ret = 
		maptt.insert({name, birthday});
	cout << maptt.size() << endl;
	cout << maptt[name].size() << endl;
}