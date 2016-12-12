#include <iostream>

using std::cout;
using std::endl;

int factory(int val)
{
	if (val > 1) return factory(val - 1) * val;
	return 1;
}

int main()
{
	cout << factory(5) << endl;
	return 0;
}