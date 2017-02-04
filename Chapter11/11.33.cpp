#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void read_rule(map<string, string>& rule)
{
	ifstream ifs("rule");
	string old;
	while (ifs >> old) {
//		cout << old << " ";
		string new_str;
		getline(ifs, new_str);
		new_str = new_str.substr(1);
		rule.insert(make_pair(old, new_str));
//		cout << new_str << endl;
	}
}

string transform(string str, map<string, string>& rule)
{
//	cout << "Before:" << str << endl;
	string new_str;
	auto it = rule.find(str);
	if (it != rule.end()) {
		new_str = it->second;
	}
	else 
		new_str = str;
//	cout << "After:" << new_str << endl;
	return new_str;
}

void word_transform(map<string, string>& rule, ifstream& ifs)
{
	ofstream ofs("result");
	string line;
	int i = 1;

	while(getline(ifs, line))
	{
		istringstream istr(line);
		string str;
		bool first_word = true;
		while (istr >> str) {
			if (first_word == false) {
				ofs << " ";
			}
			else {
				first_word = false;
			}
	//		ofs << i << ":";
			ofs << transform(str, rule);
	//		++i;	
		}
		ofs << endl;
	}
}

int main()
{
	map<string, string> rule;
	read_rule(rule);
	ifstream input("text");
	word_transform(rule, input);
}