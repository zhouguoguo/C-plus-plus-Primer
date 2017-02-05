#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class StrBlob {
	typedef vector<string>::size_type size_type;
public:
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il) :
			data(make_shared<vector<string>>(il)) {}

	string& front();
	string& back();

	const string& front() const;
	const string& back() const;
	void pop_back();

	bool empty() {return data->empty();}
	size_type size() const {return data->size();}
	void push_back(string str) {data->push_back(str);}

private:
	shared_ptr<vector<string>> data;
	void check(size_type, const string&) const;
};

void StrBlob::check(size_type i, const string& msg) const
{
	if ( i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}

int main()
{
	StrBlob strblob({"apple", "pen", "applepen"});
	cout << strblob.front() << endl;
	cout << strblob.back() << endl;
	strblob.pop_back();
	cout << strblob.back() << endl;

	const StrBlob cstrblob({"pineapple", "pen", "pineapplepen"});
	cout << cstrblob.front() << endl;
	cout << cstrblob.back() << endl;

	StrBlob houxiaotun({"lan", "shi", "zhou"});
	cout << houxiaotun.front() << endl;
	cout << houxiaotun.back() << endl;

	vector<StrBlob> vec;
	vec.push_back(houxiaotun);
	vec.push_back({"lan", "xiao", "gu"});
}