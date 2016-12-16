#include <iostream>

using namespace std;

class Person {
	friend istream& read(istream&, Person&);
	friend ostream& print(ostream&, const Person&);
public:
	Person() = default;
	Person(const string& n, const string a) : name(n), address(a){}
	Person(istream& is) {read(is, *this);}

	string getName() const {return name;}
	string getAddress() const {return address;}

private:
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