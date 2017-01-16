#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Sales_data {
public:
	Sales_data(string s) : bookNo(s)
	{}
	string isbn() const {return bookNo;}
private:
	string bookNo;
};

bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
	return s1.isbn() < s2.isbn();
}

void print(const vector<Sales_data>& vec)
{
	for (auto s : vec) {
		cout << s.isbn() << endl;
	}
	cout << endl;
}

int main()
{
	Sales_data a("Mickey");
	Sales_data b("Mouse");
	Sales_data c("Mouse1");
	Sales_data d("MM");
	Sales_data e("Apple");
	vector<Sales_data> vec;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	vec.push_back(d);
	vec.push_back(e);
	print(vec);
	sort(vec.begin(), vec.end(), [](const Sales_data& s1, const Sales_data& s2)
		 {return s1.isbn() < s2.isbn();});
	print(vec);
}