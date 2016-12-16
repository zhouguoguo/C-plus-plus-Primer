#include <iostream>

using namespace std;

struct Person {
	Person() = default;
	Person(const string& n, const string a) : name(n), address(a){}
	Person(istream& is) {read(is, *this);}

	friend istream& read(istream&, Person&);

	string getName() const {return name;}
	string getAddress() const {return address;}
	string name;
	string address;
};

istream& read(istream& is, Person& p)
{
	is >> p.name >> p.address;
	return is;
}

ostream& print(ostream& os, const Person& p)
{
	os << "Name: " << p.name
	   << " Address: " << p.address;
}

int main()
{
	Person Shizhou("lanshizhou", "shanghai");
	
	print(cout, Shizhou);
	return 0;
}