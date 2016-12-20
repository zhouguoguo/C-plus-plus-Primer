#include <iostream>

using namespace std;

class Debug {
public:
	constexpr Debug(bool b) : hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) :
							  hw(h), io(i), other(o) {}
	constexpr bool any() {return hw || io || other;}
	void set_io(bool i) {io = i;}
	void set_hw(bool h) {hw = h;}
	void set_other(bool o) {other = o;}
private:
	bool hw;
	bool io;
	bool other;
};

int main()
{
	constexpr Debug io_sub(false, true, true);
	if (io_sub.any())
		cerr << "print appropriate error messages" << endl;
	constexpr Debug prod(false);
	if (prod.any())
		cerr << "print an error message" <<endl;
	return 0;
}