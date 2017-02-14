#include <iostream>
using namespace std;

class Sales_data {
public:
	Sales_data() {};
	~Sales_data() {cout << "destroyed\n";};

	string isbn() const {return bookNo;}
private:
	string bookNo;
};

bool fcn(const Sales_data *trans, Sales_data accum)
{
	Sales_data item1(*trans), item2(accum);
	return item1.isbn() != item2.isbn();
}

int main()
{
	Sales_data *trans = new Sales_data;
	Sales_data accum;
	fcn(trans, accum);
}