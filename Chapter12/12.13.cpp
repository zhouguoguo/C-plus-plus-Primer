#include <iostream>
#include <memory>

using namespace std;

int main()
{
	auto sp = make_shared<int>(11);
	auto p = sp.get();
//	delete p; // will cause Aborted (core dumped)
			  // error when recycling sp, the memory has been deleted.
}