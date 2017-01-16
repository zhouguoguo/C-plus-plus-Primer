#include <iostream>

using namespace std;

int main()
{
	int sz = 10;
	auto g = [sz] (int a) -> int {return a+sz;};
	cout <<  g(6);
	return 0;
}