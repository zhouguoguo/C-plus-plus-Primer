#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;

//	IntP p0(ix); //compile error
//	IntP p1(pi); //core dump
	IntP p2(pi2); // correct
//	IntP p3(&ix); //core dump
	IntP p4(new int(2048)); // correct
//	IntP p5(p2.get()); // core dump
}