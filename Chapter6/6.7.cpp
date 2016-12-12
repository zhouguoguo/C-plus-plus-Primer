#include <iostream>
#include "Chapter6.h"

using namespace std;

unsigned int call_func()
{
	static unsigned cnt = -1;
	return ++cnt;
}

int main()
{
	for (int i = 0; i < 10; ++i) {
		cout << call_func() << endl;
	}
	return 0;
}