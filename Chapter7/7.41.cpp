#include <iostream>

using namespace std;

class Sales_data {
	friend void read(istream&, Sales_data&);
public:
	Sales_data(string s, unsigned u, double r) :
		bookNo(s), units_sold(u), revenue(r) {
			cout << "3 params constructor!\n";
	}

	Sales_data() : Sales_data("", 0, 0.0) {
		cout<<"default constructor!\n";
	}

	Sales_data(string s) : Sales_data(s, 0, 0.0) {
		cout << "1 params (string) constructor!\n";
	}
	Sales_data(istream& is) : Sales_data() {
		cout << "1 params (istream&) constructor!\n";
		read(is, *this);
	}
	void print_bookNo() {cout << bookNo;}
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

void read(istream& is, Sales_data& data) {
	double price = 0.0;
	is >> data.bookNo
		>> data.units_sold
		>> price;
	data.revenue = price * data.units_sold;
}

int main()
{
	Sales_data s1("book1", 1, 59.9);
	Sales_data s2;
	Sales_data s3("book3");
	Sales_data s4(cin);
	return 0;
}