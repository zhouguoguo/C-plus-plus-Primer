#include <iostream>

using namespace std;

class HasPtr {
public:
	HasPtr(const string& s = string()) :
		ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr& hp) : 
		i(hp.i), ps(hp.ps), use(hp.use) {++*use;}
	HasPtr& operator=(const HasPtr&);

	~HasPtr() {
		cout << "destroyed\n";
		if (--*use == 0) {
			delete ps;
			delete use;
		}
	}

	string get_ps_content() const {return *ps;}
	string* get_ps() const {return ps;}

private:
	string *ps;
	int i;
	size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use;
	if (*use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
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