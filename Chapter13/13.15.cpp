#include <iostream>
using namespace std;

static int index = 0;

class Numbered {
public:
	Numbered() : mysn(index) {++index; cout << "default constructor\n";}
	Numbered(int sn) : mysn(sn) {}
	Numbered(const Numbered& n) : mysn(index) {++index; cout << "copy constructor\n";}
	int get_sn() const {return mysn;};
private: 
	int mysn;
};

void f(Numbered s)
{
	cout << s.get_sn() << endl;
}

int main()
{
	Numbered a, b, c;
	f(a);
	f(b);
	f(c);
	Numbered a1, b1 = a1, c1 = b1;
	f(a1);
	f(b1);
	f(c1);
}