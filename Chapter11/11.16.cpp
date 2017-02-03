#include <map>
#include <utility>
#include <iostream>

using namespace std;

void replace_or_insert(map<string, int>& maptt, 
					   const string& str, 
					   int t)
{
	map<string, int>::iterator map_it = maptt.begin();
	while (map_it != maptt.end())
	{
		if (map_it->first == str) {
			map_it->second = t;
			break;
		}
		++map_it;
	}
	if (map_it == maptt.end())
	{
		maptt[str] = t;
	}
}

int main()
{
	map<string, int> maptt;
	replace_or_insert(maptt, "apple", 1);
	replace_or_insert(maptt, "applepen", 2);
	replace_or_insert(maptt, "apple", 4);
	
	for (auto m : maptt) {
		cout << m.first << " " << m.second << endl;
	}
}