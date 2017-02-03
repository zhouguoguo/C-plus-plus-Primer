#include <iostream>
#include <set>

using namespace std;

class Sales_data {
private:
	string bookNo;
public:
	string isbn() const {return bookNo;}
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);

	multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore_1(compareIsbn);

	using F = bool (*)(const Sales_data&, const Sales_data&);
	multiset<Sales_data, F> bookstore_2(compareIsbn);
}