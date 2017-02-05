#include <memory>
#include <iostream>
using namespace std;

void process(shared_ptr<int> sp)
{
	cout << "inside: ";
	cout << *sp << endl;
}

int main()
{
	shared_ptr<int> p(new int(42));
//	process(p);
//	process(shared_ptr<int>(p));
	int *q = p.get();
	process(shared_ptr<int>(q)); // cause Aborted (core dumped)
	cout << *q << endl;

	int* a = new int(5);
	process(shared_ptr<int>(a));  
	cout << *a << endl;

	/*
	test result:
	inside: 42
	-2144456920 --> memory is deleted
	inside: 5
	-2144456920 --> memory is deleted
	Aborted (core dumped)  --> why?
	*/

	return 0;
}