#include <memory>
#include <iostream>
using namespace std;

void process(shared_ptr<int> sp)
{
	cout << "inside: ";
	cout << *sp << endl;
	cout << sp.use_count() << endl;
}

int main()
{
	shared_ptr<int> p(new int(42));
	cout << p.use_count() << endl;
//	cout << *p << endl;
//	process(p);
//	process(shared_ptr<int>(p));
	int *q = p.get();
//	cout << q << endl;

	shared_ptr<int> temp(q); //temp计数1， q计数1，即使它们指向同一个对象
	cout << p.use_count() << endl;

	process(temp); // temp释放了对象，q计数仍然为1， 但是对象已被释放
//	cout << *p << endl;
	cout << p.use_count() << endl;
//	cout << q << endl;
	

	int* a = new int(5);
	process(shared_ptr<int>(a));  
	cout << *a << endl;

	/*
	test result:
	inside: 42
	-2144456920 --> memory is deleted
	inside: 5
	-2144456920 --> memory is deleted
	Aborted (core dumped)  --> 
	*/

	return 0;
}