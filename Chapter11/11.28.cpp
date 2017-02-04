#include <map>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int main()
{
	map<string, vector<int>> maptt = 
			{{"applepen", {1001, 1002}}, 
			 {"pineapplepen", {1001, 1005, 1110}}};
	map<string, vector<int>>::iterator it = maptt.find("pineapplepen");
	cout << it->second.size();
}