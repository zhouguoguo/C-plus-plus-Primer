#include <iostream>
using namespace std;

static int i = 0;

class Employee {
public:
	Employee() : name(""), id(i) 
		{cout << "default constructor\n"; ++i;}
	Employee(string s) :name(s), id(i) 
		{cout << "constructor\n"; ++i;}
	Employee(const Employee& e) : 
		name(e.name), id(i) 
		{cout << "copy constructor\n"; ++i;}
	Employee& operator=(const Employee&);


	int get_id() const {return id;}
private:
	string name;
	int id;
};

Employee& Employee::operator=(const Employee& e)
{
	name = e.name;
	id = i;
	++i;
	cout << "copy assignment\n";
	return *this;
}

int main()
{
	Employee David;
	Employee Mary("Mary");
	cout << David.get_id() << " " << Mary.get_id() << endl;

	Employee One = David;
	cout << One.get_id() << endl;

	One = Mary;
	cout << One.get_id() << endl;
}