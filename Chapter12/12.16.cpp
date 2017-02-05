#include <iostream>
#include <memory>

using namespace std;

int main()
{
	unique_ptr<int> p(new int(1));
//	unique_ptr<int> q = p;
	unique_ptr<int> q1(p);
}