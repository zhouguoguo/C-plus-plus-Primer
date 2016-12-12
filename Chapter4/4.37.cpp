#include <iostream>

using namespace std;

int main()
{
	int i;
	double d;
	const string *ps;
	char c = 'x';
	char *pc = &c;
	void *pv;


	//pv = (void*)ps;
	pv = static_cast<void*>(const_cast<string*>(ps));

	//i = int(*pc);
	i = static_cast<int>(*pc);

	pv = static_cast<void*>(&d);

	pc = static_cast<char*>(pv);

	return 0;
}