#include <map>
#include <vector>
#include <iostream>

using namespace std;

add_a_family(map<string,vector<string>>& families, const string& family_name)
{
	families[family_name].resize(0);
}

void add_a_child(map<string,vector<string>>& families, 
				  const string& family_name,
				  const string& child_name)
{
	families[family_name].push_back(child_name);
}

int main()
{
	map<string,vector<string>> families;
	string family_name = "Lan";
	string child_name = "Shizhou";
	add_a_family(families, family_name);
	add_a_child(families, family_name, child_name);
	add_a_child(families, "Lan", "Xiaogu");
	cout << families.size() << endl << families["Lan"].size() << endl;
}