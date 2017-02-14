#include <iostream>

using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) :
		ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& hp) : 
		i(hp.i), ps(new string(*(hp.ps))) {}
	HasPtr& operator=(const HasPtr&);

	~HasPtr() {cout << "destroyed\n";delete ps;}

	string get_ps_content() const {return *ps;}
	string* get_ps() const {return ps;}

private:
	string *ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	*ps = *(rhs.ps);
	i = rhs.i;
	cout << "copy assignment\n";
	return *this;
}

int main()
{
	HasPtr hp("Hi");
	cout << hp.get_ps() << endl;
	cout << hp.get_ps_content() << endl;
	HasPtr hp1 = hp;
	cout << hp1.get_ps() << endl;
	cout << hp1.get_ps_content() << endl;

	HasPtr hp2;
	hp2 = hp;
	cout << hp2.get_ps() << endl;
	cout << hp2.get_ps_content() << endl;
}