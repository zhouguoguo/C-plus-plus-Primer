#include <map>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Date {
public:
	Date() = default;
	Date(unsigned y, unsigned m, unsigned d) :
		year(y), month(m), day(d) {}

private:
	unsigned year;
	unsigned month;
	unsigned day;
};

add_a_family(map<string,vector<pair<string, Date>>>& families, const string& family_name)
{
	families[family_name].resize(0);
}

void add_a_child(map<string,vector<pair<string, Date>>>& families, 
				  const string& family_name,
				  const string& child_name,
				  const Date& birthday)
{
	families[family_name].push_back(make_pair(child_name, birthday));
}

int main()
{
	map<string,vector<pair<string, Date>>> families;
	string family_name = "Lan";
	string child_name = "Shizhou";
	Date birthday(2016, 5, 26);
	add_a_family(families, family_name);
	add_a_child(families, family_name, child_name, birthday);
	add_a_child(families, "Lan", "Xiaogu", birthday);
	cout << families.size() << endl << families["Lan"].size() << endl;
}