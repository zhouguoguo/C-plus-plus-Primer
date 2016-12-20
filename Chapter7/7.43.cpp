#include <iostream>
#include <vector>
using namespace std;

class NoDefault {
public:
	NoDefault(int i) {data = i;}
//	NoDefault() = default;
private:
	int data;
};

class C {
public:
	C() : nd(0) {}
private:
	NoDefault nd;
};

int main()
{
	C c;
//	vector<NoDefault> vec(10);
	vector<C> vec(10);
	return 0;
}