#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ifstream ifs("infile");
	vector<string> vec;
	string str;
	if (ifs) {
		while (getline(ifs, str)) {
			vec.push_back(str);
		}
	}
	for (auto v : vec) {
		cout << v << endl;
	}

	return 0;
}