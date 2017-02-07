#include <memory>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
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

	StrBlobPtr begin();
	StrBlobPtr end();

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

class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0)
				: wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();
	size_t get_index() {return curr;}
private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string& msg) const
{
	auto ret = wptr.lock();
	if (!ret) 
		throw runtime_error("unbound StrBlobPtr");
	if (sz >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	auto p = check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin() 
{
	return StrBlobPtr(*this);
}


StrBlobPtr StrBlob::end() 
{
	return StrBlobPtr(*this, data->size());
}

int main()
{
	ifstream ifs("strb");
	string line;
	StrBlob strobj;
	while (getline(ifs, line)) {
		strobj.push_back(line);
	}

	auto a = strobj.begin();
	while (a.get_index() != strobj.size()) {
		cout << a.deref() << endl;
		a.incr();
	}
}