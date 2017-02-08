#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <memory>

using namespace std;
using line_no = vector<string>::size_type;

class QueryResult;
class TextQuery {
public:
	TextQuery() {};
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
	void printmap(); // for test
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
	string str;
	while (getline(is, str)) {
		file->push_back(str);
		int n = file->size() - 1;
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
				shared_ptr<vector<string>> f) 
				: sought(s), lines(p), file(f) {};

private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
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
	       << *(qr.file->begin() + l) << endl;
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