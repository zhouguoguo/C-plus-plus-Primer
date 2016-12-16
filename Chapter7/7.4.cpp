#include <iostream>

using namespace std;

struct Person {
	string getName() const {return name;}
	string getAddress() const {return address;}
	string name;
	string address;
};

int main()
{
	return 0;
}