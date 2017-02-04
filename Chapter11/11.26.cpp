#include <map>
#include <iostream>

using namespace std;

int main()
{
//	map<string, int> maptt = {{"apple", 100}};
	map<string, int> maptt = {{"apple", 101}, {"apple1", 100}};
	int i = maptt["apple"];
	cout << i << endl;
}