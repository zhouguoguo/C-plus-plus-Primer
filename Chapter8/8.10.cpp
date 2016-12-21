#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;;

int main()
{
	ifstream ifs("infile");
	if (!ifs) {
		cout << "infile missing\n";
		return 1;
	}
	vector<string> vec;
	string line;
	while(getline(ifs, line)) {
		vec.push_back(line);
	}
	string word;
	istringstream istr;
	for (auto v : vec) {
		istr.str(v);
//		cout << istr.str() << endl;
		istr.clear();
		while (istr >> word) {
			cout << word << endl;
		}
	}
	return 0;
}