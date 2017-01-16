#include <iostream>

using namespace std;

auto f = [] (int a, int b) -> int {return a+b;};

int main()
{
	cout << f(1, 3) << endl;
	return 0;
}