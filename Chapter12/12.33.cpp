#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <memory>

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


	shared_ptr<vector<string>> data;
	private:
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


using line_no = vector<string>::size_type;

class QueryResult;
class TextQuery {
public:
	TextQuery() {};
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
	void printmap(); // for test
private:
//	shared_ptr<vector<string>> file;
	StrBlob file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream& is)
{
	file.data = make_shared<vector<string>>();
	string str;
	while (getline(is, str)) {
		file.data->push_back(str);
		int n = file.data->size() - 1;
		istringstream istr(str);
		string word;
		while (istr >> word) {
			auto &lines = wm[word];
			if (!lines) {
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
		
	}
}

void TextQuery::printmap()
{
	for (auto p : wm) {
		cout << p.first << " ";
		auto sp = p.second;
		for (auto l : *sp) {
			cout << l << " ";
		}
		cout << endl;
	}
	cout << endl;
}

class QueryResult {
friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s,
				shared_ptr<set<line_no>> p,
				StrBlob f) 
				: sought(s), lines(p), file(f) {};
	set<line_no>::iterator begin() const {return lines->begin();}
	set<line_no>::iterator end() const {return lines->end();}
	shared_ptr<vector<string>>& get_file() {return file.data;}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	StrBlob file;
};

QueryResult TextQuery::query(const string& sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream& print(ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size()
	   << " time(s) " << endl;
	for (auto l : *qr.lines)
		os << "\t(line " << l + 1 << ") "
	       << *(qr.file.data->begin() + l) << endl;
	return os;
}


void runQueries(ifstream& infile)
{
	TextQuery tq(infile);
	tq.printmap();
	while (true) {
		cout << "enter word to look for, or q to quit:";
		string s;
		if (!(cin>>s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream infile("text");
	runQueries(infile);
}