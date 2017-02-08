#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;
using line_no = vector<string>::size_type;

void printmap(const map<string, set<line_no>>& wm)
{
	for (auto p : wm) {
		cout << p.first << " ";
		auto sp = p.second;
		for (auto l : sp) {
			cout << l << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void input(ifstream& ifs, vector<string>& file, map<string, set<line_no>>& wm)
{
	string str;
	while (getline(ifs, str)) {
		file.push_back(str);
		int n = file.size() - 1;
		istringstream istr(str);
		string word;
		while (istr >> word) {
			wm[word].insert(n);
		}
	}
}

void query(const string& sought, 
	       const vector<string>& file, 
	       const map<string, set<line_no>>& wm)
{
	auto it = wm.find(sought);
	if (it != wm.end())
	{
		cout << sought << " accurs " << it->second.size()
		     << " time(s)" << endl;
		for (auto i : it->second) {
			cout << "\t line(" << i + 1 << "): "
			     << file[i] << endl;
		}
	}
	else 
		cout << sought << " does not exit" << endl;
}

int main()
{
	ifstream ifs("text");
	vector<string> file;
	map<string, set<line_no>> wm;
	input(ifs, file, wm);
	printmap(wm);
	string sought;
	do{
		cout << "enter word to look for or q to exit:";
		if (!(cin>>sought) || sought == "q") break;
		query(sought, file, wm);
	}
	while(true);
}