#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr {
	friend bool compare(const HasPtr&, const HasPtr&);
	friend void swap(HasPtr &lhs, HasPtr& rhs);
public:
	HasPtr(const string& s = string(), int t=0) :
		ps(new string(s)), i(t) {}
	HasPtr(const HasPtr& hp) : 
		i(hp.i), ps(new string(*(hp.ps))) {}
	~HasPtr() {delete ps;}

	HasPtr& operator=(HasPtr hp)
	{
		swap(*this, hp);
		return *this;
	}
	bool operator<(const HasPtr& hp);

	string get_ps_content() const {return *ps;}
	string* get_ps() const {return ps;}

private:
	string *ps;
	int i;
};

void swap(HasPtr &lhs, HasPtr& rhs)
{
	std::swap(lhs.ps, rhs.ps);
	std::swap(lhs.i, rhs.i);
	cout << "swap\n";
}

bool compare(const HasPtr& hp1,const HasPtr& hp2)
{
	return hp1.i < hp2.i;
}

bool HasPtr::operator<(const HasPtr& hp)
{
	cout << "operator<" << endl;
	if (*ps < *(hp.ps)) return true;
	else return false;
}

void print(const vector<HasPtr>& vec)
{
	for (auto v : vec) {
		cout << v.get_ps_content() << endl;
	}
}

int main()
{
	HasPtr hpa("Lan",1);
	HasPtr hpb("Shi",2);
	HasPtr hpc("Zhou",3);
	HasPtr hpd("Liang",4);

	vector<HasPtr> vec;
	vec.push_back(hpa);
	vec.push_back(hpb);
	vec.push_back(hpc);
	vec.push_back(hpd);

	print(vec);
	sort(vec.begin(), vec.end(), compare);
	print(vec);
}